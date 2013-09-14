class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(T.size() + 1);
        dp[T.size()] = 1; // choose nothing
        for(int i = S.size() - 1; i >= 0; i--){
            for(int j = 0; j < T.size(); j++){
                if(T[j] == S[i])
                    dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};