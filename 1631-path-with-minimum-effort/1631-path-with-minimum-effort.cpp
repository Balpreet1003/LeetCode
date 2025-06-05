class Solution {
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size(); 
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int diff=pq.top().first;
            pq.pop();

            for(int l=0;l<4;l++){
                int i=x+dx[l];
                int j=y+dy[l];
                if(i>=0 && i<n && j>=0 && j<m){
                    int diff1=max(abs(heights[i][j]-heights[x][y]),diff);
                    if(dis[i][j]>diff1){
                        dis[i][j]=diff1;
                        pq.push({diff1,{i,j}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};