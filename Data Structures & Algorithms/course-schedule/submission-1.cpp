class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i=0;i<p.size();i++){
            int u = p[i][1];
            int v = p[i][0];
            indegree[v]++;

            adj[u].push_back(v);
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;

        
    }
};
