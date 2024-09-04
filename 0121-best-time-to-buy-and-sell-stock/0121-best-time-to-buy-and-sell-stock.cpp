class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0;
        int minPrice=prices[0];
        // findMaxProfit(prices,maxProf,minPrice,i);
        for(int i=1;i<prices.size();i++){
            maxProf = max(maxProf,prices[i]-minPrice);
            minPrice = min(prices[i],minPrice);
        }
        return maxProf;
    }
};