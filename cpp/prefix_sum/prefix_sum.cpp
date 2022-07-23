#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

/**
 * Calculates the prefix sum of the given array in-place. The first element of the array will be set to 0, which means
 * that the array grows by one element.
 *
 * @param arr The array on which to calculate the prefix sum.
 */
void prefix_sum(vector<i64>& arr) {
    i64 sum = 0;
    for (i64& i : arr) {
        i64 nextNumber = i;
        i = sum;
        sum += nextNumber;
    }
    arr.resize(arr.size() + 1, sum);
}

/**
 * Calculates the difference array on the given array in place. Note that the output array is one element shorter than
 * the original array.
 *
 * @param arr The array on which to calculate the difference array.
 */
void difference_array(vector<i64>& arr) {
    for (auto i = arr.begin(); i != arr.end() - 1; i++) {
        *i = *(i+1) - *i;
    }
    arr.resize(arr.size() - 1);
}

int main() {
    vector<i64> arr{3, 1, 4};
    prefix_sum(arr);
    for (i64 n: arr) {
        cout << n << " ";
    }
    cout << endl;

    difference_array(arr);
    for (i64 n: arr) {
        cout << n << " ";
    }
    cout << endl;
}

