class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(i-j)<=k && nums[i]==key){
                    ans.insert(j);
                }
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};