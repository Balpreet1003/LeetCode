class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>trace;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                trace[mat[i][j]]={i,j};
            }
        }
        vector<int>row(m,0),col(n,0);

        for(int x=0;x<arr.size();x++){
            int i=trace[arr[x]].first,j=trace[arr[x]].second;
            row[i]++;
            col[j]++;
            if(row[i]>=m)return x;
            if(col[j]>=n)return x;
        }
        return -1;
    }
};