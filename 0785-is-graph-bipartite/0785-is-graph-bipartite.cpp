class Solution {
    private:
    bool dfs(int node, int c , vector<int> &color, vector<vector<int>>& graph){
        color[node] = c;

        for(auto i: graph[node]){
            if(color[i]==-1){   // 1-c make 0 and 1 after every switch
                if(!dfs(i,1-c,color,graph))  
                    return false;
            }
            else if(color[i]!=-1 && color[i]==c) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph))
                    return false;
            }
        }
        return true;
    }
};