/*
 * Yulian Kraynyak
 * yk2562
 * HW14
 *
 * Merge-sort implementation to find the minimum and maximum of a vector.
 */

#include <iostream>
#include <vector>

using namespace std;

/* Constants */
const int MIN_INDEX = 0;
const int MAX_INDEX = 1;

/* Function Prototypes */
vector<int> findMinMax(const vector<int>& v, int low, int high);
void printVector(const vector<int>& v);
void printMinMax(const vector<int>& v);

/* Main */
int main() {
    vector<int> input = { 3, -6, 981, 2405, 103, -235, 43, 78, 23, 456, -202, 21, 1, 3, 0, 3 };
    vector<int> minMax;

    printVector(input);
    minMax = findMinMax(input, 0, input.size() - 1);
    printMinMax(minMax);

    return 0;
}

/* Functions */
vector<int> findMinMax(const vector<int>& v, int low, int high) {
    vector<int> result = { 0, 0 };

    if (high - low == 0) {
        // One item -> so it's both the min & max
        result[MIN_INDEX] = v[low];
        result[MAX_INDEX] = v[low];
    }else if (high - low == 1) {
        // Two items -> compare both
        if (v[low] < v[high]) {
            result[MIN_INDEX] = v[low];
            result[MAX_INDEX] = v[high];
        }else {
            result[MIN_INDEX] = v[high];
            result[MAX_INDEX] = v[low];
        }
    }else {
        // Split into two halves
        vector<int> left, right = { 0, 0 };
        int mid = (low + high) / 2;

        left = findMinMax(v, 0, mid);
        right = findMinMax(v, mid + 1, high);

        result[MIN_INDEX] = min(left[MIN_INDEX], right[MIN_INDEX]);
        result[MAX_INDEX] = max(left[MAX_INDEX], right[MAX_INDEX]);
    }
    return result;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void printMinMax(const vector<int>& v) {
    cout << endl;
    cout << "Min: " << v[MIN_INDEX] << endl;
    cout << "Max: " << v[MAX_INDEX] << endl;
}