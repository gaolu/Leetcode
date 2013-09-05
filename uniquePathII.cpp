class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numOfRows = obstacleGrid.size();
        if(numOfRows == 0) return 0;
        int numOfCols = obstacleGrid[0].size();
        if(numOfCols == 0) return 0;
        int *prevRowNum = new int[numOfCols];
        int *thisRowNum = new int[numOfCols];
        
        // start from row 0
        prevRowNum[0] = 1 - obstacleGrid[0][0];
        for(int i = 1; i < numOfCols; i++)
            prevRowNum[i] = prevRowNum[i - 1] & (1 - obstacleGrid[0][i]);         
        // look at row 1 to numOfRows - 1
        for(int i = 1; i < numOfRows; i++){
            vector<int> &currRow = obstacleGrid[i];
            for(int j = 0; j < numOfCols; j++){
                if(currRow[j] == 1){
                    thisRowNum[j] = 0;
                    continue;
                }
                thisRowNum[j] = prevRowNum[j];
                if(j > 0)
                    thisRowNum[j] += thisRowNum[j - 1];
            }
            int *temp = prevRowNum;
            prevRowNum = thisRowNum;
            thisRowNum = temp;
        }
        return prevRowNum[numOfCols - 1];
    }
};

