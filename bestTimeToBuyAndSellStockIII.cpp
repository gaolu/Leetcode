class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() <= 0) return 0;
        vector<int> historyProfit(prices.size(), 0);
        vector<int> futureProfit(prices.size(), 0);
        int peak = prices[prices.size() - 1];
        int maxProfit = 0;
        int low = prices[0];
        // find history profit
        for(int i = 0; i < prices.size(); i++){
            low = min(low, prices[i]);
            if(i > 0)
                historyProfit[i] = max(historyProfit[i - 1], prices[i] - low);
        }
        // find future profit
        for(int i = prices.size() - 1; i >= 0; i--){
            peak = max(peak, prices[i]);
            if(i < prices.size() - 1)
                futureProfit[i] = max(futureProfit[i + 1], peak - prices[i]);
            maxProfit = max(maxProfit, historyProfit[i] + futureProfit[i]);
        }
        return maxProfit;
    }
};