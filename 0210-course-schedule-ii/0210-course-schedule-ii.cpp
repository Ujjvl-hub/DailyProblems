class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses,0);

        for(auto i: adj){
            for(int j : i){
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;    
        while(!q.empty()){
            int front  = q.front();
            q.pop();
            res.push_back(front);

            for(auto i: adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        if(res.size()==numCourses) return res;
        return {};
    }
};