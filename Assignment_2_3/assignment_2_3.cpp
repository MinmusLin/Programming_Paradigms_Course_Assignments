/****************************************************************
 * Project Name:  Assignment_2_3
 * File Name:     assignment_2_3.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/27
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 电影节目合并
//     影院为观众提供了一系列电影的播放时间安排 intervals ，其中每部电影的播放时间由
// 其开始和结束的时间标记，即 intervals[i] = [starti, endi] 。由于部分电影有重叠的
// 播放时间，影院决定合并这些时间，以提供一个新的播放时间表。请你合并所有重叠的播放时
// 间，并返回一个不重叠的播放时间数组，该数组需恰好覆盖输入中的所有时间。
// 提示：
//     1 <= intervals.length <= 10^4
//     intervals[i].length == 2
//     0 <= starti <= endi <= 10^4

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

/* Define Interval structure */
typedef struct {
    int startTime;
    int endTime;
} Interval;

/*
 * Function Name:    operator<<
 * Function:         Overload operator <<
 * Input Parameters: std::ostream& out
 *                   const std::vector<Type>& vectorVariable
 * Return Value:     out
 */
template <typename Type>
std::ostream& operator<<(std::ostream& out, const std::vector<Type>& vectorVariable)
{
    /* Check if the vector is empty */
    if (vectorVariable.empty()) {
        cerr << "Vector is empty." << endl;
    }
    else {
        out << "[" << vectorVariable[0];
        for (unsigned int count = 1; count < vectorVariable.size(); count++)
            out << "," << vectorVariable[count];
        out << "]";
    }
    return out;
}

/*
 * Function Name:    operator<<
 * Function:         Overload operator <<
 * Input Parameters: std::ostream& out
 *                   const Interval& interval
 * Return Value:     out
 */
std::ostream& operator<<(std::ostream& out, const Interval& interval) {
    return (out << "[" << interval.startTime << "," << interval.endTime << "]");
}

/* Define Solution class */
template <typename Type>
class Solution {
private:
    /* Define private data member */
    std::vector<Type> vec;

    /*
     * Function Name:    quickSort
     * Function:         Quick sort algorithm
     * Input Parameters: int left
     *                   int right
     * Return Value:     void
     */
    void quickSort(int left, int right)
    {
        /* If the left index is greater than or equal to the right index, return */
        if (left >= right) {
            return;
        }

        /* Choose the pivot element as the middle element's startTime in the vector */
        int pivot = vec[(left + right) / 2].startTime;
        int i = left;
        int j = right;

        /* Rearrange elements around the pivot */
        while (i <= j) {
            while (vec[i].startTime < pivot) {
                i++; //Find an element on the left side that is greater than or equal to the pivot
            }
            while (vec[j].startTime > pivot) {
                j--; //Find an element on the right side that is less than or equal to the pivot
            }
            if (i <= j) {
                std::swap(vec[i], vec[j]); //Swap elements if needed to ensure elements on the left are less than or equal to the pivot
                i++;
                j--;
            }
        }

        /* Recur for the subarrays on the left and right of the pivot */
        quickSort(left, j);
        quickSort(i, right);
    }

    /*
     * Function Name:    quickSort
     * Function:         Quick sort algorithm
     * Input Parameters: void
     * Return Value:     void
     */
    void quickSort(void)
    {
        quickSort(0, static_cast<int>(vec.size() - 1));
    }

public:
    /*
     * Function Name:    input
     * Function:         Input data
     * Input Parameters: int lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   int upperLimit: the upper limit of input data, used to verify the validity of the input data
     *                   unsigned int maxLength: the maximum length of input data, if exceeded, it will be truncated
     * Return Value:     true: input data is valid
     *                   false: input data is invalid
     */
    bool input(int lowerLimit, int upperLimit, unsigned int maxLength)
    {
        /* Read a line from standard input (cin) */
        std::string str;
        std::getline(cin, str);

        /* Create a string stream and a temporary input variable to parse the input */
        std::istringstream iss(str);
        Interval tmpInput{ -1,-1 };
        int num; // Variable to hold the parsed number

        /* Loop to read and process each number from the input */
        while (true) {
            /* Read a number from the input stream */
            iss >> num;
            if (iss.fail()) { // Check if the read operation failed (invalid data type)
                cerr << "Error: Input data is invalid, please check data type and try again." << endl;
                iss.clear();
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                vec.clear();
                return false; // Return false to indicate invalid input
            }
            else if (num < lowerLimit || num > upperLimit) { // Check if the number is outside the valid range
                cerr << "Error: Input data is not within the valid range, please check input data and try again." << endl;
                iss.clear();
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                vec.clear();
                return false; // Return false to indicate invalid input
            }
            else { // Valid input
                if (tmpInput.startTime < 0) {
                    tmpInput.startTime = num;
                }
                else {
                    tmpInput.endTime = num;
                    if (tmpInput.endTime < tmpInput.startTime) { // Check if the end time is earlier than the start time
                        cerr << "Error: The end time is earlier than the start time, please check input data and try again." << endl;
                        iss.clear();
                        iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        vec.clear();
                        return false; // Return false to indicate invalid input
                    }
                    vec.push_back(tmpInput);
                    tmpInput.startTime = -1;
                    tmpInput.endTime = -1;
                }
            }

            /* Check for end of input or maximum input length */
            if (iss.eof() || vec.size() >= maxLength) {
                break;
            }
        }

        /* Check the length of vector */
        if (vec.size() <= 0) {
            cerr << "Error: Input data is invalid, please check input data and try again." << endl;
            iss.clear();
            iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            vec.clear();
            return false; // Return false to indicate invalid input
        }

        /* Return true to indicate valid input */
        return true;
    }

