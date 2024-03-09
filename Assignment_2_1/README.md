# Assignment 2-1

## 问题描述

电影播放时间

某影院为观众提供了一系列电影的播放时间安排 `intervals` ，每部电影的播放时间由其开始和结束的时间标记，即 `intervals[i] = [starti, endi]` 。请你判断一个人是否能够看完这里面的全部电影，不错过任何一部。

提示：

* `0 <= intervals.length <= 10^4`
* `intervals[i].length == 2`
* `0 <= starti < endi <= 10^6`

## 测试用例

* Test Case 1:

  Description: Test the correctness of the algorithm

  Input: 0 30 5 10 15 20 '\n'

  Expected Output: false

* Test Case 2:

  Description: Test the correctness of the algorithm

  Input: 7 10 2 4 '\n'

  Expected Output: true

* Test Case 3:

  Description: Test the correctness of the algorithm

  Input: 1 3 2 6 8 10 15 18 '\n'

  Expected Output: false

* Test Case 4:

  Description: Test the correctness of the algorithm

  Input: 1 4 4 5 '\n'

  Expected Output: true

* Test Case 5:

  Description: Test the handling of input data exceeding the upper limit

  Input: 0 10 1000000 1000001 '\n'

  Expected Output: Error

* Test Case 6:

  Description: Test the handling of input data below the lower limit

  Input: 22 24 -1 36 '\n'

  Expected Output: Error

* Test Case 7:

  Description: Test the handling of input data with unreasonable time

  Input: 100 200 300 200 '\n'

  Expected Output: Error

* Test Case 8:

  Description: Test the handling of input data with unreasonable length

  Input: 10 '\n'

  Expected Output: Error

* Test Case 9:

  Description: Test the handling of input data with unreasonable length

  Input: 0 10 12 22 24 '\n'

  Expected Output: true

* Test Case 10:

  Description: Test the handling of incorrect input data types

  Input: 5.5 10 a bcd '\n'
  
  Expected Output: Error

## 项目构建命令

```
mkdir build
cd build
cmake ..
```

## 编译运行环境

* 本项目适用于x86和x64架构

## 文档更新日期

2024年3月10日