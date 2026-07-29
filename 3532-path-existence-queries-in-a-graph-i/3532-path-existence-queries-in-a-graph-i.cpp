class Solution {
private:
    void makeSet(vector<int> &parent,int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node, vector<int> &parent){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void makeUnion(int u, int v, vector<int> &parent,vector<int> &rank){
        u = findParent(u,parent);
        v = findParent(v,parent);

        if(rank[u]<rank[v]){
            parent[u] = v;
        }else if(rank[u]> rank[v]){
            parent[v] =u;
        }else {
            parent[u] = v;
            rank[v]++;
        }
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int> parent(n);
        makeSet(parent,n);
        vector<int> rank(n,0);

        vector<bool> res;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1]) <=maxDiff){
                makeUnion(i,i+1,parent,rank);
            }
        }

        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(findParent(u,parent)==findParent(v,parent))
                res.push_back(true);
            
            else res.push_back(false);
            
        }
        return res;

    }
};