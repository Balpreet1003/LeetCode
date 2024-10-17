class Solution {
    set<vector<int>>a;
    void solve(vector<int>&b,int i,vector<int>&c){
        if(i>=b.size()){
            a.insert(c);
            return;
        }
        c.push_back(b[i]);
        solve(b,i+1,c);
        c.pop_back();
        solve(b,i+1,c);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>c;
        solve(nums,0,c);
        return vector<vector<int>>(a.begin(),a.end());
    }
};