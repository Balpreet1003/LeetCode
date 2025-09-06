class Solution {
    stack<int>st;
    bool isCycle(unordered_map<int, vector<int>>& adj_list, vector<bool>&vis, vector<bool>&pathVis, int i){
        vis[i]=true;
        pathVis[i]=true;
        for(auto x:adj_list[i]){
            if(!vis[x]){
                if(isCycle(adj_list, vis, pathVis, x))
                    return true;
            }
            else if(pathVis[x])
                return true;
        }
        pathVis[i]=false;
        st.push(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj_list;
        for(auto x:prerequisites){
            adj_list[x[0]].push_back(x[1]);
        }
        vector<bool>vis(numCourses,false), pathVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycle(adj_list, vis, pathVis, i))
                return {};
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};