class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        vector<int>b,c;
        for(auto i:a){
            b.push_back(i[0]);
            c.push_back(i[1]);
        }
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int ans=0,j=0;
        for(auto i:b){
            if(i>c[j])j++;
            else ans++;
        }
        return ans;
    }
};