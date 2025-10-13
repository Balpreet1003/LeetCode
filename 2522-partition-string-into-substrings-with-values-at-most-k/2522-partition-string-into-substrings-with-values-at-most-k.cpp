class Solution {
    // int solve(string& s, int& k, int i){
    //     if(i>=s.length())
    //         return 0;
    //     string s="";
    //     for(int j=i;j<s.length();j++){

    //     }
    // }
public:
    int minimumPartition(string s, int k) {
        // return solve(s, k, 0);

        int ans=1;
        string s1="";
        for(char ch:s){
            if(ch-'0'>k)
                return -1;
            s1+=ch;
            if(stoll(s1)>1LL*k){
                s1="";s1+=ch;
                ans++;
            }
        }
        return ans;
    }
};