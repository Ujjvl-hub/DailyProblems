class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        dp[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});
        
        while(!pq.empty()){
            auto [cost, time, node] = pq.top();
            pq.pop();

            if (node == n - 1) return cost;

            if (cost > dp[node][time]) continue;

            for (auto [v, wt] : adj[node]) {
                int newTime = time + wt;
                int newCost = cost + passingFees[v];

                if (newTime <= maxTime &&
                    newCost < dp[v][newTime]) {

                    dp[v][newTime] = newCost;
                    pq.push({newCost, newTime, v});
                }
            }
        }
        return -1;
    }
};