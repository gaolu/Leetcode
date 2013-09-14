class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if(numRows <= 0)
            return result;
        result.push_back(vector<int>(1, 1));
        for(int i = 1; i < numRows; i++){
            vector<int> lineVec;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    lineVec.push_back(1);
                else
                    lineVec.push_back(result.back()[j - 1] + result.back()[j]);
            }
            result.push_back(lineVec);
        }
        return result;
    }
};