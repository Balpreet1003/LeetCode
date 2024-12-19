class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<=i;j++){
                if(arr[j]>i){
                    flag=false;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};