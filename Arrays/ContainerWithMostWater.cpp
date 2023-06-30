class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        /**
            The idea is pretty simple, since we need 2 lines to act as boundary let's  greedily choose the terminal lines
            and then level of water will be same as the height of the min of 2 (otherwise we consider water spill on the
            shorter bar side)
        */
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                ans = max(ans, height[left] * (right - left));
                left += 1;
            }
            else
            {
                ans = max(ans, height[right] * (right - left));
                right -= 1;
            }
        }
        return ans;
    }
};