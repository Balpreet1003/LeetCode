class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>m1,m2;
        for(int i=1;i<=n;i++){
            int sum=0;
            int x=i;
            while(x){
                sum+=(x%10);
                x/=10;
            }
            m1[sum]++;
        }
        for(auto &[i,j]:m1){
            m2[j]++;
        }
        int ans=0;
        int x=-1;
        for(auto &[i,j]:m2){
            if(x==-1){
                x=i;
                ans=j;
            }
            else if(i>x){
                x=i;
                ans=j;
            }
        }
        return ans;
    }
};