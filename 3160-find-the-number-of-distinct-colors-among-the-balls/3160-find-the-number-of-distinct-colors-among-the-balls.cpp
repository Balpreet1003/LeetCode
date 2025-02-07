class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>m1,m2;
        int n=queries.size(),colNum=0;

        for(int i=0;i<n;i++){
            if(m1.find(queries[i][1])!=m1.end() && m1[queries[i][1]]>0){
                m1[queries[i][1]]++;
            }
            else{
                m1[queries[i][1]]++;
                colNum++;
            }
            if(m2.find(queries[i][0])!=m2.end()){
                m1[m2[queries[i][0]]]--;
                if(m1[m2[queries[i][0]]]<=0)colNum--;
                m2[queries[i][0]]=queries[i][1];
            }
            else{
                m2[queries[i][0]]=queries[i][1];
            }
            ans.push_back(colNum);
        }
        return ans;
    }
};