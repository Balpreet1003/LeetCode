class Solution {
public:
    int smallestNumber(int n) {
        int i=0;
        while(true){
            if((1<<i)>n)
                return (1<<i)-1;
            i++;
        }
        return -1;
    }
};