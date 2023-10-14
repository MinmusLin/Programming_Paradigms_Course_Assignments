/****************************************************************
 * Project Name:  Assignment_3_2
 * File Name:     assignment_3_2.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/10/14
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 存在重复元素Ⅱ
//     给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个不同的
// 索引 i 和 j ，使得 nums[i] == nums[j] ，并且 abs(i - j) <= k
// 提示：
//     1 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9
//     0 <= k <= 10^5

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

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
    Type m_k = 0;

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
     * Function Name:    inputK
     * Function:         Input variable k
     * Input Parameters: Type lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   Type upperLimit: the upper limit of input data, used to verify the validity of the input data
     * Return Value:     void
     */
    void inputK(Type lowerLimit, Type upperLimit)
    {
        inputVariable(m_k, lowerLimit, upperLimit);
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
        for (unsigned int left = 0; left < vec.size(); left++) {
            /* Iterate through elements to the right of the current element */
            for (unsigned int right = left + 1; right < vec.size() && static_cast<int>(right - left) <= m_k; right++) {
                /* Check if the current and right elements are equal */
                if (vec[left] == vec[right]) {
                    return true;
                }
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
    cout << "(1 <= nums.length <= 10^5, if exceeded, it will be truncated.)" << endl;
    cout << "(-10^9 <= nums[i] <= 10^9, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(-1000000000, 1000000000, 100000U)) {
        continue;
    }

    /* Input integer k */
    cout << "Input integer k:" << endl;
    cout << "(0 <= k <= 10^5, please input an integer and press Enter.)" << endl;
    solution.inputK(0, 100000);

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
// Input: 1 2 3 1 '\n' 3 '\n'
// Expected Output: true

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 1 0 1 1 '\n' 1 '\n'
// Expected Output: true

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 1 2 3 1 2 3 '\n' 2 '\n'
// Expected Output: false

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 2147483647 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 1 2 3 '\n' 100001 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: -2147483648 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data below the lower limit
// Input: 1 2 3 '\n' -1 '\n'
// Expected Output: Error

// Test Case 8:
// Description: Test the handling of input data with unreasonable length
// Input: '\n'
// Expected Output: Error

// Test Case 9:
// Description: Test the handling of incorrect input data types
// Input: 1.5 '\n'
// Expected Output: Error

// Test Case 10:
// Description: Test the handling of incorrect input data types
// Input: 1 2 3 '\n' a '\n'
// Expected Output: Error