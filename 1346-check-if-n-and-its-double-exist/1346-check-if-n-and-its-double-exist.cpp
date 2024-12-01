class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(m.find(arr[i]*2)!=m.end() && i!=m[arr[i]*2])return 1;
        }
        return 0;
    }
};