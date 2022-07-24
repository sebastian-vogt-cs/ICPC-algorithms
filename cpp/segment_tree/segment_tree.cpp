#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

inline u64 leftChild(u64 i) {
    return 2 * i + 1;
}

inline u64 rightChild(u64 i) {
    return 2 * i + 2;
}

void build(u64 treeRoot, u64 l, u64 r, vector<i64>& segmentTree, vector<i64>& arr) {
    if (r - l == 1) {
        segmentTree[treeRoot] = arr[l];
        return;
    }
    u64 mid = (l + r) / 2;
    build(leftChild(treeRoot), l, mid, segmentTree, arr);
    build(rightChild(treeRoot), mid, r, segmentTree, arr);
    segmentTree[treeRoot] = segmentTree[leftChild(treeRoot)] + segmentTree[rightChild(treeRoot)];
}

/**
 * Builds a segment tree based on the given base array into the given segment tree array.
 *
 * @param segmentTree The array where the segment tree will live.
 * @param arr The base array.
 */
void build_segment_tree(vector<i64>& segmentTree, vector<i64>& arr) {
    segmentTree = vector<i64>(4 * arr.size(), 0);
    build(0, 0, arr.size(), segmentTree, arr);
}

i64 query_sum(u64 treeRoot, u64 l, u64 r, u64 ql, u64 qr, vector<i64>& segmentTree) {
    if (ql <= l && r <= qr) {
        return segmentTree[treeRoot];
    }
    i64 answer = 0;
    u64 mid = (l + r) / 2;
    if (ql < mid) {
        answer += query_sum(leftChild(treeRoot), l, mid, ql, qr, segmentTree);
    }
    if (qr > mid) {
        answer += query_sum(rightChild(treeRoot), mid, r, ql, qr, segmentTree);
    }
    return answer;
}

/**
 * Returns the sum between the indices l (inclusive) and r (exclusive) on an array of size N which is represented
 * by a segment tree.
 *
 * @param segmentTree The segment tree which represents the base-array.
 * @param l The start index for the sum on the base-array.
 * @param r The end index for the sum on the base-array.
 * @param N The length of the base-array (not of the segment-tree array!).
 * @return The sum of all numbers in [l, r).
 */
i64 sum(vector<i64>& segmentTree, u64 l, u64 r, u64 N) {
    return query_sum(0, 0, N, l, r, segmentTree);
}

void update(u64 index, i64 value, u64 treeRoot, u64 l, u64 r, vector<i64>& segmentTree) {
    if (r - l == 1) {
        segmentTree[treeRoot] = value;
        return;
    }
    u64 mid = (l + r) / 2;
    if (index < mid) {
        update(index, value, leftChild(treeRoot), l, mid, segmentTree);
    } else {
        update(index, value, rightChild(treeRoot), mid, r, segmentTree);
    }
    segmentTree[treeRoot] = segmentTree[leftChild(treeRoot)] + segmentTree[rightChild(treeRoot)];
}

/**
 * Updates the value at the given index of an array, which is represented by a segment tree.
 *
 * @param segmentTree The segment tree, which represents the base-array.
 * @param index The index in the base-array to update.
 * @param value The updated value.
 * @param N The length of the base-array (not of the segment-tree array!).
 */
void assign(vector<i64>& segmentTree, u64 index, i64 value, u64 N) {
    update(index, value, 0, 0, N, segmentTree);
}

int main() {
    vector<i64> segmentTree;
    vector<i64> arr{7, -3, 5, 8, 1};
    u64 N = arr.size();
    build_segment_tree(segmentTree, arr);
    cout << sum(segmentTree, 0, N, N) << endl;
    cout << sum(segmentTree, 0, N - 1, N) << endl;
    cout << sum(segmentTree, 0, N - 2, N) << endl;
    cout << sum(segmentTree, 0, N - 3, N) << endl;
    assign(segmentTree, 4, 20, N);
    cout << sum(segmentTree, 0, N, N) << endl;
}

