class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 1.0;
        // recursive log(n) complexity
        double half = pow(x, n / 2);
        if(n % 2 == 0) return half * half;
        else if(n > 0) return half * half * x;
        else return half * half / x;    
    }
};