class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0) return -1;
        if(target < A[0]) return 0;
        if(target > A[n - 1]) return n;
        int start = 0, end = n, mid;
        while(start <= end){
            mid = (start + end) / 2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return end + 1;
    }
};
