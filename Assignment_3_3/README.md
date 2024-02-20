# Assignment 3-3

## 问题描述

存在重复元素Ⅲ

给你一个整数数组 `nums` 和两个整数 `indexDiff` 和 `valueDiff` 。找出是否存在这样的两个下标 `(i, j)` ：

* `i != j`
* `abs(i - j) <= indexDiff`
* `abs(nums[i] - nums[j]) <= valueDiff`

如果存在，返回 `true` ；否则，返回 `false` 。

提示：

* `2 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* `1 <= indexDiff <= nums.length`
* `0 <= valueDiff <= 10^9`

## 测试用例

* Test Case 1:

  Description: Test the correctness of the algorithm

  Input: 1 2 3 1 '\n' 3 '\n' 0 '\n'

  Expected Output: true

* Test Case 2:

  Description: Test the correctness of the algorithm

  Input: 1 5 9 1 5 9 '\n' 2 '\n' 3 '\n'

  Expected Output: false

* Test Case 3:

  Description: Test the correctness of the algorithm

  Input: 1 2 3 1 2 3 '\n' 2 '\n' 2 '\n'

  Expected Output: true

* Test Case 4:

  Description: Test the handling of input data exceeding the upper limit

  Input: 2147483647 '\n'

  Expected Output: Error

* Test Case 5:

  Description: Test the handling of input data exceeding the upper limit

  Input: 1 2 3 '\n' 4 '\n'

  Expected Output: Error

* Test Case 6:

  Description: Test the handling of input data below the lower limit

  Input: -2147483648 '\n'

  Expected Output: Error

* Test Case 7:

  Description: Test the handling of input data below the lower limit

  Input: 1 2 3 '\n' 0 '\n'

  Expected Output: Error

* Test Case 8:

  Description: Test the handling of input data with unreasonable length

  Input: 1 '\n'

  Expected Output: Error

* Test Case 9:

  Description: Test the handling of incorrect input data types

  Input: 1.5 '\n'

  Expected Output: Error

* Test Case 10:

  Description: Test the handling of incorrect input data types
  
  Input: 1 2 3 '\n' a '\n'

  Expected Output: Error

## 文档更新日期

2024年2月20日