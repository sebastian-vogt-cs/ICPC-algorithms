#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

struct sqrt_decomposition {
    vector<i64> arr;
    vector<i64> blocks;
    u64 N{};
    u64 K{};
};

sqrt_decomposition from_vector(vector<i64> arr) {
    sqrt_decomposition sd;
    sd.arr = arr;
    sd.N = arr.size();
    sd.K = floor(sqrt(sd.N));
    sd.blocks = vector<i64>(sd.N / sd.K + (sd.N % sd.K == 0 ? 0 : 1), 0);
    for (u64 i = 0; i < sd.N; i++) {
        sd.blocks[i / sd.K] += arr[i];
    }
    return sd;
}

void assign(sqrt_decomposition& sd, u64 index, i64 value) {
    sd.blocks[index / sd.K] += value - sd.arr[index];
    sd.arr[index] = value;
}

i64 sum(sqrt_decomposition& sd, u64 l, u64 r) {
   i64 sum = 0;
   u64 i = l;
   while (i % sd.K != 0) {
       sum += sd.arr[i];
       i++;
   }
   while (i < r - sd.K + 1) {
       sum += sd.blocks[i / sd.K];
       i += sd.K;
   }
   while (i < r) {
       sum += sd.arr[i];
       i++;
   }
   return sum;
}

int main() {
    sqrt_decomposition sd = from_vector(vector<i64>{3, 4, 2, -5, 7, 4, -6, 8, 3, -5, 4, 1, 8, -4});
    cout << sum(sd, 0, sd.N) << endl;
    cout << sum(sd, 0, sd.N - 1) << endl;
    cout << sum(sd, 0, sd.N - 2) << endl;
    cout << sum(sd, 0, sd.N - 3) << endl;
    cout << sum(sd, 1, sd.N - 3) << endl;
    assign(sd, 4, 20);
    cout << sum(sd, 1, sd.N - 3) << endl;
}

