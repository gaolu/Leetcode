class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numOfRows = word1.size();
        int numOfCols = word2.size();
        if(numOfRows == 0)
            return numOfCols;
        else if(numOfCols == 0)
            return numOfRows;
        int distance[numOfRows + 1][numOfCols + 1];
        for(int i = 0; i < numOfRows + 1; i++)
            distance[i][0] = i;
        for(int j = 0; j < numOfCols + 1; j++)
            distance[0][j] = j;
        
        for(int i = 1; i < numOfRows + 1; i++){
            char rowChar = word1[i - 1];
            for(int j = 1; j < numOfCols + 1; j++){
                char colChar = word2[j - 1];
                if(rowChar == colChar)
                    distance[i][j] = distance[i - 1][j - 1];
                else{
                    int change = distance[i - 1][j - 1] + 1;
                    int add = distance[i][j  -1] + 1;
                    int del = distance[i - 1][j] + 1;
                    distance[i][j] = min(change, min(add, del));
                }
            }
        }
        
        return distance[numOfRows][numOfCols];
    }
};