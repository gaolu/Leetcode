class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        string chars[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        string subString;
        helper(digits, subString, result, 0, chars);
        return result;
    }
    
    void helper(string &digits, string &subString, vector<string> &result, int depth, string chars[]){
        if(depth == digits.size()){
            result.push_back(subString);
            return;
        }
        int currDigit = digits[depth] - '0';
        for(int i = 0; i < chars[currDigit].size(); i++){
            subString.push_back(chars[currDigit][i]);
            helper(digits, subString, result, depth + 1, chars);
            subString.resize(subString.size() - 1);
        }
        return;
    }
};
