class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        unordered_map<int,bool>m;
        for(int i:banned){
            m[i]=1;
        }
        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end()){
                if((maxSum-i)>=0){
                    maxSum-=i;
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};