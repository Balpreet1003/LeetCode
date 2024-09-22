class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,n=g.size(),m=s.size();
        while(i<n && j<m){
            if(g[i]<=s[j]) i++;
            j++;
        }
        return i;
    }
};