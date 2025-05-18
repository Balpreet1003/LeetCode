#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

struct tuple_hash {
    template <class T>
    size_t operator()(const T& t) const {
        return hash<string>()(to_string(get<0>(t)) + "|" + to_string(get<1>(t)) + "|" + to_string(get<2>(t)));
    }
};

class Solution {
    int M, N;
    using State = tuple<int, long long, int>;
    unordered_map<State, int, tuple_hash> memo;

    int solve(int x, long long prevRowMask, int prevColColor) {
        if (x >= M * N) return 1;

        int i = x / M;
        int j = x % M;

        if (j == 0) prevColColor = 0;

        State key = {x, prevRowMask, prevColColor};
        if (memo.count(key)) return memo[key];

        int ans = 0;
        int colorAbove = (i > 0) ? ((prevRowMask >> (2LL * j)) & 3) : 0;

        for (int color = 1; color <= 3; ++color) {
            if (color != colorAbove && color != prevColColor) {
                long long newMask = prevRowMask;
                newMask &= ~(3LL << (2LL * j));
                newMask |= (1LL * color << (2LL * j));
                ans = (ans + solve(x + 1, newMask, color)) % MOD;
            }
        }
        return memo[key] = ans;
    }

public:
    int colorTheGrid(int m, int n) {
        M = m;
        N = n;
        memo.clear();
        return solve(0, 0, 0);
    }
};