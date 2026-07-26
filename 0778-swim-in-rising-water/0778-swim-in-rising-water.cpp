class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j, int n ,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));

        set<pair<int,pair<int,int>>> st;

        distance[0][0] = grid[0][0];
        int money = grid[0][0];
        st.insert({money,{0,0}});  // {money, {row,col}}


        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());
            int minCost = top.first;

            int row = top.second.first;
            int col = top.second.second;

            if(minCost > distance[row][col]){
                continue;
            }

            for(int k=0;k<4;k++){
                int r = row + x[k];
                int c = col + y[k];

                if(isValid(r,c,n,m)) {
                    int newMoney  = max(minCost, grid[r][c]);
                    if( newMoney < distance[r][c]){
                        auto record = st.find({newMoney,{r,c}});
                        if(record!=st.end()) st.erase(record);
                        distance[r][c] = newMoney;
                        st.insert({newMoney,{r,c}});

                    }
                }
                
            }
        }
        return distance[n-1][m-1];

    }
};