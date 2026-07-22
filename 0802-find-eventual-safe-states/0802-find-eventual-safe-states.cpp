class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);

        // reverse graph 
        for(int u =0; u<n;u++){
            for(auto v: graph[u]){
                revAdj[v].push_back(u);
            }
        }

        unordered_map<int,int> indegree(n);
        for(auto i: revAdj){
            for(int j: i){
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> res;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            res.push_back(front);

            for(auto i: revAdj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
       sort(res.begin(),res.end());
        return res;
    }
};