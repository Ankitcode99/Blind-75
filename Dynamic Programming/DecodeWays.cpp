class Solution
{
public:
    int dp[105];

    int solve(int idx, string s)
    {
        if (idx == s.size())
            return 1;

        int &ans = dp[idx];
        if (ans != -1)
        {
            return ans;
        }

        if (s[idx] - '0' == 0)
            return ans = 0;

        if (s[idx] - '0')
            ans = solve(idx + 1, s);
        if (idx + 1 < s.size() and ((s[idx] - '0') * 10 + (s[idx + 1] - '0')) <= 26)
            ans += solve(idx + 2, s);

        return ans;
    }

    int numDecodings(string s)
    {
        memset(dp, -1, sizeof dp);
        return solve(0, s);
    }
};