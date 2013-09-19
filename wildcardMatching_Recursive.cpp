class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // if *, find the first non-* char and do the compare
        // if not match when s reach end, return false
        if(*p == '*'){
            while(*p == '*') ++p;
            if(*p == '\0') return true;
            while(*s != '\0' && !isMatch(s, p)) ++s;
            return *s != '\0'; // if not match in the end return false
        }
        else if(*p == '\0' || *s == '\0') return *p == *s;
        else if(*p == *s || *p == '?') return isMatch(++s, ++p);
        else return false;
    }
};
