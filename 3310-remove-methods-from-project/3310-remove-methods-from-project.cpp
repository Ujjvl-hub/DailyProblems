class Solution {
private:
    void dfs(int node, vector<bool> &visited,vector<vector<int>>& adj){
        visited[node] = true;

        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i,visited,adj);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
           vector<vector<int>> adj(n);
           for(int i=0;i<invocations.size();i++){
                int u= invocations[i][0];
                int v = invocations[i][1];

                adj[u].push_back(v);
           }

           vector<bool> visited(n,false);
            dfs(k,visited,adj);


            // rest logic
            bool canRemove = true;
            for(int u=0;u<n;u++){
                for(auto v: adj[u]){
                    if(!visited[u] && visited[v]) {
                        canRemove = false;
                        break;
                    }
                }
                if(!canRemove) break;
            }

            vector<int> res;
            if(!canRemove){
                for(int i=0;i<n;i++){
                    res.push_back(i);
                }
            }else{
                for(int i=0;i<n;i++){
                    if(!visited[i]){
                        res.push_back(i);
                    }
                }
            }
          
           return res;
    }
};