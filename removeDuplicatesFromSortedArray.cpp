class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1) return n;
        int arrayLength = 0, runner = 1;
        while(runner < n){
            while(A[arrayLength] == A[runner] && runner < n) runner++;
            A[++arrayLength] = A[runner];
        }
        return arrayLength;
    }
};
