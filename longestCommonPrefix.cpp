class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string prefix = "";
        if(strs.size() <= 0) return prefix;
        if(strs.size() == 1) return strs[0];
        int numString = strs.size();
        // find the shortest string
        // good for the situation that strs sizes vary a lot
        string shortestString = strs[0];
        int shortestIndex = 0;
        for(int i = 0; i < numString; i++){
            if(strs[i].size() < shortestString.size()){
                shortestString = strs[i];
                shortestIndex = i;
            }
        }
        int length = shortestString.size();
        for(int i = 0; i < length; i++){
            for(int j = 0; j < numString; j++){
                if(strs[shortestIndex][i] != strs[j][i]) return shortestString.substr(0, i);
            }
        }
        return shortestString;
    }
};
