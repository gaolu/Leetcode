class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i < n; ){
            if(A[i] == elem)
                A[i] = A[--n];
            else
                i++;
        }
        return n;
    }
};
