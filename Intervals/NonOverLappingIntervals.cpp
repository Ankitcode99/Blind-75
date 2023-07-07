class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int left=0, right=1;
        sort(intervals.begin(), intervals.end());

        while(right < intervals.size()){
            if(intervals[left][1] <= intervals[right][0]){ // no overlap
                left = right;
                right += 1;
            } else if(intervals[left][1] <= intervals[right][1]){ //partial overlap
                count += 1;
                right +=1;
            } else if(intervals[right][1] <= intervals[left][1]) { // complete overlap
                // In the above condition we did not checked interval[left][0] <= interval[right][0] because the array is sorted by first element itself above.
                count += 1;
                left = right;
                right +=1;
            }
        }

        return count;
    }
};