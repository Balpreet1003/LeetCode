class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){
            return a[1]<b[1];
        });
        int ans=0, last=INT_MIN;
        for(auto& x:pairs){
            if(x[0]>last){
                ans++;
                last=x[1];
            }
        }
        return ans;
    }
};