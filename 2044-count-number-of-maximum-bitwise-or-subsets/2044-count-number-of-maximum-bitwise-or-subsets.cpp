class Solution {
    unordered_map<int, int>m;
    void solve(vector<int>&a,int i,int x){
        if(i>=a.size()){
            m[x]++;
            return;
        }
        solve(a,i+1,x|a[i]);
        solve(a,i+1,x);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        solve(nums,0,0);
        int x=0,ans=0;
        for(auto i:m){
            if(x<i.first){
                x=i.first;
                ans=i.second;
            }
        }
        return ans;
    }
};