// Houses are arranged in circular fashion

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp1(nums.size() + 1, 0), dp2(nums.size() + 1, 0);
        dp1[0] = nums[0];
        dp2[1] = nums[1];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int pick = nums[i], leave = 0;
            if (i - 1 >= 0)
            {
                leave += dp1[i - 1];
            }
            if (i - 2 >= 0)
            {
                pick += dp1[i - 2];
            }
            dp1[i] = max(pick, leave);
        }

        for (int i = 2; i < nums.size(); i++)
        {
            int pick = nums[i], leave = 0;
            if (i - 1 >= 1)
            {
                leave += dp2[i - 1];
            }
            if (i - 2 >= 1)
            {
                pick += dp2[i - 2];
            }
            dp2[i] = max(leave, pick);
        }

        return max(dp1[nums.size() - 2], dp2[nums.size() - 1]);
    }
};