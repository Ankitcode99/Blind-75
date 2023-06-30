class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int left = i + 1, right = sz - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] == -1 * nums[i])
                    {
                        vector<int> ans = {nums[i], nums[left], nums[right]};

                        res.push_back(ans);

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++, right--;
                    }
                    else if (nums[left] + nums[right] < -1 * nums[i])
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};