/****************************************************************
 * Project Name:  Assignment_1_3
 * File Name:     assignment_1_3.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/27
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
    Type m_upperLimit = 0;
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
        m_upperLimit = upperLimit;
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
        /* Check if the prices is empty */
        if (prices.empty()) {
            return 0;
        }

        /* Initialize status variables for different states */
        Type statusNotHolding = 0, statusBuy = -prices[0], statusHold = -m_upperLimit - 1, statusSell = -m_upperLimit - 1, statusFreeze = -m_upperLimit - 1;
        Type tmp;

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
     * Input Parameters: const Type* prices
     *                   int length
     * Return Value:     maximum profit
     */
    Type maxProfit(const Type* prices, int length)
    {
        /* Check if the prices is empty */
        if (length <= 0) {
            return 0;
        }

        /* Initialize status variables for different states */
        Type statusNotHolding = 0, statusBuy = -prices[0], statusHold = -m_upperLimit - 1, statusSell = -m_upperLimit - 1, statusFreeze = -m_upperLimit - 1;
        Type tmp;

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
    cout << "Input:" << endl;
    cout << "(1 <= prices.length <= 5000, if exceeded, it will be truncated.)" << endl;
    cout << "(0 <= prices[i] <= 1000, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(0, 1000, 5000U)) {
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