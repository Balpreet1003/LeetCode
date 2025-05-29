class Solution {
    bool is_possible(vector<int>&jobs, int& sum, vector<int>&load, int i){
        if(i>=jobs.size())return true;

        for(int j=0;j<load.size();j++){
            if(load[j]+jobs[i]<=sum){
                load[j]+=jobs[i];
                if(is_possible(jobs,sum,load,i+1))return true;
                load[j]-=jobs[i];
            }
            if(load[j]==0)break;
        }
        return false;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int l=*max_element(jobs.begin(),jobs.end());
        int r = accumulate(jobs.begin(), jobs.end(), 0);

        int ans=0;

        sort(jobs.begin(),jobs.end());
        while(l<=r){
            int mid=r-((r-l)/2);
            vector<int>load(k,0);
            if(is_possible(jobs,mid,load,0)) {
                r=mid-1;
                ans=mid;
            }
            else {
                l=mid+1;
            }
        } 
        return ans;
    }
};