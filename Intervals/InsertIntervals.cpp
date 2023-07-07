class Solution {
private:
    bool checkOverlap(vector<int> interval1, vector<int> interval2){
        bool condition1 = (interval1[0] <= interval2[0]) and (interval2[0] <= interval1[1]);
        bool condition2 = (interval1[0] <= interval2[1]) and (interval2[1] <= interval1[1]);
        bool condition3 = (interval2[0] <= interval1[0]) and (interval1[0] <= interval2[1]);
        bool condition4 = (interval2[0] <= interval1[1]) and (interval1[1] <= interval2[1]);

        return condition1 || condition2 || condition3 || condition4;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx=0;
        vector<vector<int>> result;

        // insert smaller pairs that are non-overlapping;

        while(idx<intervals.size() and intervals[idx][1] < newInterval[0]){
            result.push_back(intervals[idx]);
            idx++;
        }

        // now either an overlapping interval will come or we'll only put the new interval
        while(idx<intervals.size() and checkOverlap(intervals[idx], newInterval)){
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        result.push_back(newInterval);

        while(idx<intervals.size()){
            result.push_back(intervals[idx]);
            idx++;
        }

        return result;
    }
};