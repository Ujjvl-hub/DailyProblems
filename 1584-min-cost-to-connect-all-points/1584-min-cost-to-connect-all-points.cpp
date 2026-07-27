class Solution {
private:
    int manhattanDistance(vector<vector<int>>& points,int p1,int p2){
        return abs(points[p1][0]-points[p2][0]) + abs(points[p1][1]-points[p2][1]) ;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;

        pq.push({0,0});
        vector<bool> visited(n,false);

        int cost=0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if(visited[node]) continue;
            visited[node]=true;
            cost+=wt;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int distance = manhattanDistance(points,node,i);
                    pq.push({distance,i});
                }
            }
        }
        return cost;
    }
};