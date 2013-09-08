class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> single;
        vector<vector<int>> combineResult;
        recursiveCombine(n, k, 1, single, combineResult);
        return combineResult;
    }
    
    void recursiveCombine(int n, int k, int start, vector<int> single, vector<vector<int>> &combineResult){
        if(single.size() == k){
            combineResult.push_back(single);
            return;
        }
        for(int i = start; i <= n; i++){
            single.push_back(i);
            recursiveCombine(n, k, ++start, single, combineResult);
            single.pop_back();
        }
        return;
    }
};