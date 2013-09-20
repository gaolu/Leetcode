class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // sum is used to decide whether to start over or continue
        int result = A[0], sum = A[0];
        for(int i = 1; i < n; i++){
            sum = max(sum + A[i], A[i]);
            result = max(result, sum);
        }
        return result;
    }
};