class Solution {
    vector<int>a;
    vector<bool>b;
    void getPrimeVec(int&l,int&r){
        for(int i=2;i<r;i++){
            if(b[i]==true){
                for(int j=2;j*i<=r;j++){
                    b[j*i]=false;
                }
            }
        }
        for(int i=l;i<=r;i++){
            if(b[i]==true &&i!=1)a.push_back(i);
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        b=vector<bool>(right+1,true);
        getPrimeVec(left,right);

        int diff=INT_MAX;
        vector<int>ans={-1,-1};
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]<diff){
                ans={a[i-1],a[i]};
                diff=a[i]-a[i-1];
            }
        }
        return ans;
    }
};