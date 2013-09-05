const int M_MAX = 100;
const int N_MAX = 100;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //return backTrack(1, 1, m, n);
        /*
        int matrix[M_MAX + 2][N_MAX + 2];
        for(int i = 0; i < M_MAX + 2; i++){
            for(int j = 0; j < N_MAX + 2; j++){
                matrix[i][j] = -1;
            }
        }
        return backTrackDP(1, 1, m, n, matrix);
        */
        int matrix[M_MAX + 2][N_MAX + 2] = {0};
        matrix[m][n + 1] = 1;
        for(int i = m; i >= 1; i--)
            for(int j = n; j >= 1; j--)
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
        return matrix[1][1];
    }
    
    int backTrack(int row, int column, int m, int n){
        if(row == m || column == n)
            return 1;
        if(row > m || column > n)
            return 0;
        return backTrack(row + 1, column, m, n) + backTrack(row, column + 1, m, n);
    }
    
    int backTrackDP(int row, int column, int m, int n, int matrix[][N_MAX + 2]){
        if(row == m || column == n)
            return 1;
        if(row > m || column > n)
            return 0;
        if(matrix[row + 1][column] == -1)
            matrix[row + 1][column] = backTrackDP(row + 1, column, m, n, matrix);
        if(matrix[row][column + 1] == -1)
            matrix[row][column + 1] = backTrackDP(row, column + 1, m, n, matrix);
        return matrix[row + 1][column] + matrix[row][column + 1];
    }
};
