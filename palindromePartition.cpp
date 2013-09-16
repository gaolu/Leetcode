class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> result;
        vector<string> subStrings;
        DFS(s, 0, subStrings, result);
        return result;
    }
    
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void DFS(string s, int start, vector<string> &subStrings, vector<vector<string>> &result){
        if(start == s.size()){
            result.push_back(subStrings);
            return;
        }
        
        for(int i = start + 1; i <= s.size(); i++){
            if(isPalindrome(s, start, i - 1)){
                subStrings.push_back(s.substr(start, i - start));
                DFS(s, i, subStrings, result);
                subStrings.resize(subStrings.size() - 1);
            }
        }
        return;
    }
};
