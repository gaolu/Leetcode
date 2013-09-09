class Solution {
    int f[200][200];
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0)
            return 0;
        // initialize the first column
        for(int i = 0; i < matrix.size(); i++){
            f[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        // calculate max len every cell
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                f[i][j] = matrix[i][j] == '1' ? f[i][j - 1] + 1 : 0;
            }
        }
        int maxArea = 0;
        // calcualte the max area for each cell
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int lineNum = i;
                int width = INT_MAX;
                while(lineNum >= 0){
                    if(f[lineNum][j] == 0)
                        break;
                    width = min(width, f[lineNum][j]);
                    maxArea = max(maxArea, width * (i - lineNum + 1));
                    lineNum--;
                }
            }
        }
        return maxArea;
    }
};