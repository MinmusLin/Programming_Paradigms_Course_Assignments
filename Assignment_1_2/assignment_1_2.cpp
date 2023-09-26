/****************************************************************
 * Project Name:  Assignment_1_2
 * File Name:     assignment_1_2.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/27
 ****************************************************************/

/****************************************************************
 * Problem Description
 ****************************************************************/

// 买卖股票的最佳时机
//     给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的
// 价格。你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设
// 计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取的最大利润。如果
// 你不能获取任何利润，返回 0 。
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
     * Function Name:    maxProfit
     * Function:         Calculate maximum profit
     * Input Parameters: const std::vector<Type>& prices
     * Return Value:     maximum profit
     */
    Type maxProfit(const std::vector<Type>& prices)
    {
        if (prices.empty()) { // Check if the prices is empty
            return 0;
        }
        Type maxProfit = 0;
        Type minPrice = prices[0]; // Initialize the minimum price to the first element
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
     * Input Parameters: const Type* prices
     *                   int length
     * Return Value:     maximum profit
     */
    Type maxProfit(const Type* prices, int length)
    {
        if (length <= 0) { // Check if the prices is empty
            return 0;
        }
        Type maxProfit = 0;
        Type minPrice = prices[0]; // Initialize the minimum price to the first element
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
    cout << "Input:" << endl;
    cout << "(1 <= prices.length <= 10^5, if exceeded, it will be truncated.)" << endl;
    cout << "(0 <= prices[i] <= 10^4, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(0, 10000, 100000U)) {
        continue;
    }

    /* Output result */
    cout << "Output:" << endl;
    cout << "Maximum Profit: " << solution.maxProfit(solution.getVec()) << endl;

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