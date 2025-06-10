class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size();
        int j=n-1;
        int ans=min(height[i],height[j])*(j-i);

        while(j>i){
            if(height[i]<height[j])i++;
            else j--;

            ans=max(ans,min(height[i],height[j])*(j-i));
        }
        return ans;
    }
};