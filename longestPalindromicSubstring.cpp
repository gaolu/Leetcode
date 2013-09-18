class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() <= 1) return s;
        string subString = "";
        int i;
        // case 1, centered at a particular character
        for(i = 1; i < s.size(); i++){
            int j = i - 1, m = i + 1;
            while(j >= 0 && m <= s.size() - 1){
                if(s[j] != s[m]) break;
                j--;
                m++;
            }
            if(subString.size() < m - j - 1)
                subString = s.substr(j + 1, m - j - 1);
        }
        
        // case 2, centered in the middle of two chars
        for(i = 0; i < s.size() - 1; i++){
            if(s[i] != s[i + 1]) continue;
            int j = i - 1, m = i + 2;
            while(j >= 0 && m <= s.size() - 1){
                if(s[j] != s[m]) break;
                j--;
                m++;
            }
            if(subString.size() < m - j - 1)
                subString = s.substr(j + 1, m - j - 1);
        }
        return subString;
    }
};