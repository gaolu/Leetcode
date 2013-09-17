class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long result = 0;
        long long divd = abs((double)dividend);
        long long divs = abs((double)divisor);
        while(divd >= divs){
            long long newDivs = divs;
            for(int i = 0; divd >= newDivs; i++, newDivs <<= 1){
                divd -= newDivs;
                result += 1 << i;
            }
        }
        return (dividend ^ divisor) >> 31 ? (-result) : result;
    }
};
