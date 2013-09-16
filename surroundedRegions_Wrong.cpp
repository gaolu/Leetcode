class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size() == 0) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                char current = board[i][j];
                if(current == 'X') continue;
                // get an 'O'
                if(leftX(board, i, j) && rightX(board, i, j, n) && upX(board, i, j) && downX(board, i, j, m))
                    current = 'X';
            }
        }
    }
    
    bool leftX(vector<vector<char>> &board, int &i, int &j){
        if(board[i][j] == 'X') return true;
        if(j > 0) return leftX(board, i, j - 1);
        else return board[i][j] == 'X';
    }
    bool rightX(vector<vector<char>> &board, int &i, int &j, int &n){
        if(board[i][j] == 'X') return true;
        if(j < n - 1) return rightX(board, i, j + 1, n);
        else return board[i][j] == 'X';
    }
    bool upX(vector<vector<char>> &board, int &i, int &j){
        if(board[i][j] == 'X') return true;
        if(i > 0) return upX(board, i - 1, j);
        else return board[i][j] == 'X';
    }
    bool downX(vector<vector<char>> &board, int &i, int &j, int &m){
        if(board[i][j] == 'X') return true;
        if(i < m - 1) return downX(board, i + 1, j, m);
        else return board[i][j] == 'X';
    }
};
