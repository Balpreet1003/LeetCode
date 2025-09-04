class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {

        int n=statements.size(), ans=0;

        for(int i=1;i<(1<<n);i++){
            vector<int>arr(n,-1);
            int cnt=0;
            for(int j=0;j<16;j++){
                if((i>>j)&1){
                    arr[j]=1;
                    cnt++;
                }
            }
            bool flag=true;
            for(int j=0;j<n;j++){
                if(arr[j]==1){
                    for(int k=0;k<n;k++){
                        if(k==j)
                            continue;
                        else{
                            if(statements[j][k]==1){
                                if(arr[k]==-1){
                                    flag=false;
                                    break;
                                }
                            }
                            else if(statements[j][k]==0){
                                if(arr[k]==1){
                                    flag=false;
                                    break;
                                }
                            }
                        }
                    }
                    if(!flag)
                        break;
                }
            }
            if(flag)
                ans=max(ans, cnt);
        }
        return ans;
    }
};