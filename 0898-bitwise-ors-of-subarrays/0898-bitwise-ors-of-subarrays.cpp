class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>ans,prev;
        for(int num:arr){
            set<int>curr;
            curr.insert(num);
            for(auto x:prev){
                curr.insert(x|num);
            }
            prev=curr;
            ans.insert(curr.begin(), curr.end());
        }
        return ans.size();
    }
};