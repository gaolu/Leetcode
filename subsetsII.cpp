class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> subsets;
        vector<int> subset;
        if(S.size() <= 0)
            return subsets;
        sort(S.begin(), S.end());
        getSubsets(S, 0, subset, subsets);
        return subsets;
    }
    
    void getSubsets(vector<int> &S, int begin, vector<int> &subset, vector<vector<int>> &subsets){
        subsets.push_back(subset);
        for(int i = begin; i < S.size(); i++){
            if(i != begin && S[i] == S[i - 1])
                continue;
            subset.push_back(S[i]);
            getSubsets(S, i + 1, subset, subsets);
            subset.pop_back();
        }
        return;
    }
};
