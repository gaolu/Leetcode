class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        if(strs.size() <= 0) return result;
        map<string, int> strings;
        for(int i = 0; i < strs.size(); i++){
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            if(strings.find(sortedString) == strings.end()) strings.insert(make_pair(sortedString, i));
            else{
                if(strings[sortedString] >= 0){
                    result.push_back(strs[strings[sortedString]]);
                    strings[sortedString] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};