class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        for(int layer = 0; layer < n / 2; layer++){
            int first = layer;
            int last = n - 1 - layer;
            for(int i = first; i < last; i++){
                int offset = i - first;
                // save top row
                int temp = matrix[first][i];
                // left to top
                matrix[first][i] = matrix[last - offset][first];
                // bottom to left
                matrix[last - offset][first] = matrix[last][last - offset];
                // right to bottom
                matrix[last][last - offset] = matrix[i][last];
                // top to right
                matrix[i][last] = temp;
            }
        }
    }
};