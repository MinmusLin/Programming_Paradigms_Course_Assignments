/****************************************************************
 * Project Name:  Assignment_3_1
 * File Name:     assignment_3_1.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/10/14
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