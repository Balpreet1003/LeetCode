class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=-k,r=k;
            int x=INT_MIN;
            while(l<=r){
                int mid=l-((l-r)/2);
                if(m.find(nums[i]+mid)==m.end()){
                    x=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(x!=INT_MIN){
                m[nums[i]+x]=1;
            }
        }
        return m.size();
    }
};