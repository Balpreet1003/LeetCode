class FindSumPairs {
    unordered_map<int,int>m1,m2;
    vector<int>a,b;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        b=nums2;
        for(int x:nums2)m2[x]++;
        for(int x:nums1)m1[x]++;
    }
    
    void add(int index, int val) {
        int x=b[index];
        b[index]+=val;
        m2[x]--;
        if(m2[x]==0){
            m2.erase(x);
        }
        m2[x+val]++;
    }
    
    int count(int tar) {
        int ans=0;
        for(auto &[x,y]:m1){
            if(m2.find(tar-x)!=m2.end()){
                ans+=(y*m2[tar-x]);
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */