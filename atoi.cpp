class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long returnInt = 0;
        if(str == NULL) return (int)returnInt;
        char *runner = (char *) str;
        // get rid of preceding spaces
        while(*runner == ' ') runner++;
        bool isNegative;
        if(*runner == '-' || *runner == '+'){
            isNegative = *runner == '-' ? true : false;
            runner++;
        }
        if(*runner < '0' || *runner > '9') return (int)returnInt;
        int i = 0;
        while(*runner){
            i++;
            if(*runner < '0' || *runner > '9') break;
            if(i > 10)
                return isNegative ? INT_MIN : INT_MAX;
            returnInt = returnInt * 10 + (*runner - '0');
            runner++;
        }
        returnInt =  isNegative ? -returnInt : returnInt;
        if(returnInt == INT_MIN || returnInt == INT_MAX)
            return isNegative ? INT_MIN : INT_MAX;
        return (int)returnInt;
    }
};