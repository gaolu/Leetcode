/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = intervals.size();
        if(n == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i = 0;
        vector<Interval> result;
        // find the first interval whose start is bigger than the newInterval
        while(i < n && intervals[i].start < newInterval.start){
            result.push_back(intervals[i]);
            ++i;
        }
        // reach the end of intervals
        if(i == n){
        	// no overlapping
            if(result.back().end < newInterval.start)
                result.push_back(newInterval);
            // overlapped and update the end value
            else result.back().end = max(result.back().end, newInterval.end);
            return result;
        }
        // newInterval is smaller than the smallest interval in start values
        if(result.size() == 0) result.push_back(newInterval);
        // insert newInterval
        else{
            if(newInterval.start <= result.back().end)
                result.back().end = max(result.back().end, newInterval.end);
            else
                result.push_back(newInterval);
        }
        // push back to rest of intervals and update the end value if necessary
        while(i < n){
            if(intervals[i].start <= result.back().end)
                result.back().end = max(result.back().end, intervals[i].end);
            else
                result.push_back(intervals[i]);
            ++i;
        }
        return result;
    }
};
