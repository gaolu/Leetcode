class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if((m + n) % 2) return findKthSorted(A, m, B, n, (m + n) / 2 + 1);
        else return (findKthSorted(A, m, B, n, (m + n) / 2) + findKthSorted(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
    }
    // find the kth element in two sorted arrays
    int findKthSorted(int A[], int m, int B[], int n, int k){
        assert(A && B);
        if(m <= 0) return B[k - 1];
        if(n <= 0) return A[k - 1];
        if(k <= 1) return min(A[0], B[0]);
        // A is too big
        if(A[m / 2] >= B[n / 2]){
            // if k is below half way then the current median is too big so drop the bigger's right
            if(m / 2 + n / 2 + 1  >= k) return findKthSorted(A, m / 2, B, n, k);
            // else drop smaller's left
            else return findKthSorted(A, m, B + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
        }
        // B is too big
        else{
            // if k is below half way then the current median is too big so drop the bigger's right 
            if(m / 2 + n / 2 + 1 >= k) return findKthSorted(A, m, B, n / 2, k);
            // else drop smaller's left
            else return findKthSorted(A + m / 2 + 1, m - (m / 2 + 1), B, n, k - (m / 2 + 1));
        }
    }
};