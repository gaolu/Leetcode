class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        if(n <= 0) return result;
        string combination = "";
        helper(result, combination, n, 0, 0, 0);
        return result;
    }
    // use left to indicate # of left parenthesis, right # of right parenthesis
    // if left < n, continue insert '(', if left > right, insert ')'
    // before returning, erase the inserted parenthesis so as to trace back to previous state
    void helper(vector<string> &result, string &combination, int n, int left, int right, int total){
        if(total == 2 * n){
            result.push_back(combination);
            return;
        }
        if(left < n){
            combination.push_back('(');
            helper(result, combination, n, left + 1, right, total + 1);
            combination.resize(combination.size() - 1);
        }
        if(left > right){
            combination.push_back(')');
            helper(result, combination, n, left, right + 1, total + 1);
            combination.resize(combination.size() - 1);
        }
        return;
    }
};
