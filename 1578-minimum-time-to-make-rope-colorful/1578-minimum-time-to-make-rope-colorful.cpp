class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0, j=1, n=colors.length();
        int ans=0;
        while(j<n){
            if(colors[i]==colors[j]){
                if(neededTime[i]>neededTime[j]){
                    ans+=neededTime[j];
                }
                else{
                    ans+=neededTime[i];
                    i=j;
                }
            }
            else
                i=j;
            j++;
        }
        return ans;
    }
};