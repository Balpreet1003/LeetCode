class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans = 0;
        int x_min=1e7,x_max=0;
        int y_min=1e7,y_max=0;

        unordered_map<int,pair<int,int>>mx,my;
        for(auto x:coords){
            x_min=min(x_min,x[0]);
            x_max=max(x_max,x[0]);
            if(mx.find(x[0])==mx.end()){
                mx[x[0]]={x[1],x[1]};
            }
            else{
                mx[x[0]].first=min(mx[x[0]].first, x[1]);
                mx[x[0]].second=max(mx[x[0]].second, x[1]);
            }
            
            y_min=min(y_min,x[1]);
            y_max=max(y_max,x[1]);
            if(my.find(x[1])==my.end()){
                my[x[1]]={x[0],x[0]};
            }
            else{
                my[x[1]].first=min(my[x[1]].first, x[0]);
                my[x[1]].second=max(my[x[1]].second, x[0]);
            }
        }

        for(auto &[x, y_range]:mx){
            int y1 = y_range.first;
            int y2 = y_range.second;
            if(y1 != y2){
                ans = max(ans, max(1LL * abs(x - x_min), 1LL * abs(x - x_max)) * abs(y1 - y2));
            }
        }
        for(auto &[y, x_range]:my){
            int x1 = x_range.first;
            int x2 = x_range.second;
            if(x1 != x2){
                ans = max(ans, max(1LL * abs(y - y_min), 1LL * abs(y - y_max)) * abs(x1 - x2));
            }
        }
        return ans==0?-1:ans;
    }
};