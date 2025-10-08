class Solution {
    int get_len(vector<int>& arr, long long tar, long long x){
        int l=0, h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(1LL*x*arr[mid]>=tar){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;

        for(int i:spells){
            int ind=get_len(potions, success, 1LL*i);
            ans.push_back(potions.size()-ind);
        }
        return ans;
    }
};