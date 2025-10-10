class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>arr=energy;
        for(int i=n-1;i>=0;i--){
            if(i+k<n){
                arr[i]+=arr[i+k];
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};