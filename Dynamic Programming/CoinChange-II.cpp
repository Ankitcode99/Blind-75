/**
 * Number of ways to generate the sum of amount when we are allowed to same denomination multiple times
 */

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // vector<vector<int>> dp(coins.size(), vector<int> (amount+5,-1));
        if (amount == 0)
            return 1;
        int dp[coins.size()][amount + 5];
        memset(dp, 0, sizeof dp);

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < coins.size(); i++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int notPick = dp[i - 1][amt];
                int pick = 0;
                if (coins[i] <= amt)
                    pick = dp[i][amt - coins[i]];
                dp[i][amt] = pick + notPick;
            }
        }

        return dp[coins.size() - 1][amount];
    }
};