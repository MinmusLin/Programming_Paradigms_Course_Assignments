/****************************************************************
 * Project Name:  Assignment_1_1
 * File Name:     assignment_1_1.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/10/11
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

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
     * Function Name:    nextIncrease
     * Function:         Calculate next increase
     * Input Parameters: const std::vector<Type>& prices
     * Return Value:     increase vector
     */
    std::vector<int> nextIncrease(const std::vector<Type>& prices)
    {
        std::vector<int> increaseVector(prices.size(), 0); // The increase vector with zeros
        std::stack<int> indices; // Stack to store indices
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
        std::stack<int> indices; // Stack to store indices
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
    cout << "(30 <= prices[i] <= 100, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(30, 100, 100000U)) {
        continue;
    }

    /* Output result */
    cout << "Output:" << endl;
    cout << "Increase Vector: " << solution.nextIncrease(solution.getVec()) << endl;

    // Notes:
    //     To enhance the versatility and extensibility of the code, you can also call the
    //     std::vector<int> Solution::nextIncrease(const T* prices, int length) function to
    //     handle cases where the parameter is an array, the input parameters are the array's
    //     starting address and its length.

    /* Program ends */
    return 0;
}