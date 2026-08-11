class Solution {
private:
    bool isCycle(int node, vector<bool> &visited,vector<bool> &dfsCycle, vector<vector<int>> &adj){
        visited[node] = true;
        dfsCycle[node] = true;

        for(auto i: adj[node]){
            if(visited[i] && dfsCycle[i]) return true;
            else if(!visited[i]){
                bool res = isCycle(i,visited,dfsCycle,adj);
                if(res) return true;
            }
        }
        dfsCycle[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> dfsCycle(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool res = isCycle(i,visited,dfsCycle,adj);
                if(res) return false;
            }
        }
        return true;
    }
};