class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if(candidates.size() <= 0) return result;
        sort(candidates.begin(), candidates.end());
        if(target < candidates[0]) return result;
        vector<int> temp;
        find(candidates, 0, candidates.size(), target, result, temp);
        set<vector<int>> s(result.begin(), result.end());
        result.assign(s.begin(), s.end());
        return result;
    }
    
    void find(vector<int> &candidates, int start, int end, int target, vector<vector<int>> &result, vector<int> &temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i = start; i < end; i++){
            if(target < candidates[i]) continue;
            temp.push_back(candidates[i]);
            // reduce the target
            target -= candidates[i];
            // find the new target from the next int
            find(candidates, i + 1, end, target, result, temp);
            // restore target back to its original value
            target += temp.back();
            // remove the last element before return
            temp.resize(temp.size() - 1);
        }
        return;
    }
};