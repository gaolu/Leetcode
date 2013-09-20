class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int m = matrix.size();
        if(m <= 0) return result;
        //if(m == 1) return matrix[0];
        int n = matrix[0].size();
        int numOfLayer = min(m, n) / 2;
        bool extra = min(m, n) % 2;
        int layer;
        for(layer = 0; layer < numOfLayer; layer++){
            int left = layer, right = n - 1 - layer, top = layer, bottom = m - 1 - layer;
            // push top
            for(int i = left; i < right; i++)
                result.push_back(matrix[top][i]);
            // push right
            for(int i = top; i < bottom; i++)
                result.push_back(matrix[i][right]);
            // push bottom
            for(int i = right; i > left; i--)
                result.push_back(matrix[bottom][i]);
            // push left
            for(int i = bottom; i > top; i--)
                result.push_back(matrix[i][left]);
            }
    	// insert the middle column
        if(extra && m > n){
            for(int i = numOfLayer; i <= m - 1 - numOfLayer; i++)
                result.push_back(matrix[i][numOfLayer]);
        }
        // insert the middle row
        if(extra && m < n){
            for(int i = numOfLayer; i <= n - 1 - numOfLayer; i++)
                result.push_back(matrix[numOfLayer][i]);
        }
        // insert the central element
        if(extra && m == n)
            result.push_back(matrix[numOfLayer][numOfLayer]);
        return result;
    }
};