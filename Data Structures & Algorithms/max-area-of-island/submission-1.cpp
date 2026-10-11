class Solution {
private:
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &area){
        vis[x][y] = true;
        area = area + 1;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && grid[nx][ny]){
                dfs(nx, ny, grid, vis, area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = 0;

                    dfs(i,j,grid,vis,area);

                    ans = max(area, ans);
                }
            }
        } 
        return ans;
    }
};
