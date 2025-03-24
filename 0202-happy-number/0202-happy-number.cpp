#define ll long long 
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<ll,bool>m;
        ll x=(ll)n;
        while(m.find(x)==m.end()){
            m[x]=true;
            ll y=0;
            while(x){
                y+=(x%10)*(x%10);
                x/=10;
            }
            x=y;
        }
        return x==1;
    }
};