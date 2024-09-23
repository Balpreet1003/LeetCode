class Solution {
public:
    int change(int am, vector<int>& c){
        int n=c.size();
        vector<long long>prev(am+1,0),curr(am+1,0);
        prev[0]=1;
        curr[0]=1;
        for(int i=0;i<n;i++){
            for(int a=1;a<=am;a++){
                int exclude=0;
                if(i>0)exclude=prev[a];
                int include=0;
                if(c[i]<=a)include=curr[a-c[i]];
                curr[a]=(long long)include+exclude;
            }
            prev=curr;
        }
        return curr[am];
    }
};