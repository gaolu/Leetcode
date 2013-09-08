class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string miniWindow = "";
        int sLen = S.length();
        int tLen = T.length();
        int needToFind[256] = {0};
        for(int i = 0; i < tLen; i++){
            needToFind[T[i]]++;
        }
        int hasFound[256] = {0};
        int minWindow = INT_MAX;
        int count = 0;
        int begin = 0, end = 0;
        for( ; end < sLen; end++){
            // skip preceding non-T chars
            if(needToFind[S[end]] == 0)
                continue;
            hasFound[S[end]]++;
            if(hasFound[S[end]] <= needToFind[S[end]])
                count++;
            // got a window    
            if(count == tLen){
                while(needToFind[S[begin]] == 0 || needToFind[S[begin]] < hasFound[S[begin]]){
                    if(needToFind[S[begin]] < hasFound[S[begin]])
                        hasFound[S[begin]]--;
                    begin++;
                }
                // update min window length
                int windowLength = end - begin + 1;
                if(windowLength < minWindow){
                    minWindow = windowLength;
                    miniWindow = S.substr(begin, minWindow);
                }
            }
        }
        return miniWindow;
    }
};