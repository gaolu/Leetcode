class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!*needle) return haystack;
        //if(strlen(haystack) < strlen(needle)) return NULL;
        char *p1 = haystack;
        while(*p1){
            // used to restore
            char *p1Original = p1;
            char *p2 = needle;
            while(*p1 && *p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(!*p2) return p1Original;
            p1 = p1Original + 1;
        }
        return NULL;
    }
};