    /*
     * Function Name:    mergeMovie
     * Function:         Merge movies
     * Input Parameters: void
     * Return Value:     merged vector
     */
    std::vector<Type> mergeMovie(void)
    {
        /* Initialize merged vector */
        std::vector<Type> mergedVector;

        /* Check if the vector is empty */
        if (vec.empty()) {
            cerr << "Vector is empty." << endl;
            return mergedVector;  // Return an empty vector
        }
        else {
            /* Sort intervals based on their end times using quick sort */
            quickSort();

            /* Initialize the first interval as the first interval in the sorted vector */
            Interval currentInterval = vec[0];

            /* Traverse the sorted intervals and merge overlapping intervals */
            for (unsigned int count = 1; count < vec.size(); count++) {
                if (currentInterval.endTime >= vec[count].startTime) {
                    /* If the intervals overlap, update the end time of the current interval */
                    currentInterval.endTime = std::max(currentInterval.endTime, vec[count].endTime);
                }
                else {
                    /* If there is no overlap, add the current interval to the merged vector */
                    mergedVector.push_back(currentInterval);
                    currentInterval = vec[count];
                }
            }

            /* Add the last merged interval */
            mergedVector.push_back(currentInterval);
            return mergedVector;
        }
    }
};

/*
 * Function Name:    main
 * Function:         Main function
 * Return Value:     0
 */
int main()
{
    /* Define solution object */
    Solution<Interval> solution;

    /* Input data */
    cout << "Input:" << endl;
    cout << "(1 <= intervals.length <= 10^4, if exceeded, it will be truncated.)" << endl;
    cout << "(intervals[i].length == 2, if exceeded, it will be truncated, if the last input data is a start time, it will be discarded.)" << endl;
    cout << "(0 <= starti <= endi <= 10^4, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(0, 10000, 10000U)) {
        continue;
    }

    /* Output result */
    cout << "Output:" << endl;
    cout << solution.mergeMovie() << endl;

    /* Program ends */
    return 0;
}

/****************************************************************
 * Test Cases
 ****************************************************************/

// Test Case 1:
// Description: Test the correctness of the algorithm
// Input: 0 30 5 10 15 20 '\n'
// Expected Output: [[0,30]]

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 7 10 2 4 '\n'
// Expected Output: [[2,4],[7,10]]

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 1 3 2 6 8 10 15 18 '\n'
// Expected Output: [[1,6],[8,10],[15,18]]

// Test Case 4:
// Description: Test the correctness of the algorithm
// Input: 1 4 4 5 '\n'
// Expected Output: [[1,5]]

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 0 10 10000 10001 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: 22 24 -1 36 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data with unreasonable time
// Input: 100 200 300 200 '\n'
// Expected Output: Error

// Test Case 8:
// Description: Test the handling of input data with unreasonable length
// Input: '\n'
// Expected Output: Error

// Test Case 9:
// Description: Test the handling of input data with unreasonable length
// Input: 0 10 12 22 24 '\n'
// Expected Output: [[0,10],[12,22]]

// Test Case 10:
// Description: Test the handling of incorrect input data types
// Input: 5.5 10 a bcd '\n'
// Expected Output: Error