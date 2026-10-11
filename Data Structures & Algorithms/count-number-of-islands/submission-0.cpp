class Solution {
private:
    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[x][y] = true;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && grid[nx][ny] == '1'){
                dfs(nx, ny, grid, vis);
            }
        }


    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
        
    }
};
