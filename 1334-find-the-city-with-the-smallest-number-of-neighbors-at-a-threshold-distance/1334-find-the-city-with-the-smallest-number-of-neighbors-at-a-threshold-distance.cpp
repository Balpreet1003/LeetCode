class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        for(auto x:edges){
            dist[x[0]][x[1]]=x[2];
            dist[x[1]][x[0]]=x[2];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]==1e9 || dist[i][k]==1e9)continue;
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        
        int cnt=n;
        int ans=-1;
        for(int i=0;i<n;i++){
            int cnt1=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold)cnt1++;
            }
            if(cnt1<=cnt){
                ans=i;
                cnt=cnt1;
            }
        }
        return ans;
    }
};