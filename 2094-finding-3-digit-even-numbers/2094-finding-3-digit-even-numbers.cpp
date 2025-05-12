class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i){
                        int x=digits[i]*100 + digits[j]*10 + digits[k];
                        if(x>99 && !(x&1))ans.insert(x);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};