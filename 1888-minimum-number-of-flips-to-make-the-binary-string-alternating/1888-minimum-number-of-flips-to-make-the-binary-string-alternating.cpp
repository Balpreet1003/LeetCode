class Solution {
    class Data{
        public:
            int even=0, odd=0;
    };
public:
    int minFlips(string s) {
        int n=s.length();
        Data *one = new Data();
        Data *zero = new Data();
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0')
                    zero->odd++;
                else
                    one->odd++;
            }
            else{
                if(s[i]=='0')
                    zero->even++;
                else
                    one->even++;
            }
        }

        int ans=min(one->even+zero->odd, one->odd+zero->even);
        for(int i=0;i<n;i++){
            swap(one->even, one->odd);
            swap(zero->even, zero->odd);
            if(n&1){
                if(s[i]=='1'){
                    one->even++;
                    one->odd--;
                }
                else{
                    zero->even++;
                    zero->odd--;
                }
            }
            ans=min({ans,one->even+zero->odd, one->odd+zero->even});
        }
        return ans;
    }
};