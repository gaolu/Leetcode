class Solution {
public:
    bool helper(string s, unordered_set<string> &dict, set<string> &unmatch){
        if(s.length() < 1) return true;
        bool isMatch = false;
        for(int len = 1; len <= s.length(); len++){
            string prefix = s.substr(0, len);
            unordered_set<string>::iterator preIter = dict.find(prefix);
            if(preIter != dict.end()){
                string suffix = s.substr(len);
                set<string>::iterator sufIter = unmatch.find(suffix);
                if(sufIter != unmatch.end()) continue;
                else{
                    isMatch = helper(suffix, dict, unmatch);
                    if(isMatch) return isMatch;
                    else unmatch.insert(suffix);
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s.length() < 1) return true;
        set<string> unmatch;
        return helper(s, dict, unmatch);
    }
};