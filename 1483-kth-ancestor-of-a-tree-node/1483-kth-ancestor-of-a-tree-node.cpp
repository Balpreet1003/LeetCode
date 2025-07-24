class TreeAncestor {
    vector<vector<int>>up;
    int max_height;
public:
    TreeAncestor(int n, vector<int>& parent) {
        max_height=0;
        while((1<<max_height)<=n)max_height++;
        up.resize(n,vector<int>(max_height));

        for(int i=0;i<n;i++){
            up[i][0]=parent[i];
        }
        for(int j=1;j<max_height;j++){
            for(int i=0;i<n;i++){
                if(up[i][j-1]==-1){
                    up[i][j]=-1;
                }
                else {
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<max_height;j++){
            if(k&(1<<j)){
                node=up[node][j];
                if(node==-1)return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */