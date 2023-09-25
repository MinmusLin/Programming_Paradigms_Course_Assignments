/****************************************************************
 * Project Name:  Assignment_1_3
 * File Name:     assignment_1_3.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/25
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 给定⼀个整数数组 prices ，其中第 prices[i] 表示第 i 天的股票价格。
// 设计⼀个算法计算出最⼤利润。在满⾜以下约束条件下，你可以尽可能地完
// 成更多的交易（多次买卖⼀⽀股票）：
//     卖出股票后，你⽆法在第⼆天买⼊股票（即冷冻期为 1 天）。
// 注意：
//     你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 提示：
//     1 <= prices.length <= 5000
//     0 <= prices[i] <= 1000

/****************************************************************
 * Problem Solution
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>

/* Define Solution class */
template <typename T>
class Solution {
private:
    std::vector<T> vec;
    T m_upperLimit = 0;
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
        m_upperLimit = upperLimit;
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
        /* Check if the prices is empty */
        if (prices.empty()) {
            return 0;
        }

        /* Initialize status variables for different states */
        T statusNotHolding = 0, statusBuy = -prices[0], statusHold = -m_upperLimit - 1, statusSell = -m_upperLimit - 1, statusFreeze = -m_upperLimit - 1;
        T tmp;

        /* Iterate through the prices vector and calculate maximum profit based on different states */
        for (unsigned int count = 1; count < prices.size(); count++) {
            tmp = statusFreeze;
            statusFreeze = statusSell;
            statusSell = std::max(statusBuy, statusHold) + prices[count];
            statusHold = std::max(statusBuy, statusHold);
            statusBuy = std::max(tmp, statusNotHolding) - prices[count];
            statusNotHolding = std::max(tmp, statusNotHolding);
        }
        
        /* Return the maximum profit */
        return std::max(statusNotHolding, std::max(statusSell, statusFreeze));
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
        /* Check if the prices is empty */
        if (length <= 0) {
            return 0;
        }

        /* Initialize status variables for different states */
        T statusNotHolding = 0, statusBuy = -prices[0], statusHold = -m_upperLimit - 1, statusSell = -m_upperLimit - 1, statusFreeze = -m_upperLimit - 1;
        T tmp;

        /* Iterate through the prices vector and calculate maximum profit based on different states */
        for (int count = 1; count < length; count++) {
            tmp = statusFreeze;
            statusFreeze = statusSell;
            statusSell = std::max(statusBuy, statusHold) + prices[count];
            statusHold = std::max(statusBuy, statusHold);
            statusBuy = std::max(tmp, statusNotHolding) - prices[count];
            statusNotHolding = std::max(tmp, statusNotHolding);
        }

        /* Return the maximum profit */
        return std::max(statusNotHolding, std::max(statusSell, statusFreeze));
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
    std::cout << "(1 <= prices.length <= 5000, if exceeded, it will be truncated.)" << std::endl;
    std::cout << "(0 <= prices[i] <= 1000, please separate the data with spaces and press Enter.)" << std::endl;
    while (!solution.input(0, 1000, 5000U)) {
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
// Input: 1 2 3 0 2 '\n'
// Expected Output: 3

// Test Case 2:
// Description: Test the correctness of the algorithm
// Input: 3 3 '\n'
// Expected Output: 0

// Test Case 3:
// Description: Test the correctness of the algorithm
// Input: 1 '\n'
// Expected Output: 0

// Test Case 4:
// Description: Test the handling of input data exceeding the upper limit
// Input: 1001 '\n'
// Expected Output: Error

// Test Case 5:
// Description: Test the handling of input data exceeding the upper limit
// Input: 50 60 1200 50 80 '\n'
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