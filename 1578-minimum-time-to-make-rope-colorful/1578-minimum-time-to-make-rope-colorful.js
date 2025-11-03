/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let i=0, j=1, n= colors.length;
    let ans=0;
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
};