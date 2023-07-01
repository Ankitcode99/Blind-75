class Solution
{
public:
    int countSetBits(int num)
    {
        int cnt = 0;
        for (int i = 0; i < 20; i++)
        {
            if (num & (1 << i))
            {
                cnt++;
            }
        }
        return cnt;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(countSetBits(i));
        }
        return ans;
    }
};