class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numOfRows = grid.size();
        if(numOfRows == 0) return 0;
        int numOfCols = grid[0].size();
        if(numOfCols == 0) return 0;
        vector<int> thisSum(numOfCols, INT_MAX);
        thisSum[0] = 0;
        for(int i = 0; i < numOfRows; i++){
            thisSum[0] += grid[i][0];
            for(int j = 1; j < numOfCols; j++){
                thisSum[j] = min(thisSum[j - 1], thisSum[j]) + grid[i][j];
            }
        }
        return thisSum[numOfCols - 1];
    }
};
