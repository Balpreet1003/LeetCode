class Solution {
    vector<vector<string>>ans;
    unordered_map<int,int>m,diag1,diag2;
    void solve(int& n, int i, vector<string>&temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(m.count(j) || diag1.count(i-j) || diag2.count(i+j))continue;
            
            temp[i][j]='Q';
            m[j]=1;
            diag1[i-j]=1;
            diag2[i+j]=1;

            solve(n,i+1,temp);
            
            diag1.erase(i-j);
            diag2.erase(i+j);
            m.erase(j);
            temp[i][j]='.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>temp(n,s);
        solve(n,0,temp);
        return ans;
    }
};