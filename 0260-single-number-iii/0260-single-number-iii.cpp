class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor=0;
        for(int i:nums){
            all_xor^=i;
        }
        int pos=0;
        while(!((all_xor>>pos)&1)){
            pos++;
        }
        int x=0;
        for(int i:nums){
            if((i>>pos)&1){
                x^=i;
            }
        }
        
        return {x,all_xor^x};
    }
};