class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int sz = nums.size();

        vector<int> dp(sz, 1);
        int mx = 1;
        cout << dp[0] << " ";
        for (int i = 1; i < sz; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
            cout << dp[i] << " ";
        }
        return mx;
    }
};