class Solution {
    bool is_poss(vector<int>& arr, int h, long long t){
        long long ans=0;
        for(auto x:arr){
            ans+=(sqrt(((2*t)/x)+0.25)-0.5);
            if(ans>=h)
                return true;
        }
        return ans>=h;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=1, r=(*max_element(workerTimes.begin(), workerTimes.end())*1LL)*((mountainHeight*1LL*(mountainHeight*1LL+1))/2);
        long long ans=0;
        while(l<=r){
            long long mid=r-((r-l)/2);
            if(is_poss(workerTimes, mountainHeight, mid)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};