class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // brute force just 2d array then record which cell zero
        // m+n 2 array record col and row respectively
        int numOfRows = matrix.size();
        if(numOfRows <= 0)
            return;
        int numOfCols = matrix[0].size();
        if(numOfCols <= 0)
            return;
        
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        
        for(int i = 0; i < numOfRows; i++){
            if(matrix[i][0] == 0)
                firstColHasZero = true;
        }
        for(int j = 0; j < numOfCols; j++){
            if(matrix[0][j] == 0)
                firstRowHasZero = true;
        }
        for(int i = 1; i < numOfRows; i++){
            for(int j = 1; j < numOfCols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < numOfRows; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < numOfCols; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j < numOfCols; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < numOfRows; i++)
                    matrix[i][j] = 0;
            }
        }
        if(firstRowHasZero){
            for(int j = 0; j < numOfCols; j++)
                matrix[0][j] = 0;
        }
        if(firstColHasZero){
            for(int i = 0; i < numOfRows; i++)
                matrix[i][0] = 0;
        }
        return;
    }
};