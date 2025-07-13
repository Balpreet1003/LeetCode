#define ll long long 
class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        vector<ll>a(n+1,0);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='*'){
                a[i]=max(a[i-1]-1,0LL);
            }
            else if(s[i-1]=='#'){
                a[i]=a[i-1]*2;
            }
            else if(s[i-1]=='%'){
                a[i]=a[i-1];
            }
            else{
                a[i]=a[i-1]+1;
            }
        }
        if(k>=a[n]){
            return '.';
        }

        for(int i=n;i>0;i--){
            if(s[i-1]=='*'){
                a[i]=a[i-1];
            }
            else if(s[i-1]=='#'){
                ll half=a[i]/2;
                if(k>=half){
                    k-=half;
                }
                a[i]/=2;
            }
            else if(s[i-1]=='%'){
                k=a[i]-1-k;
            }
            else{
                if(k==a[i]-1){
                    return s[i-1];
                }
                a[i]--;
            }
        }
        return '.';
    }
};