class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!*s && !*p) return true;
        // we need an 2-d array 1 bigger in two dimensions, respectively
        int numS = 1, numP = 1;
        const char *sRunner = s;
        // count # of chars in s
        while(*sRunner){
            ++numS;
            ++sRunner;
        }
        const char *pRunner = p;
        // skip *s
        while(*pRunner){
            if(*pRunner != '*')
                ++numP;
            ++pRunner;
        }
        if(numS < numP) return false;
        // we just need the 2-d vector to have 2 rows b/c we only read the upper one
        vector<vector<bool>> table(2, vector<bool>(numS, false));
        table[0][0] = true;
        bool flag = 1;
        do{
            // initialize to the beginning of string s
            int column = 1;
            sRunner = s;
            // if p == *, then the cell will be true if any one of the cells left and one row above it is true
            if(*p == '*'){
                while(*p == '*') ++p;
                --p;
                // the first one equals to the one above it
                table[flag][0] = table[!flag][0];
                for( ; column <= numS; column++){
                    // search the up and left, break and write the whole row to true after found a true
                    if(table[!flag][column] || table[flag][column - 1]) break;
                    else table[flag][column] = false;
                }
                // write the cells to the right of * to be all true
                for( ; column <= numS; column++) table[flag][column] = true;
            }
            // not * equal to its up & left diagonal
            else{
                do{
                    bool diagonal = false;
                    if(*sRunner == *p || *p == '?') diagonal = table[!flag][column - 1];
                    table[flag][column] = diagonal;
                    ++column;
                    ++sRunner;
                }while(*sRunner);
                table[flag][0] = false;
            }
            ++p;
            flag = !flag;
        }while(*p);
        return table[!flag][numS - 1];
    }
};
