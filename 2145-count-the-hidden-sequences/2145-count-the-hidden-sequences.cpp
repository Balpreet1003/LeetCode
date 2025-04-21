class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini=0,maxi=0,n=differences.size();
        long long curr=0;
        for(int i=0;i<n;i++){
            curr+=differences[i];
            mini=min(mini,curr);
            maxi=max(maxi,curr);
        }
        int cnt = (upper-lower)-(maxi-mini)+1;
        return cnt>0 ? cnt:0;
    }
};