class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& arr) {
        int ans=0, n=arr.size(), m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && arr[i][j]!=0){
                    arr[i][j]+=arr[i-1][j];
                }
            }
            vector<int>height=arr[i];
            sort(height.begin(), height.end(), greater<int>());
            for(int j=0;j<m;j++){
                int base=j+1;
                int x=height[j];
                ans=max(ans, base*x);
            }
        }
        return ans;
    }
};