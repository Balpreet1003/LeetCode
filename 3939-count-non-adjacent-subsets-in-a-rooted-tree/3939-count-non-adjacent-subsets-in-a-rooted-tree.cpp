class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        int root = -1;
        
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = i;
            } else {
                adj[parent[i]].push_back(i);
            }
        }

        int MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(k, 0)));

        auto dfs = [&](auto& self, int u) -> void {
            dp[u][0][0] = 1; 
            dp[u][1][nums[u] % k] = 1;

            for (int v : adj[u]) {
                self(self, v); 

                vector<long long> new_dp0(k, 0);
                vector<long long> new_dp1(k, 0);

                vector<long long> ways_v(k, 0);
                for (int r_v = 0; r_v < k; ++r_v) {
                    ways_v[r_v] = (dp[v][0][r_v] + dp[v][1][r_v]) % MOD;
                }

                for (int r_u = 0; r_u < k; ++r_u) {
                    if (dp[u][0][r_u] > 0) {
                        for (int r_v = 0; r_v < k; ++r_v) {
                            if (ways_v[r_v] > 0) {
                                int next_r = (r_u + r_v) % k;
                                new_dp0[next_r] = (new_dp0[next_r] + dp[u][0][r_u] * ways_v[r_v]) % MOD;
                            }
                        }
                    }
                    
                    if (dp[u][1][r_u] > 0) {
                        for (int r_v = 0; r_v < k; ++r_v) {
                            if (dp[v][0][r_v] > 0) {
                                int next_r = (r_u + r_v) % k;
                                new_dp1[next_r] = (new_dp1[next_r] + dp[u][1][r_u] * dp[v][0][r_v]) % MOD;
                            }
                        }
                    }
                }

                dp[u][0] = new_dp0;
                dp[u][1] = new_dp1;
            }
        };

        dfs(dfs, root);

        long long ans = (dp[root][0][0] + dp[root][1][0]) % MOD;
        
        ans = (ans - 1 + MOD) % MOD; 

        return ans;
    }
};