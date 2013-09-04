struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e){}
}

class Solution{
	public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
		int n = intervals.size();
		int i = 0;
		vector<Interval> ret;
		while(i < n && intervals[i].end < newInterval.start){
			ret.push_back(intervals[i++]);
		}
		// insert position found
		while(i < n && newInterval.end >= intervals[i].start){
			newInterval.end = max(newInterval.end, intervals[i].end);
			newInterval.start = min(newInterval.start, intervals[i].start);
			++i;
		}
		// insertion finished and intervals updated
		ret.push_back(newInterval);
		while(i < n){
			ret.push_back(intervals[i++]);
		}
		return ret;
	}
};
