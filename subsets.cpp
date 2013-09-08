class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        sort(S.begin(), S.end());
        for(int i = 0; i < (1 << S.size()); i++){
            vector<int> temp;
            for(int j = 0; j < S.size(); j++){
                if(i & (1 << j))
                    temp.push_back(S[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};