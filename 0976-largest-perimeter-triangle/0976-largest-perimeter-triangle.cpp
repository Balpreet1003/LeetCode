class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i:nums)pq.push(i);

        while(pq.size()>2){
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
            int z=pq.top(); pq.pop();

            if(x+y>z && x+z>y && y+z>x){
                return x+y+z;
            }
            pq.push(y);
            pq.push(z);
        }
        return 0;
    }
};