/****************************************************************
 * Project Name:  Assignment_2_2
 * File Name:     assignment_2_2.cpp
 * File Function: Problem solution
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/27
 ****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <queue>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

/* Define Interval structure */
typedef struct {
    int startTime;
    int endTime;
} Interval;

/* Define Solution class */
template <typename Type>
class Solution {
private:
    /* Define private data member */
    std::vector<Type> vec;

    /*
     * Function Name:    quickSort
     * Function:         Quick sort algorithm
     * Input Parameters: int left
     *                   int right
     * Return Value:     void
     */
    void quickSort(int left, int right)
    {
        /* If the left index is greater than or equal to the right index, return */
        if (left >= right) {
            return;
        }

        /* Choose the pivot element as the middle element's start time in the vector */
        int pivot = vec[(left + right) / 2].startTime;
        int i = left;
        int j = right;

        /* Rearrange elements around the pivot */
        while (i <= j) {
            while (vec[i].startTime < pivot) {
                i++; // Find an element on the left side that is greater than or equal to the pivot
            }
            while (vec[j].startTime > pivot) {
                j--; // Find an element on the right side that is less than or equal to the pivot
            }
            if (i <= j) {
                std::swap(vec[i], vec[j]); // Swap elements if needed to ensure elements on the left are less than or equal to the pivot
                i++;
                j--;
            }
        }

        /* Recur for the subarrays on the left and right of the pivot */
        quickSort(left, j);
        quickSort(i, right);
    }

    /*
     * Function Name:    quickSort
     * Function:         Quick sort algorithm
     * Input Parameters: void
     * Return Value:     void
     */
    void quickSort(void)
    {
        quickSort(0, static_cast<int>(vec.size() - 1));
    }

public:
    /*
     * Function Name:    input
     * Function:         Input data
     * Input Parameters: int lowerLimit: the lower limit of input data, used to verify the validity of the input data
     *                   int upperLimit: the upper limit of input data, used to verify the validity of the input data
     *                   unsigned int maxLength: the maximum length of input data, if exceeded, it will be truncated
     * Return Value:     true: input data is valid
     *                   false: input data is invalid
     */
    bool input(int lowerLimit, int upperLimit, unsigned int maxLength)
    {
        /* Read a line from standard input (cin) */
        std::string str;
        std::getline(cin, str);

        /* Create a string stream and a temporary input variable to parse the input */
        std::istringstream iss(str);
        Interval tmpInput{ -1,-1 };
        int num; // Variable to hold the parsed number

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
                if (tmpInput.startTime < 0) {
                    tmpInput.startTime = num;
                }
                else {
                    tmpInput.endTime = num;
                    if (tmpInput.endTime <= tmpInput.startTime) { // Check if the end time is earlier than the start time
                        cerr << "Error: The end time is earlier than the start time, please check input data and try again." << endl;
                        iss.clear();
                        iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        vec.clear();
                        return false; // Return false to indicate invalid input
                    }
                    vec.push_back(tmpInput);
                    tmpInput.startTime = -1;
                    tmpInput.endTime = -1;
                }
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
     * Function Name:    minRoomNum
     * Function:         Calculate minimum number of screening rooms
     * Input Parameters: void
     * Return Value:     minimum number of screening rooms
     */
    int minRoomNum(void)
    {
        /* Check if the vector is empty */
        if (vec.empty()) {
            cerr << "Vector is empty." << endl;
            return 0;
        }
        else {
            /* Sort the intervals by their start times */
            quickSort();

            /* Min heap to keep track of end times */
            std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

            /* Add the end time of the first interval to the heap */
            minHeap.push(vec[0].endTime);

            /* Iterate through the intervals starting from the second one */
            for (unsigned int count = 1; count < vec.size(); count++) {
                /* If the current interval's start time is after the earliest end time in the heap, remove that end time as it can be reused for the current interval */
                if (vec[count].startTime >= minHeap.top()) {
                    minHeap.pop();
                }

                /* Add the end time of the current interval to the heap */
                minHeap.push(vec[count].endTime);
            }

            /* The size of the heap is the minimum number of screening rooms needed */
            return static_cast<int>(minHeap.size());
        }
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
    Solution<Interval> solution;

    /* Input data */
    cout << "Input:" << endl;
    cout << "(0 <= intervals.length <= 10^4, if exceeded, it will be truncated.)" << endl;
    cout << "(0 <= starti < endi <= 10^6, please separate the data with spaces and press Enter.)" << endl;
    while (!solution.input(0, 1000000, 10000U)) {
        continue;
    }

    /* Output result */
    cout << "Output:" << endl;
    cout << "Minimum Number of Screening Rooms: " << solution.minRoomNum() << endl;

    /* Program ends */
    return 0;
}