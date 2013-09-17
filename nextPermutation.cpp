class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // from right to left find the digit that is not ascending
        // from right to left find the first digit larger than the above one
        // swap the two
        // reverse the order from the right of the first digit to the end
        if(num.size() <= 0) return;
        int n = num.size();
        int left;
        int i;
        for(i = n - 1; i >= 1; i--){
            if(num[i - 1] < num[i]) break;
        }
        // decending order reverse it to ascending
        if(i == 0){
            reverse(num.begin(), num.end());
            return;
        }
        left = i - 1;
        int right;
        int j;
        for(j = n - 1; j > left; j--){
            if(num[left] < num[j]) break;
        }
        right = j;
        swap(num[left], num[right]);
        reverse(num.begin() + i, num.end());
    }
};
