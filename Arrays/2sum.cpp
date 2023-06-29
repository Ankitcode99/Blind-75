class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int idx=0;
        vector<int> ans;
        for(int num:nums){
            if(mp.find(target-num)!=mp.end()){
                ans.push_back(idx);
                ans.push_back(mp[target-num]);
                return ans;
            }
            mp[num]=idx++;
        }
        return ans;
    }
};