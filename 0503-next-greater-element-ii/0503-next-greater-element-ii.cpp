class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        vector<int>ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            int x=-1;
            for(int j=i+1;j!=i;j++){
                if(j>=n)j=-1;
                else if(a[i]<a[j]){
                    x=a[j];
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};