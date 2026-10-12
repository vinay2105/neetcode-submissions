class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        queue<pair<int, pair<int, int>>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) count++;
                else if(grid[i][j] == 2) q.push({0,{i,j}});
            }
        }

        int ans = 0;
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int time = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            ans = max(time, ans);

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({time+1,{nx,ny}});
                    count--;
                }
            }


        }

        if(count!=0) return -1;
        return ans;
        
    }
};
