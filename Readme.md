# 2048控制台版

## 概述

该程序为控制台版的2048小游戏

## 开发环境

- Ubuntu20.04（wsl）

- cmake version 3.16.3

- g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

## 运行

``` bash
mkdir build && cd build && cmake .. && make	#编译
./2048 #正常运行
./2048 -t #测试运行
```

或者

``` bash
g++ *.cpp *.h -o 2048 #编译
./2048 #正常运行
。/2048 -t #测试运行
```

