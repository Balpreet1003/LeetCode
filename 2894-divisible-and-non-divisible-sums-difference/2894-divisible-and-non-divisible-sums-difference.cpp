class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(i%m==0){
                ans2+=i;
            }
            else {
                ans1+=i;
            }
        }
        return ans1-ans2;
    }
};