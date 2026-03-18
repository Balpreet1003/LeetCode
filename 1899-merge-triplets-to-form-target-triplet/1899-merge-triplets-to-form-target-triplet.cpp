class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        bool ans[3]={false, false, false};
        for(auto x:triplets){
            if(x[0]<=t[0] && x[1]<=t[1] && x[2]<=t[2]){
                if(x[0]==t[0])
                    ans[0]=true;
                if(x[1]==t[1])
                    ans[1]=true;
                if(x[2]==t[2])
                    ans[2]=true;
            }
            if(ans[0] && ans[1] && ans[2])
                return true;
        }
        return false;
    }
};