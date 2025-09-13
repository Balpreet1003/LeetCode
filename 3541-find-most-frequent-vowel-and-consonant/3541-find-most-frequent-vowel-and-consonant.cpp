class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>m1,m2;
        int cnt1=0,cnt2=0;
        for(char ch:s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                m1[ch]++;
                cnt1=max(cnt1,m1[ch]);
            }
            else {
                m2[ch]++;
                cnt2=max(cnt2,m2[ch]);
                
            }
        }
        return cnt1 + cnt2;
    }
};