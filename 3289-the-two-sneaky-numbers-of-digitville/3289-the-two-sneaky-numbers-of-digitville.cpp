class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& a) {
        int n=a.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(a[i])==m.end()){
                m[a[i]]=1;
            }
            else {
                ans.push_back(a[i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};