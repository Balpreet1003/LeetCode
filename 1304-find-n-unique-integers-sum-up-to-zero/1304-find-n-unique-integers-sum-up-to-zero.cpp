class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n);
        int i=0,j=n-1, x=n/2;
        while(i<=j){
            ans[i++]=-x;
            ans[j--]=x;
            x--;
        }
        return ans;
    }
};