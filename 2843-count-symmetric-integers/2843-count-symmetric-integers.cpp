class Solution {
    int getNumberOfDigits(int n){
        int cnt=0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        
        for(int i=low;i<=high;i++){
            int cnt=getNumberOfDigits(i);
            if(!(cnt&1)){
                int n=cnt/2;
                int x=i,sum1=0,sum2=0,j=0;
                while(x>0){
                    if(j<n){
                        sum1+=(x%10);
                    }
                    else{
                        sum2+=(x%10);
                    }
                    x/=10;
                    j++;
                }
                if(sum1==sum2)ans++;
            }
        }
        return ans;
    }
};