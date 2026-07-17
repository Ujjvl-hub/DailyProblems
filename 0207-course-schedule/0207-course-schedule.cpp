class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);

        }
        vector<int> indegree(numCourses,0);
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        int count=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            for(auto i: adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }

        }
       if(count==numCourses) return true;
       else return false;
        
    }
};