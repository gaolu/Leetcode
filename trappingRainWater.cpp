class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!A || !n) return 0;
        int *leftHigh = new int[n];
        int leftPeak = A[0];
        leftHigh[0] = 0;
        // find the highest bar to the left of each bar
        for(int i = 1; i < n; i++){
            leftHigh[i] = leftPeak;
            leftPeak = max(leftPeak, A[i]);
        }
        int trapWater = 0;
        int rightPeak = A[n - 1];
        // start from right, got right peak and calculate the water trapped
        for(int i = n - 2; i > 0; i--){
            int height = min(leftHigh[i], rightPeak);
            if(height > A[i]) trapWater += height - A[i];
            if(A[i] > rightPeak) rightPeak = A[i];
        }
        return trapWater;
    }
};
