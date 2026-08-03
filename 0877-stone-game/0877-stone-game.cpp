class Solution {
public:
    int dp[501][501][2];

    int rec(int p, int l, int r, vector<int>& piles) {

        if (l == r)
            return (p == 0 ? piles[l] : -piles[l]);

        if (dp[l][r][p] != INT_MIN)
            return dp[l][r][p];

        int sign = (p == 0 ? 1 : -1);

        int left = sign * piles[l] + rec(1 - p, l + 1, r, piles);
        int right = sign * piles[r] + rec(1 - p, l, r - 1, piles);

        if (p == 0)
            return dp[l][r][p] = max(left, right);

        return dp[l][r][p] = min(left, right);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        for (int i = 0; i <= 500; i++)
            for (int j = 0; j <= 500; j++)
                dp[i][j][0] = dp[i][j][1] = INT_MIN;

        return rec(0, 0, n - 1, piles) > 0;
    }
};