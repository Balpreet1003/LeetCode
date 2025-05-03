class Solution {
    int solve(int i,vector<int>&tops,vector<int>&bottoms){
        int cnt=0,n=tops.size();
        for(int j=0;j<n;j++){
            if(tops[j]==i){
                continue;
            }
            else if(bottoms[j]==i)cnt++;
            else{
                return INT_MAX;
            }
        }
        return cnt;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            int cnt1=solve(i,tops,bottoms);
            int cnt2=INT_MAX;
            if(cnt1!=INT_MAX)cnt2=solve(i,bottoms,tops);
            ans=min(ans,min(cnt1,cnt2));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};