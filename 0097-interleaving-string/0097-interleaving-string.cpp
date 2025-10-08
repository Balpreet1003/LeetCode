class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), m = s3.length();
        if (n1 + n2 != m)
            return false;
        if(n1==0 && n2==0 && m==0)
            return true;
        vector<vector<int>>prev(n1+1, vector<int>(n2+1, 0)), curr(n1+1, vector<int>(n2+1, 0));
        prev[n1][n2]=true;
        for(int k=m-1;k>=0;k--){
            for(int i=0;i<=n1;i++){
                for(int j=0;j<=n2;j++){
                    bool ans = false;
                    if (i < n1 && s3[k] == s1[i])
                        ans |= prev[i + 1][j];
                    if (j < n2 && s3[k] == s2[j])
                        ans |= prev[i][j + 1];
                    curr[i][j] = ans;
                }
            }
            prev=curr;
        }
        return curr[0][0];
    }
};