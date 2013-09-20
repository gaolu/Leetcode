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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // function overload using isLower and we have to tell the compiler the scope of isLower
        sort(intervals.begin(), intervals.end(), Solution::isLower);
        int length = intervals.size();
        int i = 0;
        vector<Interval> result;
        while(i < length){
            result.push_back(intervals[i++]);
            while(i < length && intervals[i].start <= result.back().end)
                result.back().end = max(result.back().end, intervals[i++].end);
        }
        return result;
    }
    // have to be static to avoid compilation error
    static bool isLower(const Interval &interval1, const Interval &interval2){
        return interval1.start < interval2.start;
    }
};
