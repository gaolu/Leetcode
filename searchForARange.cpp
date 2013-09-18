class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(2, -1);
        int start = 0, end = n, mid;
        // search lower bound
        while(start < end){
            mid = (start + end) / 2;
            if(A[mid] < target) start = mid + 1;
            else end = mid;
        }
        if(A[start] != target) return result;
        result[0] = start;
        end = n;
        // search higher bound
        while(start < end){
            mid = (start + end) / 2;
            if(A[mid] > target) end = mid;
            else start = mid + 1;
        }
        result[1] = end - 1;
        return result;
    }
};
