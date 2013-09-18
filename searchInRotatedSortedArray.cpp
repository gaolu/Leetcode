class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0, end = n - 1, mid = (start + end) / 2;
        while(start <= end){
            mid = (start + end) / 2;
            if(A[mid] == target) return mid;
            else{
                // left half is sorted
                if(A[start] <= A[mid]){
                    if(target >= A[start] && target < A[mid])
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
                // right halft is sorted
                else{
                    if(target > A[mid] && target <= A[end])
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
        return -1;
    }
};
