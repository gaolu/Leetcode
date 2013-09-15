class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start == end) return 1;
        if(start.size() == 0 && end.size() == 0) return 1;
        if(start.size() != end.size()) return 0;
        if(dict.size() == 0) return 0;
        int length = 1;
        queue<string> currentLevel, nextLevel;
        currentLevel.push(start);
        while(dict.size() > 0 && !currentLevel.empty()){
            while(!currentLevel.empty()){
                string str(currentLevel.front());
                currentLevel.pop();
                for(int i = 0; i < str.size(); i++){
                    for(char j = 'a'; j <= 'z'; j++){
                        if(j == str[i]) continue;
                        char temp = str[i]; // used to restore back to original str
                        str[i] = j;
                        // found
                        if(str == end) return length + 1;
                        // not found, check dict
                        if(dict.count(str) > 0){
                            nextLevel.push(str);
                            dict.erase(str);
                        }
                        str[i] = temp;
                    }
                }
            }
            swap(currentLevel, nextLevel);
            length++;
        }
        return 0; // not found
    }
};