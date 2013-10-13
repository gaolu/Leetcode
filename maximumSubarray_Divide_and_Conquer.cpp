class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return maxSub(A, 0, n - 1);
    }
    
    int maxSub(int A[], int left, int right){
        if(left > right) return INT_MIN;
        if(left == right) return A[left];
        int mid = (left + right) / 2;
        int currSum = 0, leftMax = INT_MIN, rightMax = INT_MIN;
        for(int i = mid - 1; i >= left; i--){
            currSum += A[i];
            leftMax = max(leftMax, currSum);
        }
        for(int i = mid + 1, currSum = 0; i <= right; i++){
            currSum += A[i];
            rightMax = max(rightMax, currSum);
        }
        int midMax = A[mid] + max(leftMax, 0) + max(rightMax, 0);
        return max(midMax, max(maxSub(A, left, mid - 1), maxSub(A, mid + 1, right)));
    }
};