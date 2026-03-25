class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if(prices[i]<minPrice)
                minPrice = min(minPrice, prices[i]);
            else    
                maxPro = max(maxPro, prices[i] - minPrice);
        }

        return maxPro;
    }
};