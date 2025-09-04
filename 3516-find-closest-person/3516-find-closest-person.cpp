class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a=abs(x-z),b=abs(y-z);
        if(a>b)return 2;
        else if(a<b)return 1;
        return 0;
    }
};