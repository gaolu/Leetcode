class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    vector<vector<char>> passIn(board);
                    bool result = recursiveSearch(passIn, i, j, word, 0);
                    if(result)
                        return true;
                }
            }
        }
        return false;
    }
    
    bool recursiveSearch(vector<vector<char>> &passIn, int i, int j, string &word, int index){
        if(index == word.size())
            return true;
        if(i < passIn.size() && j < passIn[i].size() && i >= 0 && j >= 0 && passIn[i][j] == word[index]){
            // mark as visited
            passIn[i][j] = '#';
            index++;
            return recursiveSearch(passIn, i - 1, j, word, index) |
                    recursiveSearch(passIn, i + 1, j, word, index) |
                    recursiveSearch(passIn, i, j - 1, word, index) |
                    recursiveSearch(passIn, i, j + 1, word, index);
        }
        return false;
    }
};