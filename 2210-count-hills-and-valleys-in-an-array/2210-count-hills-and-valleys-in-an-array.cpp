class Solution {
public:
    int countHillValley(vector<int>& nums) {
        unordered_map<int ,int>m;
        vector<int>a;
        int n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])==m.end()){
                a.push_back(nums[i]);
                m[nums[i]]++;
            }
        }
        for(int i=1;i<a.size()-1;i++){
            if((a[i]>a[i-1] && a[i]>a[i+1]) || a[i]<a[i-1] && a[i]<a[i+1]){
                ans++;
            }
        }
        return ans;
    }
};