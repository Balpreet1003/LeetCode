class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remain_bottles = numBottles;
        while (remain_bottles >= numExchange) {
            int new_bottles = remain_bottles / numExchange;
            remain_bottles = new_bottles + remain_bottles % numExchange;
            ans +=new_bottles;
        }
        return ans;
    }
};