class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() == 0)
            return 0;
        int low = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            low = min(low, prices[i]);
            profit = max(profit, prices[i] - low);
        }
        return profit;
    }
};