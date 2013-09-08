class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 2)
            return n;
        int currCount = 1, slow = 0, fast;
        for(fast = 1; fast < n; fast++){
            if(A[slow] == A[fast]){
                if(currCount < 2){
                    currCount++;
                    A[++slow] = A[fast];
                }
            }
            else{
                currCount = 1;
                A[++slow] = A[fast];
            }
        }
        return slow + 1;
    }
};