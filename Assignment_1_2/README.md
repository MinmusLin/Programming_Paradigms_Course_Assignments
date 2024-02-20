# Assignment 1-2

## 问题描述

买卖股票的最佳时机

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

提示：

* `1 <= prices.length <= 10^5`
* `0 <= prices[i] <= 10^4`

## 测试用例

* Test Case 1:

  Description: Test the correctness of the algorithm

  Input: 7 1 5 3 6 4 '\n'

  Expected Output: 5

* Test Case 2:

  Description: Test the correctness of the algorithm

  Input: 7 6 4 3 1 '\n'

  Expected Output: 0

* Test Case 3:

  Description: Test the correctness of the algorithm

  Input: 0 '\n'

  Expected Output: 0

* Test Case 4:

  Description: Test the handling of input data exceeding the upper limit

  Input: 10001 '\n'

  Expected Output: Error

* Test Case 5:

  Description: Test the handling of input data exceeding the upper limit

  Input: 50 60 12000 50 80 '\n'

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