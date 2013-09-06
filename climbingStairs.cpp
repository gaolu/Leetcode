class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        else if(n == 1)
            return 1;
        else if(n > 1)
            return climbStairs(n - 1) + climbStairs(n - 2);
        else
            return -1;
    }
    
    
    int climbStairsII(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || n == 1)
            return 1;
        vector<int> s(n, 0);
        s[0] = 1;
        s[1] = 1;
        for(int i = 2; i < n; i++)
            s[i] = s[i - 1] + s[i - 2];
        return s[n - 1] + s[n - 2];
    }

    
};
