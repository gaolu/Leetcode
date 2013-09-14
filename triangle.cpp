class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numLayer = triangle.size();
        vector<int> sum(numLayer + 1, 0);
        while(numLayer--){
            for(int i = 0; i <= numLayer; i++)
                sum[i] = triangle[numLayer][i] + min(sum[i], sum[i + 1]);
        }
        return sum[0];
    }
};