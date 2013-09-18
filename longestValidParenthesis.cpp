class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLen = 0, start = -1;
        stack<int> parenthesis;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') parenthesis.push(i);
            else{
                // set start to the first non-matched ')'
                if(parenthesis.empty()) start = i;
                else{
                    parenthesis.pop();
                    // from start to i
                    if(parenthesis.empty()) maxLen = max(maxLen, i - start);
                    // from start to the first non-matched '('
                    else maxLen = max(maxLen, i - parenthesis.top());
                }
            }
        }
        return maxLen;
    }
};
