class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 1) return A[0];
        for(int i = 1; i < n; i++){
            A[0] ^= A[i];
        }
        return A[0];
    }
};