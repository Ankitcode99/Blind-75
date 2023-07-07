class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        ans.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1;i<intervals.size();i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            
            int prevStart = ans.back()[0];
            int prevEnd = ans.back()[1];
            
            if(prevEnd >= currStart){
                currEnd = max(currEnd, prevEnd);
                ans.pop_back();
                ans.push_back({prevStart, currEnd});
            }else{
                ans.push_back({currStart, currEnd});
            }
        }
        
        return ans;
    }
};