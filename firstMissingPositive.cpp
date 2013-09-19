class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0) return 1;
        // neglect all non-positive values
        for(int i = 0; i < n; i++){
            if(A[i] <= 0) A[i] = n + 2; // A[i] not possible
        }
        // if A[i] is in [1, n], then set A[A[i] - 1] to its negative value
        // others remain positive
        // so we could return the first non-negative value + 1 as the first missing
        for(int i = 0; i < n; i++){
            int ai = A[i];
            int absi = abs(ai);
            if(absi <= n)
                A[absi - 1] = -abs(A[absi - 1]);
        }
        for(int i = 0; i < n; i++){
            if(A[i] > 0) return i + 1;
        }
        return n + 1;
    }
};