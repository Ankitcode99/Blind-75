class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[lo] <= nums[mid])
            { // left half is sorted;
                if (nums[lo] <= target && target <= nums[mid])
                { // 4 <= 0 <= 7
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};