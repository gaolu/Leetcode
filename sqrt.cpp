class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x <= 1)
            return x;
        int left = 0, right = x, mid;
        
        while(right - left > 1){
            mid = (left + right) / 2;
            if(mid == x / mid)
                return mid;
            else if(mid < x / mid)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};
