class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res;

        for(int i = 0; i < n-2; i++) {
            vector<int> temp;

            for(int j = 0; j < n-2; j++) {

                int maxi = INT_MIN;

                // Traverse 3x3 submatrix
                for(int x = i; x < i+3; x++) {
                    for(int y = j; y < j+3; y++) {
                        maxi = max(maxi, grid[x][y]);
                    }
                }

                temp.push_back(maxi);
            }

            res.push_back(temp);
        }

        return res;
    }
};