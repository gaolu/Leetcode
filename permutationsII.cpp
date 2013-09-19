class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = num.size();
        vector<vector<int>> result;
        vector<int> temp;
        if(length <= 0) return result;
        // indicate whether that node has already been visited
        vector<int> visited(length, 0);
        sort(num.begin(), num.end());
        helper(visited, num, result, temp, length, 0);
        return result;
    }
    
    void helper(vector<int> &visited, vector<int> &num, vector<vector<int>> &result, vector<int> &temp, int length, int depth){
        if(length == depth){
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < length; i++){
        	// visit the non-visited nodes
            if(!visited[i]){
            	// when equal to previous node and previous node has not been used
            	// continue
                if(i > 0 && num[i - 1] == num[i] && !visited[i - 1]) continue;
                visited[i] = 1;
                temp.push_back(num[i]);
                helper(visited, num, result, temp, length, depth + 1);
                temp.resize(temp.size() - 1);
                visited[i] = 0;
            }
        }
        return;
    }
};
