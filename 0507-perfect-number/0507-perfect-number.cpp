class Solution {
public:
    bool checkPerfectNumber(int num) {
        set<int>arr;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                arr.insert(i);
                arr.insert(num/i);
            }
        }
        int sum=-num;
        for(int i:arr)sum+=i;
        return sum==num;
    }
};