class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>prev2(2,0),prev1(2,0),curr(2,0);
        for(int i=nums.size()-1;i>=0;i--){
            for(int zeroTrace=0;zeroTrace<2;zeroTrace++){
                //include
                int include=0;
                if(i==0){
                    include=prev2[1]+nums[i];
                }
                else{
                    if(i!=nums.size()-1)
                        include=prev2[zeroTrace]+nums[i];
                    else{
                        if(zeroTrace!=1)
                            include=prev2[zeroTrace]+nums[i];
                    }  
                }
                //exclude
                int exclude=prev1[zeroTrace];
                curr[zeroTrace] = max(include,exclude);
            }
            prev2=prev1;
            prev1=curr;
        }
        return curr[0];
    }
};