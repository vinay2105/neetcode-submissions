class Solution {
private:
    void dfs(int x, int y, vector<vector<char>> &board){
        board[x][y] = '1';

        int m = board.size();
        int n = board[0].size();

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && ny >=0 && nx < m && ny < n && board[nx][ny] == 'O'){
                dfs(nx,ny, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((board[i][j]=='O') && (i==0 || i==m-1 || j == 0 || j==n-1)){
                    dfs(i,j,board);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        

        
    }
};
