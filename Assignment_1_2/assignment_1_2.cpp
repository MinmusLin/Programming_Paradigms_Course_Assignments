/****************************************************************
 * Project Name:  Assignment_1_2
 * File Name:     assignment_1_2.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/26
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个
// 算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果你不能
// 获取任何利润，返回 0 。
// 提示：
//     1 <= prices.length <= 10^5
//     0 <= prices[i] <= 10^4

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

/* Define Solution class */
template <typename T>
class Solution {
private:
    std::vector<T> vec;
public:
    /*
     * Function Name:    getVec
     * Function:         Get private vector variable
     * Input Parameters: void
     * Return Value:     private vector variable
     */
    const std::vector<T>& getVec() const
    {
        return vec;
    }

    /*
     * Function Name:    input
     * Function:         Input data
     * Input Parameters: T lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   T upperLimit: the upper limit of input data, used to verify the validity of the input data
     *                   unsigned int maxLength: the maximum length of input data, if exceeded, it will be truncated
     * Return Value:     true: input data is valid
     *                   false: input data is invalid
     */
    bool input(T lowerLimit, T upperLimit, unsigned int maxLength)
    {
        /* Read a line from standard input (cin) */
        std::string str;
        std::getline(std::cin, str);

        /* Create a string stream to parse the input */
        std::istringstream iss(str);
        T num; // Variable to hold the parsed number

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
     * Function Name:    maxProfit
     * Function:         Calculate maximum profit
     * Input Parameters: const std::vector<T>& prices
     * Return Value:     maximum profit
     */
    T maxProfit(const std::vector<T>& prices)
    {
        if (prices.empty()) { // Check if the prices is empty
            return 0;
        }
        T maxProfit = 0;
        T minPrice = prices[0]; // Initialize the minimum price to the first element
        for (unsigned int count = 1; count < prices.size(); count++) {
            /* Update the minimum price if we find a smaller value */
            minPrice = std::min(minPrice, prices[count]);

            /* Update the maximum profit if we find a higher profit */
            maxProfit = std::max(maxProfit, prices[count] - minPrice);
        }
        return maxProfit; // Return the maximum profit
    }

    /*
     * Function Name:    maxProfit
     * Function:         Calculate maximum profit
     * Input Parameters: const T* prices
     *                   int length
     * Return Value:     maximum profit
     */
    T maxProfit(const T* prices, int length)
    {
        if (length <= 0) { // Check if the prices is empty
            return 0;
        }
        T maxProfit = 0;
        T minPrice = prices[0]; // Initialize the minimum price to the first element
        for (int count = 1; count < length; count++) {
            /* Update the minimum price if we find a smaller value */
            minPrice = std::min(minPrice, prices[count]);

            /* Update the maximum profit if we find a higher profit */
            maxProfit = std::max(maxProfit, prices[count] - minPrice);
        }
        return maxProfit; // Return the maximum profit
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
    std::cout << "Input:" << std::endl;
    std::cout << "(1 <= prices.length <= 10^5, if exceeded, it will be truncated.)" << std::endl;
    std::cout << "(0 <= prices[i] <= 10^4, please separate the data with spaces and press Enter.)" << std::endl;
    while (!solution.input(0, 10000, 100000U)) {
        continue;
    }

    /* Output result */
    std::cout << "Output:" << std::endl;
    std::cout << "Maximum Profit: " << solution.maxProfit(solution.getVec()) << std::endl;

    // Notes:
    //     To enhance the versatility and extensibility of the code, you can also call the
    //     T Solution::maxProfit(const T* prices, int length) function to handle cases
    //     where the parameter is an array, the input parameters are the array's starting
    //     address and its length.

    /* Program ends */
    return 0;
}

/****************************************************************
 * Test Cases
 ****************************************************************/

// Test Case 1:
// Description: Test the correctness of the algorithm
// Input: 7 1 5 3 6 4 '\n'
// Expected Output: 5

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 7 6 4 3 1 '\n'
// Expected Output: 0

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 0 '\n'
// Expected Output: 0

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 10001 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 50 60 12000 50 80 '\n'
// Expected Output: Error

// Test Case 6:
// Description: Test the handling of input data below the lower limit
// Input: -1 '\n'
// Expected Output: Error

// Test Case 7:
// Description: Test the handling of input data below the lower limit
// Input: 95 45 30 -20 98 20 '\n'
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