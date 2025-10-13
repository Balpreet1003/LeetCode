class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>arr;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            arr.push_back(capacity[i]-rocks[i]);
        }
        sort(arr.begin(), arr.end());

        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=additionalRocks){
                ans++;
                additionalRocks-=arr[i];
            }
        }
        return ans;
    }
};