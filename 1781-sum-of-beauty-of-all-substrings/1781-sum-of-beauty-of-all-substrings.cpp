class Solution {
public:
    int beautySum(string s) {
        int ans=0,n=s.length();
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                if((j-i)>0){
                    int maxi=INT_MIN;
                    int mini=INT_MAX;
                    for(auto k:m){
                        mini=min(mini,k.second);
                        maxi=max(maxi,k.second);
                    }
                    ans+=(maxi-mini);
                }
            }
        }
        return ans;
    }
};