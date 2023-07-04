class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size() + 1, 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i], leave = 0;
            if (i - 1 >= 0)
            {
                leave += dp[i - 1];
            }
            if (i - 2 >= 0)
            {
                pick += dp[i - 2];
            }
            dp[i] = max(pick, leave);
        }
        return dp[nums.size() - 1];
    }
};