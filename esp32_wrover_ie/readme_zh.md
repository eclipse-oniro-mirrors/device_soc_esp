# ESP32_WROVER_IE

* [简介]()

* [目录]()

* [相关仓]()

# 简介

## 开发板概述

ESP32_DEVKITC_V4是乐鑫一款基于ESP32_WROVER_IE的小型开发板。单模组采用了ESP32系列的ESP32-D0WD-V3芯片（xtensa 32-bit LX6 双核处理器），CPU时钟频率可调节为80MHz到240MHz，配置4MB SPI flash和8MB SPI PSRAM，集成传统蓝牙、低功耗蓝牙和Wi-Fi。可以用于低功耗传感器网络和要求极高的任务，例如语音编码、音频流和 MP3 解码等。

# 目录

```
device/soc/espressif
├── esp_wrover_ie                               # 芯片SOC名称
│   ├── pack_tools                              # 打包烧录包工具目录
│   └── liteos_m                                # 基于liteos_m的bsp适配目录
│       ├── components                          # 组件服务层代码目录
│       │   ├── drivers                         # 驱动适配目录
│       │   ├── fs                              # 文件系统适配目录
│       │   └── utils                           # 组件系统适配目录
│       ├── hals                                # hals适配目录
│       └── sdk                                 # sdk模块的目录
│           ├── include                         # 编译头文件目录
│           ├── rtos                            # 系统启动代码目录
│           └── scripts                         # 链接脚本目录
├── Kconfig.liteos_m.defconfig.esp32            # esp32 kconfig 默认宏配置
├── Kconfig.liteos_m.series                     # esp32_wrover_ie系列soc配置宏
└── Kconfig.liteos_m.soc                        # soc kconfig配置宏
```     

# 说明

适配鸿蒙编译集成bsp的目录

# 相关仓

* [device/soc/espressif](https://gitee.com/openharmony-sig/device_soc_espressif)

