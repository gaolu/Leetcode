class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Catalan number count = (2n)! / ((n+1)! * n!)
        int count = 1;
        for(int i = 2; i <= n ; i++)
            count = count * 2 * (2 * i - 1) / (i + 1); // follow the formular above
        return count;
    }
};


