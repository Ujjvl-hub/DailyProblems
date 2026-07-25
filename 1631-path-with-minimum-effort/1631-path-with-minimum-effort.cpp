class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j,int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        res[0][0] = 0;

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});

        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());

            int distance = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if(distance> res[row][col]) continue;

            for(int k=0;k<4;k++){
                int r = row + x[k];
                int c = col + y[k];
                
                if(!isValid(r,c,n,m)) continue;

                int diff = abs(heights[row][col]-heights[r][c]);
                int newWt = max(distance, diff);

                if(newWt < res[r][c]){
                    auto record = st.find({res[r][c], {r, c}});
                    if(record!=st.end()) st.erase(record);
                    res[r][c] = newWt;
                    st.insert({newWt,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};