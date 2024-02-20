# Assignment 3-2

## 问题描述

存在重复元素Ⅱ

给你一个整数数组 `nums` 和一个整数 `k` ，判断数组中是否存在两个不同的索引 `i` 和 `j` ，使得 `nums[i] == nums[j]` ，并且 `abs(i - j) <= k` 。

提示：

* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* `0 <= k <= 10^5`

## 测试用例

* Test Case 1:

  Description: Test the correctness of the algorithm

  Input: 1 2 3 1 '\n' 3 '\n'

  Expected Output: true

* Test Case 2:

  Description: Test the correctness of the algorithm

  Input: 1 0 1 1 '\n' 1 '\n'

  Expected Output: true

* Test Case 3:

  Description: Test the correctness of the algorithm

  Input: 1 2 3 1 2 3 '\n' 2 '\n'

  Expected Output: false

* Test Case 4:

  Description: Test the handling of input data exceeding the upper limit

  Input: 2147483647 '\n'

  Expected Output: Error

* Test Case 5:

  Description: Test the handling of input data exceeding the upper limit

  Input: 1 2 3 '\n' 100001 '\n'

  Expected Output: Error

* Test Case 6:

  Description: Test the handling of input data below the lower limit

  Input: -2147483648 '\n'

  Expected Output: Error

* Test Case 7:

  Description: Test the handling of input data below the lower limit

  Input: 1 2 3 '\n' -1 '\n'

  Expected Output: Error

* Test Case 8:

  Description: Test the handling of input data with unreasonable length

  Input: '\n'

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