class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> stack;
        assert(path[0] == '/');
        int i = 0;
        while(i < path.size()){
            // skip preceding /s
            while(path[i] == '/' && i < path.size())
                i++;
            if(i == path.size())
                break;
            int start = i;
            while(path[i] != '/' && i < path.size())
                i++;
            int end = i - 1;
            string sub = path.substr(start, end - start + 1);
            if(sub == ".."){
                if(stack.size() > 0)
                    stack.pop_back();
            }
            // push only when not / or .
            else if(sub != ".")
                stack.push_back(sub);
        }
        if(stack.size() == 0)
            return "/";
        string afterSimplified = "";
        for(int i = 0; i < stack.size(); i++)
            afterSimplified += "/" + stack[i];
        return afterSimplified;
    }
};