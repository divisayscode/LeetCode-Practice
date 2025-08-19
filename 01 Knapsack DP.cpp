class Solution {
public:
    int dp[1002][1002];

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        memset(dp, -1, sizeof(dp));
        return solve(W, val, wt, n);
    }

private:
    int solve(int W, vector<int> &val, vector<int> &wt, int n) {
        if(n == 0 || W == 0) return 0;
        if(dp[n][W] != -1) return dp[n][W];

        if(wt[n-1] <= W) {
            return dp[n][W] = max(
                val[n-1] + solve(W - wt[n-1], val, wt, n-1),
                solve(W, val, wt, n-1)
            );
        } else {
            return dp[n][W] = solve(W, val, wt, n-1);
        }
    }
};
