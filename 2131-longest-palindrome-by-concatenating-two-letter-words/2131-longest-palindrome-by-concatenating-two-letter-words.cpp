class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int ans = 0;
        for(auto s : words){
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(m[rev] > 0){
                ans += 4;
                m[rev]--;
            } else {
                m[s]++;
            }
        }
        for(auto &[i, j] : m){
            if(i[0] == i[1] && j > 0){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};