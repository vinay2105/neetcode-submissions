class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int INF = INT_MAX;
        queue<pair<int, pair<int, int>>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int dist = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx < m && ny < n && grid[nx][ny] == INF){
                    grid[nx][ny] = dist+1;
                    q.push({dist+1, {nx,ny}});
                }
            }

        }
        
    }
};
