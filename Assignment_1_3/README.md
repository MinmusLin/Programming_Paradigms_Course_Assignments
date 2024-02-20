# Assignment 1-3

## 问题描述

买卖股票的最佳时机含冷冻期

给定一个整数数组 `prices` ，其中第 `prices[i]` 表示第 `i` 天的股票价格。设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）。卖出股票后，你无法在第二天买入股票（即冷冻期为1天）。

注意：

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

提示：

* `1 <= prices.length <= 5000`
* `0 <= prices[i] <= 1000`

## 测试用例

* Test Case 1:

  Description: Test the correctness of the algorithm

  Input: 1 2 3 0 2 '\n'

  Expected Output: 3

* Test Case 2:

  Description: Test the correctness of the algorithm

  Input: 3 3 '\n'

  Expected Output: 0

* Test Case 3:

  Description: Test the correctness of the algorithm

  Input: 1 '\n'

  Expected Output: 0

* Test Case 4:

  Description: Test the handling of input data exceeding the upper limit

  Input: 1001 '\n'

  Expected Output: Error

* Test Case 5:

  Description: Test the handling of input data exceeding the upper limit

  Input: 50 60 1200 50 80 '\n'

  Expected Output: Error

* Test Case 6:

  Description: Test the handling of input data below the lower limit

  Input: -1 '\n'

  Expected Output: Error

* Test Case 7:

  Description: Test the handling of input data below the lower limit

  Input: 95 45 30 -20 98 20 '\n'

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