class Solution {
    static bool cmd(int a,int b){
        return to_string(a)<to_string(b);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>a;
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        sort(a.begin(),a.end(),cmd);
        return a;
    }
};