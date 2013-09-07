class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return;
        int red = 0, white = 0, blue = n - 1;
        for( ; white <= blue; ){
            if(A[white] == 0)
                swap(A[red++], A[white++]); // the red can only be smaller
            else if(A[white] == 2)
                swap(A[blue--], A[white]);
            else
                white++;
        }
        return;
    }
};