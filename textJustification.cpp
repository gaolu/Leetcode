class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> afterJustified;
        int begin = 0, length = 0, n = words.size();
        for(int i = 0; i < n; i++){
            if(length + words[i].size() + (i - begin) > L){
                afterJustified.push_back(connect(words, begin, i - 1, length, L, false));
                begin = i;
                length = 0;
            }
            length += words[i].size();
        }
        // add last line
        afterJustified.push_back(connect(words, begin, n - 1, length, L, true));
        return afterJustified;
    }
    
    string connect(vector<string> &words, int begin, int end, int len, int L, bool leftJustify){        
        string s;
        int n = end - begin + 1;
        for(int i = 0; i < n; i++){
            s += words[begin + i];
            addSpaces(s, i, n - 1, L - len, leftJustify);
        }
        
        if(s.size() < L)
            s.append(L - s.size(), ' ');
		return s;
    }
    
    void addSpaces(string &s, int i, int n, int L, bool leftJustify){
        if(n < 1 || i > n - 1) return;
        int spaces = leftJustify ? 1 : (L / n + (i < (L % n) ? 1 : 0));
        s.append(spaces, ' ');
    }
};
