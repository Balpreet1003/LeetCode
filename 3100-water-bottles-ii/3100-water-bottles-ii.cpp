class Solution {
public:
    int maxBottlesDrunk(int n, int m) {
        int ans=0;
        while(n>0){
            ans+=min(n, m);
            n-=m;
            n++;
            m++;
        }
        return ans;
    }
};