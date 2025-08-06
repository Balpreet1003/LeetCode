class Solution {
    vector<int>segTree;
    void buildSegTree(vector<int>& nums, int l, int h, int start){
        if(l==h){
            segTree[start]=nums[l];
            return ;
        }

        int mid=l+((h-l)/2);
        buildSegTree(nums, l, mid, 2*start);
        buildSegTree(nums, mid+1, h, 2*start+1);
        segTree[start]=max(segTree[2*start], segTree[2*start+1]);
    }
    int getLeftBasket(int& tar, int l, int h, int s){
        if(segTree[s]<tar){
            return -1;
        }
        if(l==h){
            segTree[s]=-1;
            return 1;
        }

        int ans=0, mid=l+((h-l)/2);
        if(segTree[2*s]>=tar){
            ans=getLeftBasket(tar, l, mid, 2*s);
        }
        else{
            ans=getLeftBasket(tar, mid+1, h, 2*s+1);
        }
        segTree[s]=max(segTree[2*s], segTree[2*s+1]);
        return ans;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        segTree.resize(4*n + 1);
        buildSegTree(baskets, 0, n-1, 1);

        int ans=0;
        for(auto i:fruits){
            if(getLeftBasket(i, 0, n-1, 1)==-1){
                ans++;
            }
        }
        return ans;
    }
};