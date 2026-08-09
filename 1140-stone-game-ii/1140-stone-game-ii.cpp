class Solution {
public:
    int n;
    int dp[2][101][101];
    int solveForAlice(vector<int>& piles, int person, int idx, int M){
        if(idx>=n) return 0;

        if(dp[person][idx][M]!=-1) return dp[person][idx][M];
        int res = (person==1)?-1:INT_MAX;
        int stones = 0;
        for(int x = 1; x<=min(2*M,n-idx);x++){
            stones+=piles[idx+x-1];
            if(person==1){
                res = max(res,stones+(solveForAlice(piles,0,idx+x, max(M, x))));
            }else{
                res = min(res,solveForAlice(piles,1,idx+x,max(M,x)));
            }
        }
        return dp[person][idx][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(dp,-1,sizeof(dp));
        return solveForAlice(piles,1,0,1);   // 1 = alice , 0 = starting index, 1 = value of M

    }
};