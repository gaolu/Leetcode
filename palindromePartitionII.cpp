class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() <= 1) return 0;
        vector<int> cutNumber(s.size() + 1);
        vector<vector<bool>> isPalindrome(s.size() + 1, vector<bool>(s.size() + 1, false));
        for(int i = 0; i <= s.size(); i++){
            cutNumber[i] = s.size() - i;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                    cutNumber[i] = min(cutNumber[i], cutNumber[j + 1] + 1);
                }
            }
        }
        return cutNumber[0] - 1;
    }
};
