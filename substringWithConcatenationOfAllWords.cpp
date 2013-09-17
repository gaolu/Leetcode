class Solution {  
public:  
    vector<int> findSubstring(string S, vector<string> &L) {  
        map<string, int> need; // store the # of times we need a specific word
        vector<int> result;
        map<string, int> found; // store the # of times we found a specific word so far
        int numOfWords = L.size();
        if(numOfWords <= 0) return result;
        int wordSize = L[0].size();
        if(S.size() < numOfWords * wordSize) return result;
        for(int i = 0; i < numOfWords; i++){
            ++need[L[i]]; // get # of times we need each word in the list
        }
        for(int i = 0; i <= S.size() - numOfWords * wordSize; i++){
            found.clear(); // re-do the scanning
            int j;
            for(j = 0; j < numOfWords; j++){
                string subStr = S.substr(i + j * wordSize, wordSize); // get current substring and match with words
                if(need.find(subStr) == need.end()) break;
                ++found[subStr]; // found the needed word
                if(found[subStr] > need[subStr]) break;
            }
            if(j == numOfWords) result.push_back(i); // found and need matches
        } 
        return result;
    }  
};
