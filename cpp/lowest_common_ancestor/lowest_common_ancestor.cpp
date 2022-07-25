#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

struct node {
    i64 value;
    vector<u64> children;
};

void dfs(vector<pair<u64, u64>>& e, vector<u64>& fst, vector<node> const& tree, u64 nodeIndex, u64 depth) {
    fst[nodeIndex] = e.size();
    e.push_back({depth, tree[nodeIndex].value});
    for (u64 childIndex : tree[nodeIndex].children) {
        dfs(e, fst, tree, childIndex, depth + 1);
        e.push_back({depth, tree[nodeIndex].value});
    }
}

void euler_tour(vector<pair<u64, u64>>& e, vector<u64>& fst, vector<node> const& tree) {
    e = vector<pair<u64, u64>>();
    fst = vector<u64>(tree.size(), 0);
    dfs(e, fst, tree, 0, 0);
}

int main() {
    vector<node> tree{
        node{1, vector<u64>{1, 2, 3}},
        node{3, vector<u64>{4}},
        node{5, vector<u64>{}},
        node{2, vector<u64>{5, 6}},
        node{6, vector<u64>{}},
        node{4, vector<u64>{}},
        node{7, vector<u64>{}}
    };

    vector<pair<u64, u64>> e;
    vector<u64> fst;
    euler_tour(e, fst, tree);

    cout << e.size() << endl;
}

