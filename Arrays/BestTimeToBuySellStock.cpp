class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int miniPrice = prices[0], maxProfit = 0;
        for (int idx = 1; idx < prices.size(); idx++)
        {
            if (prices[idx] < miniPrice)
            {
                miniPrice = prices[idx];
            }
            else
            {
                maxProfit = max(maxProfit, prices[idx] - miniPrice);
            }
        }
        return maxProfit;
    }
};