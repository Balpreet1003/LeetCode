class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1)
            return false;
        //set<int>arr;
        int sum=-num;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                //arr.insert(i);
                //arr.insert(num/i);
                sum+=i;
                sum+=(num/i);
            }
        }
        // for(int i:arr)sum+=i;
        return sum==num;
    }
};