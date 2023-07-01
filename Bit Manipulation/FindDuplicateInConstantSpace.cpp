class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[(nums[i] - 1) % nums.size()] += nums.size();

        vector<int> o;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 2 * nums.size())
                o.push_back(i + 1);

        return o;
    }
};