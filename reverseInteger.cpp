class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(abs(x) <= 9) return x;
        int division = x / 10;
        int afterReverse = 0;
        bool isNegative = x < 0 ? true : false;
        x = abs(x);
        while(division != 0){
            int mod = x % 10;
            afterReverse = afterReverse * 10 + mod;
            x /= 10;
            division = x;
        }
        return isNegative ? -afterReverse : afterReverse;
    }
};