struct Interval {
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};

class Solution{
	vector<Interval> merge(vector<Interval> &intervals){
		vector<Interval> ret;
		sort(intervals.begin(), intervals.end(), isLower);
		int i = 0;
		int n = intervals.size();
		while(i < n){
			ret.push_back(intervals[i++]);
			while(i < n && intervals[i].start <= ret.back().end)
				ret.back().end = max(ret.back().end, intervals[i++].end);
		}
		return ret;
	}

	bool isLower(const Interval int1, const Interval int2){
		return int1.start < int2.start;
	}
}
