class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int x=a[i];
            if(x==2){
                ans[i]=-1;
                continue;
            }
            int y=x,c=0;
            while((y&1)==1){
                c++;
                y=y>>1;
            }
            ans[i]=x-(1<<(c-1));
        }
        return ans;
    }
};