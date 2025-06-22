class Solution {
    vector<bool> is_prime;
    void prime_fun() {
        int n = 101;
        is_prime.resize(n, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        prime_fun();
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        for(auto &[x,y]:m){
            if(is_prime[y]){
                return true;
            }
        }
        return false;
    }
};