class Solution {
public:
    int minBitFlips(int n1, int n2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int count=0;
        while(n1 || n2){
            bool p1=n1&1,p2=n2&1;
            if(p1!=p2)count++;
            n1=n1>>1;
            n2=n2>>1;
        }
        return count;
    }
};