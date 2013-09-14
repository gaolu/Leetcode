class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            profit += (prices[i] - prices[i - 1]) > 0 ? (prices[i] - prices[i - 1]) : 0;
        }
        return profit;
    }
};