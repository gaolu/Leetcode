class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n <= 0)
            return 0;
        vector<int> count(n + 1);
        count[0] = 1;
        for(int i = 1; i < n + 1; i++){
            int count1 = 0;
            if(s[i - 1] != '0')
                count1 = count[i - 1];
            int count2 = 0;
            if(i >= 2 && s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
                count2 = count[i - 2];
            count[i] = count1 + count2;
        }
        return count[n];
    }
};