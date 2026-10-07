class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
        
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};
