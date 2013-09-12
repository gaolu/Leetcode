class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        vector<int> count(n + 1, 0);
        if(n == 0 || n == 1)
            return 1;
        count[0] = 1, count[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                count[i] += count[j] * count[i - j - 1];
            }
        }
        return count[n];
    }
};
