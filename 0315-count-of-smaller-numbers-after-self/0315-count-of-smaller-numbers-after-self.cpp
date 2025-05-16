class Solution {
    vector<int> ans;

    void merge_sort(vector<pair<int,int>>& nums, int l, int r){
        if (l >= r) return;
        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);

        vector<pair<int,int>> temp(r - l + 1);
        int i = l, j = mid + 1, k = 0;
        int rightCount = 0;

        while (i <= mid && j <= r){
            if (nums[i].first <= nums[j].first){
                ans[nums[i].second] += rightCount;
                temp[k++] = nums[i++];
            }
            else{
                rightCount++;
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid){
            ans[nums[i].second] += rightCount;
            temp[k++] = nums[i++];
        }

        while (j <= r){
            temp[k++] = nums[j++];
        }

        for (int p = 0; p < temp.size(); ++p){
            nums[l + p] = temp[p];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans = vector<int>(n, 0);
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < n; ++i){
            numWithIndex.push_back({nums[i], i});
        }
        merge_sort(numWithIndex, 0, n - 1);
        return ans;
    }
};