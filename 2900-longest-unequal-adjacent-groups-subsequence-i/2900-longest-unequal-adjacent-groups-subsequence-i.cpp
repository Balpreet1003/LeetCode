class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans={words[0]};
        int n=words.size(),x=groups[0];
        for(int i=1;i<n;i++){
            if(groups[i]!=x){
                ans.push_back(words[i]);
                x=groups[i];
            }
        }
        return ans;
    }
};