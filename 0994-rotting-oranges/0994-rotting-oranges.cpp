class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>arr=grid;
        int count=0,ansTime=0,freshCount=0;

        for(int row=0;row<arr.size();row++){
            for(int col=0;col<arr[0].size();col++){
                if(arr[row][col]==2){
                    //rottten orange
                    q.push({{row,col},0});
                }
                if(arr[row][col]==1)
                    freshCount++;
            }
        }
        while(!q.empty()){
            auto fNode=q.front();
            q.pop();

            int x=fNode.first.first;
            int y=fNode.first.second;
            int time=fNode.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];

                if(newX>=0 && newY>=0 && newX<arr.size() && newY<arr[0].size() && arr[newX][newY]==1){
                    ansTime=max(ansTime,time+1);
                    q.push({{newX,newY},time+1});
                    //mark rotten
                    arr[newX][newY]=2;
                    freshCount--;
                }
            }
        }
        if(freshCount!=0)
            return -1;
        return ansTime;
    }
};