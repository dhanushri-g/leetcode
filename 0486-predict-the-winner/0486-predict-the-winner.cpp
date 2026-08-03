class Solution {
public:
    int dp[21][21][2];

    int rec(int p, int l, int r, vector<int>& nums) {

        if (l == r) {
            return (p == 0 ? nums[l] : -nums[l]);
        }

        if (dp[l][r][p] != INT_MIN)
            return dp[l][r][p];

        int sign = (p == 0 ? 1 : -1);

        int left = sign * nums[l] + rec(1 - p, l + 1, r, nums);
        int right = sign * nums[r] + rec(1 - p, l, r - 1, nums);

        if (p == 0)
            return dp[l][r][p] = max(left, right);

        return dp[l][r][p] = min(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            dp[i][j][0] = dp[i][j][1] = INT_MIN;
        }
    }

    return rec(0, 0, n - 1, nums) >= 0;
}
};