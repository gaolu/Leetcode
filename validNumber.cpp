class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // get rid of preceding 0s
        int dotCount = 0;
        while(*s == ' '){
            s++;
        }
        // first char must be a number
        if((*s < '0' || *s > '9') && *s != '-' && *s != '+' && *s != '.')
            return false;
        
        if(*s == '-' || *s == '+')
            s++;
        if(*s == '.'){
            s++;
            dotCount++;
        }
        if(*s == '.')
            return false;
        if((*s < '0' || *s > '9') && *s != '.')
            return false;
        if(*s < '0' || *s > '9')
            return false;
        
        while(*s >= '0' && *s <= '9'){
            s++;
        }
        if(*s == '\0')
            return true;
        else if(*s == '.'){
            if(dotCount >= 1)
                return false;
            s++;
            if(*s == 'e'){
                s++;
                if(*s == '\0')
                    return false;
                else if(*s == '-' || *s == '+')
                    s++;
            }
            while(*s >= '0' && *s <= '9'){
                s++;
            }
            if(*s == '\0')
                return true;
            if(*s == 'e'){
                s++;
                if(*s == '-' || *s == '+')
                    s++;
                else if(*s < '0' || *s > '9')
                    return false;
                while(*s >= '0' && *s <= '9')
                    s++;
                while(*s == ' ')
                    s++;
                return *s == '\0';
            }
            if(*s != ' ')
                return false;
            while(*s == ' ')
                s++;
            if(*s == '\0')
                return true;
            else
                return false;
        }
        else if(*s == ' '){
            while(*s == ' ')
                s++;
            if(*s == '\0')
                return true;
            else
                return false;
        }
        else if(*s == 'e'){
            s++;
            if(*s == '\0')
                return false;
            if(*s == '-' || *s == '+')
                s++;
            if(*s < '0' || *s > '9')
                return false;
            while(*s >= '0' && *s <= '9')
                s++;
            if(*s == '\0')
                return true;
            if(*s != ' ')
                return false;
            while(*s == ' ')
                s++;
            if(*s == '\0')
                return true;
            else
                return false;
        }
        else
            return false;
    }
};