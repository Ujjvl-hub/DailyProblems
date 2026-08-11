class Solution {
private:
    void makeParent(vector<int> &parent, int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(vector<int> &parent, int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent,parent[node]);
    }

    void Union(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent,u);
        v = findParent(parent,v);

        if(rank[u]<rank[v]){
            parent[u] = v;
        }else if(rank[u]> rank[v]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> parent(n);
        makeParent(parent,n);

        vector<int> rank(n,0);
        int count=n;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    int u = i;
                    int v = j;

                    if(findParent(parent,u)!=findParent(parent,v)){
                        Union(u,v,parent,rank);
                        count--;
                    }
                }

            }
        }
        return count;
    }
};