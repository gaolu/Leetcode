class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> compareChart(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        compareChart[0][0] = true;
        for(int i = 1; i < s1.size() + 1; i++){
            if(s1[i - 1] == s3[i - 1])
                compareChart[i][0] = true;
            else
                break;
        }
        for(int i = 1; i < s2.size() + 1; i++){
            if(s2[i - 1] == s3[i - 1])
                compareChart[0][i] = true;
            else
                break;
        }
        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                if(s1[i - 1] == s3[i + j - 1])
                    compareChart[i][j] = compareChart[i - 1][j] || compareChart[i][j];
                if(s2[j - 1] == s3[i + j - 1])
                    compareChart[i][j] = compareChart[i][j - 1] || compareChart[i][j];
            }
        }
        return compareChart[s1.size()][s2.size()];
    }
};
