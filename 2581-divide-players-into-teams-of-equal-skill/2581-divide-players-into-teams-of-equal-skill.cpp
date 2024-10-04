class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(), s.end());
        
        int n = s.size();
        int ts = s[0] + s[n - 1]; 
        long long ans= 0;

        for (int i = 0; i < n / 2; i++) {
            if (s[i] + s[n - i - 1] != ts) {
                return -1;
            }
            ans+= (long long)s[i]*s[n - i - 1];
        }

        return ans;
    }
};