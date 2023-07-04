class Solution
{
public:
    int dp[305];
    set<string> st;

    bool solve(int idx, string &s)
    {
        if (idx == s.size())
        {
            return 1;
        }

        int &ans = dp[idx];
        if (ans != -1)
            return ans;

        for (int i = idx + 1; i <= s.size(); i++)
        {
            string temp = s.substr(idx, i - idx);
            if (st.find(temp) != st.end())
            {
                if (solve(i, s))
                    return ans = 1;
            }
        }
        return ans = 0;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(dp, -1, sizeof dp);
        for (auto x : wordDict)
        {
            st.insert(x);
        }
        return solve(0, s);
    }
};