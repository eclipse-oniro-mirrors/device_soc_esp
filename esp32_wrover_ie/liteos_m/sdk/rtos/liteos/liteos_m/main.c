/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdarg.h>
#include <stdio.h>
#include "task_demo.h"
#include "los_task.h"
#include "los_interrupt.h"
#include "hal_watchdog.h"
#include "soc.h"
#include "fs_init.h"

VOID BssClean(VOID)
{
    CHAR *p = &_sbss;
    for (INT32 i = 0; i < &_ebss - &_sbss; i++){
        *(p + i) = 0;
    }
}

INT32 main(VOID)
{
    UINT32 ret;

    ret = LosAppInit();
    if (ret != LOS_OK) {
        printf("LosAppInit failed! ERROR: 0x%x\n", ret);
    }
    return ret;
}

VOID MainThreadCreate(VOID)
{
    UINT32 ret;
    UINT32 taskID;
    TSK_INIT_PARAM_S stTask = {0};

    stTask.pfnTaskEntry = (TSK_ENTRY_FUNC)main;
    stTask.uwStackSize = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    stTask.pcName = "main";
    stTask.usTaskPrio = 2;
    ret = LOS_TaskCreate(&taskID, &stTask);
    if (ret != LOS_OK) {
        printf("Task1 create failed\n");
    }
}

void board_main(void)
{
    UINT32 ret;
    BssClean();
    WdtDisable();

    __asm__ __volatile__("mov sp, %0" : : "r"(&__init_stack_e));
#ifdef __FPU_PRESENT
    __asm__ __volatile__("wsr %0, CPENABLE;rsync" : : "r"(1));
#endif
    ret = LOS_KernelInit();
    if (ret != LOS_OK) {
        printf("Liteos kernel init failed! ERROR: 0x%x\n", ret);
    }
    FileSystemInit();
    
    if (ret == LOS_OK) {
        MainThreadCreate();
        (VOID)LOS_Start();
    }
}
