class Solution {
    bool isPossible(vector<int>&a,int&k,int&h){
        int x=0;
        for(int i:a){
            x+=((i/k)+((i%k==0)?0:1));
        }
        return x<=h;
    }
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int i=1,j;
        for(int x:a)j=max(j,x);
        int ans=1;
        while(i<=j){
            int mid=j-((j-i)/2);
            if(isPossible(a,mid,h)) {
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};