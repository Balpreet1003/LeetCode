class Solution {
    #define pii pair<int,int>
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        /*
            dist[A][0]=X: Distance from node1(source1) to 'node A' is X
            dist[A][1]=Y: Distance from node2(source2) to 'node A' is Y
        */
        vector<vector<int>> dist(n,vector<int>(2,-1));
        dist[node1][0]=0;
        dist[node2][1]=0;
        
        //Step-1: Multi-Source BFS to calculate distance of all nodes from node1 & node2
        queue<pii> q;
        q.push({node1,0});
        q.push({node2,1});
        while(!q.empty()){
            auto& [curr,type] = q.front();
            
            if(edges[curr]!=-1 and dist[edges[curr]][type]==-1){
                dist[edges[curr]][type] = 1 + dist[curr][type];
                q.push({edges[curr],type});
            }
            q.pop();
        }

        //Step-2: Minimize the max-distance of a node from node1 & node2 and track the meeting point
        int meeting_point = INT_MAX;
        int meeting_distance = INT_MAX;
        for(int i=0;i<n;++i){
            if(dist[i][0]!=-1 and dist[i][1]!=-1){
                int curr_dist = max(dist[i][0],dist[i][1]);
                if(curr_dist < meeting_distance){
                    meeting_distance = curr_dist;
                    meeting_point = i;
                }
            }
        }
        return meeting_point==INT_MAX?-1:meeting_point;
    }
};