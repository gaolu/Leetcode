class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> charLocation;
        // initialize to be unvisited
        for(int i = 0; i < s.size(); i++){
            charLocation[s[i]] = -1;
        }
        
        int maxLen = 0;
        int currLen = 0;
        for(int i = 0; i < s.size(); i++){
            // unvisited
            if(charLocation[s[i]] < 0){
                currLen++;
                charLocation[s[i]] = i; // mark as visited 
                if(currLen > maxLen) maxLen = currLen;
            }
            else{
                int prevLen = currLen; // backup
                currLen = i - charLocation[s[i]];
                // change the chars before the first copy of duplicates to unvisited
                for(int j = i - prevLen; j < charLocation[s[i]]; j++){
                    charLocation[s[j]] = -1;
                }
                charLocation[s[i]] = i;
            }
        }
        return maxLen;
    }
};