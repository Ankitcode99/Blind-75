class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSubArraySum = INT_MIN;
        int runningSum = 0;
        for (int num : nums)
        {
            runningSum += num;
            maxSubArraySum = max(maxSubArraySum, runningSum);
            if (runningSum < 0)
                runningSum = 0;
        }
        return maxSubArraySum;
    }
};