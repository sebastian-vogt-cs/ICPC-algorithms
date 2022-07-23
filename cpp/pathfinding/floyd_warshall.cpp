#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

/**
 * Calculates the shortest path between any two nodes in the input graph and inserts the shortest paths directly into
 * the adjacency matrix.
 *
 * @param mat The adjacency matrix representing the graph to compute on, filled with weight values of the template type.
 *            Must be a n x n matrix. Nodes that are not connected must be represented by the greatest positive value
 *            of the template type.
 * @param n The number of nodes in the graph.
 */
template <typename T>
void floyd(vector<vector<T>>& mat, u32 n) {
    for (u32 k = 0; k < n; k++) {
        for (u32 i = 0; i < n; i++) {
            for (u32 j = 0; j < n; j++) {
                if (mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
}

template <typename T>
void print_matrix(vector<vector<T>> const& matrix) {
    for (vector<T> const& row: matrix) {
        for (T const& n: row) {
            cout << n << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example for floyd_double:
    vector<vector<double>> matrix{{INFINITY, 5.0, INFINITY},
                                  {3.0, INFINITY, INFINITY},
                                  {INFINITY, 2.0, INFINITY}};
    floyd(matrix, 3);
    print_matrix(matrix);

}

