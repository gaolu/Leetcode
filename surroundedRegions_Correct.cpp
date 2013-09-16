class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O') BFS(board, 0, i);
        }
        for(int j = 1; j < m; j++){
            if(board[j][n - 1] == 'O') BFS(board, j, n - 1);
        }
        for(int i = 0; i < n - 1; i++){
            if(board[m - 1][i] == 'O') BFS(board, m - 1, i);
        }
        for(int j = 1; j < m - 1; j++){
            if(board[j][0] == 'O') BFS(board, j, 0);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    
    void BFS(vector<vector<char>> &board, int row, int col){
        board[row][col] = '#';
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i - 1 >= 0 && board[i - 1][j] == 'O'){
                board[i - 1][j] = '#';
                q.push(make_pair(i - 1, j));
            }
            if(i + 1 < board.size() && board[i + 1][j] == 'O'){
                board[i + 1][j] = '#';
                q.push(make_pair(i + 1, j));
            }
            if(j - 1 >= 0 && board[i][j - 1] == 'O'){
                board[i][j - 1] = '#';
                q.push(make_pair(i, j - 1));
            }
            if(j + 1 < board[0].size() && board[i][j + 1] == 'O'){
                board[i][j + 1] = '#';
                q.push(make_pair(i, j + 1));
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        if (i - 1 >= 0 && board[i-1][j] == 'O')
            DFS(board, i - 1, j);
        if (j + 1 < board[0].size() && board[i][j+1] == 'O')
            DFS(board, i, j + 1);
        if (i + 1 < board.size() && board[i+1][j] == 'O')
            DFS(board, i + 1, j);
        if (j - 1 >= 0 && board[i][j-1] == 'O')
            DFS(board, i, j - 1);
    }
};
