class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() <= 0) return 0;
        unordered_map<int, int> map;
        vector<int>::iterator iter = num.begin();
        int longest = INT_MIN;
        for( ; iter != num.end(); iter++)
            map[*iter] = 0;
        for(iter = num.begin(); iter != num.end(); iter++){
            if(map[*iter] == 0){
                int count = 0, number = *iter + 1;
                while(map.find(number) != map.end() && map[number] == 0){ // found and not visited yet
                    count++;
                    map[number++] = -1; // visited
                }
                map[*iter] = map.find(number) == map.end() ? count : count + map[number] + 1;
                longest = max(longest, map[*iter]);
            }
        }
        return longest + 1;
    }
};
