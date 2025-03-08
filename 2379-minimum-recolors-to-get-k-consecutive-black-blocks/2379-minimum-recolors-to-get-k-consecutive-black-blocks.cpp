class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX,n=blocks.length();
        for(int i=0;i<n;i++){
            int cnt=0;
            int len=0;
            for(int j=i;j<n;j++){
                if(blocks[j]=='W')cnt++;
                len++;
                if(len>=k)break;
            }
            if(len>=k)ans=min(ans,cnt);

        }
        return ans;
    }
};