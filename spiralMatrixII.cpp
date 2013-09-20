class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result(n, vector<int>(n));
        if(n == 0) return result;
        int start = 0, end = n - 1;
        int num = 1;
        while(start < end){
            // write top
            for(int i = start; i < end; i++){
                result[start][i] = num;
                num++;
            }
            // write right
            for(int i = start; i < end; i++){
                result[i][end] = num;
                num++;
            }
            // write bottom
            for(int i = end; i > start; i--){
                result[end][i] = num;
                num++;
            }
            // write left
            for(int i = end; i > start; i--){
                result[i][start] = num;
                num++;
            }
            start++;
            end--;
        }
        // odd # of rows/columns
        if(start == end) result[start][start] = num;
        return result;
    }
};