class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0,n=fruits.size();
        vector<bool>used(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!used[j] && baskets[j]>=fruits[i]){
                    used[j]=true;
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};