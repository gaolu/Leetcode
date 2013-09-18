class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0) return false;
        if(x == 0) return true;
        int divisor = 1;
        // beware that the divisor could also overflow
        // so we have to make sure that the x overflows before divisor
        while(x / divisor >= 10){
            divisor *= 10;
        }
        while(x != 0){
            if(x / divisor != x % 10) return false;
            x = (x % divisor) / 10;
            divisor /= 100;
        }
        return true;
    }
};
