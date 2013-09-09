class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int finalSize = m + n;
        for(int i = m + n - 1; i >= 0 ; i--){
            if(n >= 1 && m >= 1 && A[m - 1] > B[n - 1]){
                A[i] = A[m - 1];
                m--;
                //continue;
            }    
            else if(n >= 1 && m >= 1 && A[m - 1] <= B[n - 1]){
                A[i] = B[n - 1];
                n--;
                //continue;
            }
            else if(m == 0 && n >= 1){
                A[i] = B[n - 1];
                n--;
                //continue;
            }
            else if(n == 0 && m >= 1){
                A[i] = A[m - 1];
                m--;
                //continue;
            }
        }
        return;
    }
};
