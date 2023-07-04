class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> temp(n), prev(n);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 || j == n - 1)
                {
                    temp[j] = 1;
                }
                else
                {
                    int down = prev[j];
                    int right = temp[j + 1];
                    temp[j] = down + right;
                }
            }
            prev = temp;
        }
        return prev[0];
    }
};