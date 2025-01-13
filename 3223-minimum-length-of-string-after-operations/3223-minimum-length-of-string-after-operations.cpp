class Solution {
public:
    int minimumLength(string s) {
        vector<int>arr(26,0);
        for(char c:s){
            arr[c-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                if(arr[i]&1)ans+=1;
                else ans+=2;
            }
        }
        return ans;
    }
};