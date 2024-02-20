# Assignment 1-1

## 问题描述

股票价格的下一次上涨

给定一个整数数组 `prices` ，表示连续几天的股票价格。返回一个数组 `answer` ，其中 `answer[i]` 是指对于第 `i` 天，股价下一次上涨是在几天后。如果在这之后股价都不会上涨，请在该位置用 `0` 来代替。

提示：

* `1 <= prices.length <= 10^5`
* `30 <= prices[i] <= 100`

## 测试用例

* Test Case 1:
  Description: Test the correctness of the algorithm
  Input: 73 74 75 71 69 72 76 73 '\n'
  Expected Output: [1,1,4,2,1,1,0,0]

* Test Case 2:
  Description: Test the correctness of the algorithm
  Input: 30 40 50 60 '\n'
  Expected Output: [1,1,1,0]

* Test Case 3:
  Description: Test the correctness of the algorithm
  Input: 100 '\n'
  Expected Output: [0]

* Test Case 4:
  Description: Test the handling of input data exceeding the upper limit
  Input: 101 '\n'
  Expected Output: Error

* Test Case 5:
  Description: Test the handling of input data exceeding the upper limit
  Input: 50 60 120 50 80 '\n'
  Expected Output: Error

* Test Case 6:
  Description: Test the handling of input data below the lower limit
  Input: 29 '\n'
  Expected Output: Error

* Test Case 7:
  Description: Test the handling of input data below the lower limit
  Input: 95 45 30 20 98 20 '\n'
  Expected Output: Error

* Test Case 8:
  Description: Test the handling of input data with unreasonable length
  Input: '\n'
  Expected Output: Error

* Test Case 9:
  Description: Test the handling of incorrect input data types
  Input: a bcd '\n'
  Expected Output: Error

* Test Case 10:
  Description: Test the handling of incorrect input data types
  Input: 50.5 '\n'
  Expected Output: Error

## 文档更新日期

2024年2月20日