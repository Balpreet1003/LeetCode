class Solution {
    void heapPush(priority_queue<pair<double,int>>&pq,vector<vector<int>>& classes,int i){
        double curr=((double)classes[i][0]/classes[i][1]);
        double neW=((double)(classes[i][0]+1)/(classes[i][1]+1));
        double poss_inc=neW-curr;
        pq.push({poss_inc,i});
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++)heapPush(pq,classes,i);

        while(extraStudents--){
            auto curr=pq.top();
            pq.pop();
            int i=curr.second;
            classes[i][0]++;
            classes[i][1]++;

            heapPush(pq,classes,i);
        }
        double ans=0.0;
        for(int i=0;i<n;i++){
            ans+=((double)classes[i][0]/classes[i][1]);
        }
        return ans/n;
    }
};