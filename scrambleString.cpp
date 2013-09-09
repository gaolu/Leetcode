class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1 == s2)
            return true;
        if(s1.size() != s2.size())
            return false;
        string sortedS1 = s1, sortedS2 = s2;
        sort(sortedS1.begin(), sortedS1.end());
        sort(sortedS2.begin(), sortedS2.end());
        if(sortedS1 != sortedS2)
            return false;
        for(int sptPt = 1; sptPt < s1.size(); sptPt++){
            string s11 = s1.substr(0, sptPt);
            string s12 = s1.substr(sptPt);
            string s21 = s2.substr(0, sptPt);
            string s22 = s2.substr(sptPt);
            if(isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            s21 = s2.substr(s2.size() - sptPt);
            s22 = s2.substr(0, s2.size() - sptPt);
            if(isScramble(s11, s21) && isScramble(s12, s22))
                return true;
        }
        return false;
    }
};
