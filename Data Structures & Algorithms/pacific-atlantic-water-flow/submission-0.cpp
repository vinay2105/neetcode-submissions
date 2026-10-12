class Solution {
private:
    void dfs(int x, int y, vector<vector<int>> &heights, vector<vector<bool>> &vis){
        vis[x][y] = true;

        int m = heights.size();
        int n = heights[0].size();

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n && heights[nx][ny] >= heights[x][y] && !vis[nx][ny]){
                dfs(nx,ny,heights,vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0) && !pacific[i][j]){
                    dfs(i,j,heights,pacific);
                }
                if((i==m-1 || j==n-1) && !atlantic[i][j]){
                    dfs(i,j,heights,atlantic);
                }
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
