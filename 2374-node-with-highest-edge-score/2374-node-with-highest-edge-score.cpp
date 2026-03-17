class Solution {
    unordered_map<int, long long>mp;
public:
    int edgeScore(vector<int>& edges) {
        for(int i=0;i<edges.size();i++){
            mp[edges[i]]+=i;
        }
        long long ans=-1, maxi=INT_MIN;
        for(int i=0;i<edges.size();i++){
            if(maxi<mp[i]){
                ans=i;
                maxi=mp[i];
            }
        }
        return ans;
    }
};