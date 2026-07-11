class Solution {
    void dfs(int node,unordered_map<int,bool>& visited,unordered_map<int,vector<int>>& adj,
    int &nodes, int &degreeSum){
        visited[node]= true;
        nodes++;
        degreeSum+=adj[node].size();
        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i,visited,adj,nodes,degreeSum);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        int ans =0;

        int nodes=0;
        int degreeSum=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                nodes =0;
                degreeSum=0;
                dfs(i,visited,adj,nodes,degreeSum);
                int actualEdges = degreeSum/2;
                int requiredEdges = nodes*(nodes-1)/2;

                if(actualEdges==requiredEdges) ans++;
            }
        }
        return ans;
    }
};