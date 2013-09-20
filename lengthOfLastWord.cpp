class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = 0, lastLength = 0;
        while(*s){
            if(*s == ' '){
                length = 0;
                s++;
                continue;
            }
            while(*s != ' ' && *s){
                length++;
                s++;
            }
            lastLength = length;
        }
        return lastLength;
    }
};
