# Assignment 3-1

## 问题描述

存在重复元素Ⅰ

给你一个整数数组 `nums` 。如果任意一值在数组中出现至少两次，返回 `true` ；如果数组中每个值仅出现一次，返回 `false` 。

提示：

* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`

## 测试用例

* Test Case 1:
  Description: Test the correctness of the algorithm
  Input: 1 2 3 1 '\n'
  Expected Output: true

* Test Case 2:
  Description: Test the correctness of the algorithm
  Input: 1 2 3 4 '\n'
  Expected Output: false

* Test Case 3:
  Description: Test the correctness of the algorithm
  Input: 1 1 1 3 3 4 3 2 4 2 '\n'
  Expected Output: true

* Test Case 4:
  Description: Test the handling of input data exceeding the upper limit
  Input: 2147483647 '\n'
  Expected Output: Error

* Test Case 5:
  Description: Test the handling of input data exceeding the upper limit
  Input: 1 2147483648 2 3 '\n'
  Expected Output: Error

* Test Case 6:
  Description: Test the handling of input data below the lower limit
  Input: -2147483648 '\n'
  Expected Output: Error

* Test Case 7:
  Description: Test the handling of input data below the lower limit
  Input: 1 -2147483649 2 3 '\n'
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
  Input: 1.5 '\n'
  Expected Output: Error

## 文档更新日期

2024年2月20日