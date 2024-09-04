class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        vector<pair<int,int>>nums1(n);
        for(int i=0;i<n;i++){
            nums1[i]=make_pair(nums[i],i);
        }
        sort(nums1.begin(),nums1.end());
        int i=0,j=nums1.size()-1;
        while(i<j){
            if(((nums1[i]).first+(nums1[j].first))>target)
                j--;
            else if(((nums1[i]).first+(nums1[j].first))<target)
                i++;
            else{
                ans.push_back((nums1[i]).second);
                ans.push_back((nums1[j]).second);
                break;
            }
        }
        return ans;
    }
};