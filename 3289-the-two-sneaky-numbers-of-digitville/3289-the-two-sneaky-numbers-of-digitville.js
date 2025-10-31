/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    let trace={};
    let ans=[];
    for(let i=0;i<nums.length;i++){
        trace[nums[i]] = (trace[nums[i]] || 0) + 1;
        if(trace[nums[i]]>1){
            ans.push(nums[i]);
        }
    }
    return ans;
};