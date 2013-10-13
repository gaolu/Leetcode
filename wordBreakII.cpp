class Solution {
public:
    bool helper(string s, unordered_set<string> &dict, set<string> &unmatch, vector<string> &result, vector<string> &currStr){
        if(s.length() < 1) {
            string curr = "";
            for(int i = 0; i < currStr.size(); i++){
                curr += currStr[i];
                if(i < currStr.size() - 1)
                    curr += " ";
            }
            result.push_back(curr);
            currStr.clear();
            return true;
        }
        bool isMatch = false;
        for(int len = 1; len <= s.length(); len++){
            string prefix = s.substr(0, len);
            unordered_set<string>::iterator preIter = dict.find(prefix);
            if(preIter != dict.end()){
                currStr.push_back(prefix);
                string suffix = s.substr(len);
                set<string>::iterator sufIter = unmatch.find(suffix);
                if(sufIter != unmatch.end()) {
                    currStr.resize(currStr.size() - 1);
                    continue;
                }
                else{
                    isMatch = helper(suffix, dict, unmatch, result, currStr);
                    //if(isMatch) return isMatch;
                    if(!isMatch) unmatch.insert(suffix);
                }
            }
        }
        unmatch.clear();
        return false;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        //string currStr = "";
        if(s.length() < 1) return result;
        set<string> unmatch;
        vector<string> currStr;
        helper(s, dict, unmatch, result, currStr);
        return result;
    }
};