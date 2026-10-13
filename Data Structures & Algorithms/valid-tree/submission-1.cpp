class Solution {
private:
    bool dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;

        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                if(!dfs(nbr, node, vis, adj)) return false;
            }
            else if(nbr != parent){
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][0];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                if(!dfs(i, -1, vis, adj)) return false;
            }
        }
        if(count > 1) return false;
        return true;

    }
};
