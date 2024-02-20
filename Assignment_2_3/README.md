# Assignment 2-3

## 问题描述

电影节目合并

影院为观众提供了一系列电影的播放时间安排 `intervals` ，其中每部电影的播放时间由其开始和结束的时间标记，即 `intervals[i] = [starti, endi]` 。由于部分电影有重叠的播放时间，影院决定合并这些时间，以提供一个新的播放时间表。请你合并所有重叠的播放时间，并返回一个不重叠的播放时间数组，该数组需恰好覆盖输入中的所有时间。

提示：

* `1 <= intervals.length <= 10^4`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 10^4`

## 测试用例

* Test Case 1:
  Description: Test the correctness of the algorithm
  Input: 0 30 5 10 15 20 '\n'
  Expected Output: [[0,30]]

* Test Case 2:
  Description: Test the correctness of the algorithm
  Input: 7 10 2 4 '\n'
  Expected Output: [[2,4],[7,10]]

* Test Case 3:
  Description: Test the correctness of the algorithm
  Input: 1 3 2 6 8 10 15 18 '\n'
  Expected Output: [[1,6],[8,10],[15,18]]

* Test Case 4:
  Description: Test the correctness of the algorithm
  Input: 1 4 4 5 '\n'
  Expected Output: [[1,5]]

* Test Case 5:
  Description: Test the handling of input data exceeding the upper limit
  Input: 0 10 10000 10001 '\n'
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
  Expected Output: [[0,10],[12,22]]

* Test Case 10:
  Description: Test the handling of incorrect input data types
  Input: 5.5 10 a bcd '\n'
  Expected Output: Error

## 文档更新日期

2024年2月20日