/****************************************************************
 * Project Name:  Assignment_1_1
 * File Name:     assignment_1_1.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/26
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 给定一个整数数组 prices ，表示连续几天的股票价格。返回一个数组 answer ，其中 answer[i] 是
// 指对于第 i 天，股价下一次上涨是在几天后。如果在这之后股价都不会上涨，请在该位置用 0 来代替。
// 提示：
//     1 <= prices.length <= 10^5
//     30 <= prices[i] <= 100

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <limits>

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
        std::cerr << "Vector is empty." << std::endl;
    }
    else {
        out << "[" << vectorVariable[0];
        for (unsigned int count = 1; count < vectorVariable.size(); count++)
            out << "," << vectorVariable[count];
        out << "]";
    }
    return out;
}

/* Define Solution class */
template <typename Type>
class Solution {
private:
    std::vector<Type> vec;
public:
    /*
     * Function Name:    getVec
     * Function:         Get private vector variable
     * Input Parameters: void
     * Return Value:     private vector variable
     */
    const std::vector<Type>& getVec(void) const
    {
        return vec;
    }

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
        std::getline(std::cin, str);

        /* Create a string stream to parse the input */
        std::istringstream iss(str);
        Type num; // Variable to hold the parsed number

        /* Loop to read and process each number from the input */
        while (true) {
            /* Read a number from the input stream */
            iss >> num;
            if (iss.fail()) { // Check if the read operation failed (invalid data type)
                std::cerr << "Error: Input data is invalid, please check data type and try again." << std::endl;
                iss.clear();
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                vec.clear();
                return false; // Return false to indicate invalid input
            }
            else if (num < lowerLimit || num > upperLimit) { // Check if the number is outside the valid range
                std::cerr << "Error: Input data is not within the valid range, please check input data and try again." << std::endl;
                vec.clear();
                return false; // Return false to indicate invalid input
            }
            else { // Valid input
                vec.push_back(num);
            } // Check for end of input or maximum input length
            if (iss.eof() || vec.size() >= maxLength) {
                break;
            }
        }

        /* Return true to indicate valid input */
        return true;
    }

    /*
     * Function Name:    nextIncrease
     * Function:         Calculate next increase
     * Input Parameters: const std::vector<Type>& prices
     * Return Value:     increase vector
     */
    std::vector<int> nextIncrease(const std::vector<Type>& prices)
    {
        std::vector<int> increaseVector(prices.size(), 0); // The increase vector with zeros
        std::stack<int> indices; //Stack to store indices
        for (unsigned int count = 0; count < prices.size(); count++) {
            /* If the stack is not empty and the current price is greater than the price at the top of the stack */
            while (!indices.empty() && prices[count] > prices[indices.top()]) {
                increaseVector[indices.top()] = count - indices.top();
                indices.pop();
            }

            /* Push the current index onto the stack */
            indices.push(count);
        }
        return increaseVector;
    }

    /*
     * Function Name:    nextIncrease
     * Function:         Calculate next increase
     * Input Parameters: const Type* prices
     *                   int length
     * Return Value:     increase vector
     */
    std::vector<int> nextIncrease(const Type* prices, int length)
    {
        std::vector<int> increaseVector(length, 0); // The increase vector with zeros
        std::stack<int> indices; //Stack to store indices
        for (int count = 0; count < length; count++) {
            /* If the stack is not empty and the current price is greater than the price at the top of the stack */
            while (!indices.empty() && prices[count] > prices[indices.top()]) {
                increaseVector[indices.top()] = count - indices.top();
                indices.pop();
            }

            /* Push the current index onto the stack */
            indices.push(count);
        }
        return increaseVector;
    }

    /* Friend function declaration */
    friend std::ostream& operator<<(std::ostream& out, const std::vector<Type>& vectorVariable);
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
    std::cout << "Input:" << std::endl;
    std::cout << "(1 <= prices.length <= 10^5, if exceeded, it will be truncated.)" << std::endl;
    std::cout << "(30 <= prices[i] <= 100, please separate the data with spaces and press Enter.)" << std::endl;
    while (!solution.input(30, 100, 100000U)) {
        continue;
    }

    /* Output result */
    std::cout << "Output:" << std::endl;
    std::cout << "Increase Vector: " << solution.nextIncrease(solution.getVec()) << std::endl;

    // Notes:
    //     To enhance the versatility and extensibility of the code, you can also call the
    //     std::vector<int> Solution::nextIncrease(const T* prices, int length) function to
    //     handle cases where the parameter is an array, the input parameters are the array's
    //     starting address and its length.

    /* Program ends */
    return 0;
}

/****************************************************************
 * Test Cases
 ****************************************************************/

// Test Case 1:
// Description: Test the correctness of the algorithm
// Input: 73 74 75 71 69 72 76 73 '\n'
// Expected Output: [1,1,4,2,1,1,0,0]

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 30 40 50 60 '\n'
// Expected Output: [1,1,1,0]

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 100 '\n'
// Expected Output: [0]

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 101 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 50 60 120 50 80 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: 29 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data below the lower limit
// Input: 95 45 30 20 98 20 '\n'
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
// Input: 50.5 '\n'
// Expected Output: Error