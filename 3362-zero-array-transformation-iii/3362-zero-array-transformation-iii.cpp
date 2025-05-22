class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int applied=0;
        priority_queue<int>apply;
        priority_queue<int,vector<int>,greater<int>>inuse;
        int j=0;
        sort(queries.begin(),queries.end());

        for(int i=0;i<nums.size();i++){
            while(j<queries.size() && queries[j][0]==i)apply.push(queries[j++][1]);

            while(nums[i]>inuse.size()){
                if(apply.empty())return -1;
                inuse.push(apply.top());
                apply.pop();
                applied++;
            }

            while(!inuse.empty() && inuse.top()==i)inuse.pop();
        }

        return queries.size()-applied;
    }
};