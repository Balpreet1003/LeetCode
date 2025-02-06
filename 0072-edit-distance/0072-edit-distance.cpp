class Solution {
    vector<vector<long long>>dp;
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp=vector<vector<long long>>(n+1,vector<long long>(m+1,0));
        vector<long long>curr(m+1,0),prev(m+1,0);

        for(int j=0;j<=m;j++)prev[j]=m-j;

        for(int i=n-1;i>=0;i--){
            curr[m]=n-i;
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) curr[j] = prev[j+1];
                else curr[j] = min(prev[j],min(curr[j+1],prev[j+1]))+1;
            }
            prev=curr;
        }
        
        return prev[0];
    }
};