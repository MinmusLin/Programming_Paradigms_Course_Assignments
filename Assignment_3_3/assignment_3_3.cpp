/****************************************************************
 * Project Name:  Assignment_3_3
 * File Name:     assignment_3_3.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/10/14
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 存在重复元素Ⅲ
//     给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。
// 找出是否存在这样的两个下标 (i, j) ：
//     i != j
//     abs(i - j) <= indexDiff
//     abs(nums[i] - nums[j]) <= valueDiff
// 如果存在，返回 true ；否则，返回 false 。
// 提示：
//     2 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9
//     1 <= indexDiff <= nums.length
//     0 <= valueDiff <= 10^9

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

/* Define Solution class */
template <typename Type>
class Solution {
private:
    /* Define private data members */
    std::vector<Type> vec;
    Type m_indexDiff = 0;
    Type m_valueDiff = 0;

    /*
     * Function Name:    inputVariable
     * Function:         Input data
     * Input Parameters: Type& input: input variable
     *                   Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     * Return Value:     void
     */
    void inputVariable(Type& input, Type lowerLimit, Type upperLimit)
    {
        while (true) {
            cin >> input;
            if (cin.good()) {
                if (input >= lowerLimit && input <= upperLimit) {
                    return;
                }
                else {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cerr << "Error: Input data is not within the valid range, please check input data and try again." << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cerr << "Error: Input data is invalid, please check data type and try again." << endl;
            }
        }
    }

public:
    /*
     * Function Name:    getVecLength
     * Function:         Get private vector variable's length
     * Input Parameters: void
     * Return Value:     private vector variable's length
     */
    const size_t getVecLength(void) const
    {
        return vec.size();
    }

    /*
     * Function Name:    input
     * Function:         Input data
     * Input Parameters: Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     *                   unsigned int minLength: the minimum length of input data, used to verify the validity of the input data
     *                   unsigned int maxLength: the maximum length of input data, if exceeded, it will be truncated
     * Return Value:     true: input data is valid
     *                   false: input data is invalid
     */
    bool input(Type lowerLimit, Type upperLimit, unsigned int minLength, unsigned int maxLength)
    {
        /* Read a line from standard input (cin) */
        std::string str;
        std::getline(cin, str);

        /* Create a string stream to parse the input */
        std::istringstream iss(str);
        Type num; // Variable to hold the parsed number

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
                vec.push_back(num);
            }

            /* Check for end of input or maximum input length */
            if (iss.eof() || vec.size() >= maxLength) {
                break;
            }
        }

        /* Check the length of vector */
        if (vec.size() < minLength) {
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
     * Function Name:    inputIndexDiff
     * Function:         Input variable indexDiff
     * Input Parameters: Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     * Return Value:     void
     */
    void inputIndexDiff(Type lowerLimit, Type upperLimit)
    {
        inputVariable(m_indexDiff, lowerLimit, upperLimit);
    }

    /*
     * Function Name:    inputValueDiff
     * Function:         Input variable valueDiff
     * Input Parameters: Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     * Return Value:     void
     */
    void inputValueDiff(Type lowerLimit, Type upperLimit)
    {
        inputVariable(m_valueDiff, lowerLimit, upperLimit);
    }

    /*
     * Function Name:    checkDuplicateElement
     * Function:         Check for duplicate elements
     * Input Parameters: void
     * Return Value:     true: existence of two indices meeting the criteria
     *                   false: absence of two indices meeting the criteria
     */
    bool checkDuplicateElement()
    {
        /* Iterate through the array */
        for (unsigned int i = 0; i < vec.size(); i++) {
            /* Iterate through elements within the index difference from the current element */
            for (unsigned int j = i + 1; j < i + m_indexDiff + 1 && j < vec.size(); j++) {
                /* Check if the absolute difference of elements is within the value difference */
                if (abs(vec[i] - vec[j]) <= m_valueDiff)
                    return true;
            }
        }
        return false;
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
    Solution<int> solution;

    /* Input integer array */
    cout << "Input integer array:" << endl;
    cout << "(2 <= nums.length <= 10^5, if exceeded, it will be truncated.)" << endl;
    cout << "(-10^9 <= nums[i] <= 10^9, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(-1000000000, 1000000000, 2U, 100000U)) {
        continue;
    }

    /* Input integer indexDiff */
    cout << "Input integer indexDiff:" << endl;
    cout << "(1 <= indexDiff <= nums.length, please input an integer and press Enter.)" << endl;
    solution.inputIndexDiff(1, static_cast<int>(solution.getVecLength()));

    /* Input integer valueDiff */
    cout << "Input integer valueDiff:" << endl;
    cout << "(0 <= valueDiff <= 10^9, please input an integer and press Enter.)" << endl;
    solution.inputValueDiff(0, 1000000000);

    /* Output result */
    cout << "Output:" << endl;
    cout << "Whether there exist two indices meeting the criteria: " << (solution.checkDuplicateElement() ? "true" : "false") << endl;

    /* Program ends */
    return 0;
}

/****************************************************************
 * Test Cases
 ****************************************************************/

// Test Case 1:
// Description: Test the correctness of the algorithm
// Input: 1 2 3 1 '\n' 3 '\n' 0 '\n'
// Expected Output: true

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 1 5 9 1 5 9 '\n' 2 '\n' 3 '\n'
// Expected Output: false

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 1 2 3 1 2 3 '\n' 2 '\n' 2 '\n'
// Expected Output: true

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 2147483647 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 1 2 3 '\n' 4 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: -2147483648 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data below the lower limit
// Input: 1 2 3 '\n' 0 '\n'
// Expected Output: Error

// Test Case 8:
// Description: Test the handling of input data with unreasonable length
// Input: 1 '\n'
// Expected Output: Error

// Test Case 9:
// Description: Test the handling of incorrect input data types
// Input: 1.5 '\n'
// Expected Output: Error

// Test Case 10:
// Description: Test the handling of incorrect input data types
// Input: 1 2 3 '\n' a '\n'
// Expected Output: Error