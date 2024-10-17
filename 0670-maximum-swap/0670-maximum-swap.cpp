class Solution {
public:
    int maximumSwap(int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        string s=to_string(m);
        int n=s.length();
        vector<bool>a(n,false);
        for(int i=0;i<n;i++){
            int x=i;
            if(!a[i]){
                for(int j=n-1;j>i;j--){
                    if(s[j]>s[x] && !a[j])x=j;
                }
                if(x!=i){
                    swap(s[i],s[x]);
                    a[i]=1;a[x]=1;
                    break;
                }
            }
        }
        return stoi(s);
    }
};