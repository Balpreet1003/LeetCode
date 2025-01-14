class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int n=A.size();
        unordered_map<int,bool>m;
        for(int i=0;i<n;i++){
            int cnt=0;
            m[A[i]]=true;
            for(int j=0;j<=i;j++){
                if(m.find(B[j])!=m.end())cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};