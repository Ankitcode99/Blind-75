class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (!nums.size())
            return 0;

        int mx = 1, mn = 1, ans = INT_MIN;
        for (int x : nums)
        {
            if (x < 0)
            {
                swap(mn, mx);
            }
            mn = min(mn * x, x);
            mx = max(mx * x, x);
            ans = max(ans, mx);
        }
        return ans;
    }
};