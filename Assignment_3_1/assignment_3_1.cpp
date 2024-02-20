/****************************************************************
 * Project Name:  Assignment_3_1
 * File Name:     assignment_3_1.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/10/14
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 存在重复元素Ⅰ
//     给你一个整数数组 nums 。如果任意一值在数组中出现至少两次，返回 true ；
// 如果数组中每个值仅出现一次，返回 false 。
// 提示：
//     1 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

/* Define Solution class */
template <typename Type>
class Solution {
private:
    std::vector<Type> vec;
public:
    /*
     * Function Name:    input
     * Function:         Input data
     * Input Parameters: Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     *                   unsigned int maxLength: the maximum length of input data, if exceeded, it will be truncated
     * Return Value:     true: input data is valid
     *                   false: input data is invalid
     */
    bool input(Type lowerLimit, Type upperLimit, unsigned int maxLength)
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
     * Function Name:    checkDuplicateElement
     * Function:         Check for duplicate elements
     * Input Parameters: void
     * Return Value:     true: any value appears at least twice in the array
     *                   false: each value in the array appears only once
     */
    bool checkDuplicateElement()
    {
        /* Sort the array */
        std::vector<Type> vecCopy = vec;
        sort(vecCopy.begin(), vecCopy.end());

        /* Check for duplicate elements */
        for (unsigned int count = 0; count < vecCopy.size() - 1; count++) {
            if (vecCopy[count] == vecCopy[count + 1]) {
                return true; // Found duplicate elements
            }
        }
        return false; // Not found duplicate elements
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

    /* Input data */
    cout << "Input:" << endl;
    cout << "(1 <= nums.length <= 10^5, if exceeded, it will be truncated.)" << endl;
    cout << "(-10^9 <= nums[i] <= 10^9, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(-1000000000, 1000000000, 100000U)) {
        continue;
    }

    /* Output result */
    cout << "Output:" << endl;
    cout << "Whether any value appears at least twice in the array: " << (solution.checkDuplicateElement() ? "true" : "false") << endl;

    /* Program ends */
    return 0;
}

/****************************************************************
 * Test Cases
 ****************************************************************/

// Test Case 1:
// Description: Test the correctness of the algorithm
// Input: 1 2 3 1 '\n'
// Expected Output: true

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 1 2 3 4 '\n'
// Expected Output: false

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 1 1 1 3 3 4 3 2 4 2 '\n'
// Expected Output: true

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 2147483647 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 1 2147483648 2 3 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: -2147483648 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data below the lower limit
// Input: 1 -2147483649 2 3 '\n'
// Expected Output: Error

// Test Case 8:
// Description: Test the handling of input data with unreasonable length
// Input: '\n'
// Expected Output: Error

// Test Case 9:
// Description: Test the handling of incorrect input data types
// Input: a bcd '\n'
// Expected Output: Error

// Test Case 10:
// Description: Test the handling of incorrect input data types
// Input: 1.5 '\n'
// Expected Output: Error