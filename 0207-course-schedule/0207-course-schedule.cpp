class Solution {
    private:
    bool dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsCycle, unordered_map<int,vector<int>> &adj){
        visited[node]= true;
        dfsCycle[node] = true;

        for(auto nbr : adj[node]){
            if(visited[nbr] && dfsCycle[nbr]){
                return true;
            }else if(!visited[nbr]){
                bool ans = dfs(nbr,visited,dfsCycle,adj);
                if(ans) return true;
            }
        }
        dfsCycle[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsCycle;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
               bool res =  dfs(i,visited,dfsCycle,adj);
               if(res) return false;
            }
        }

    return true;
    }
};