public class Solution {
    public ArrayList<String> wordBreak(String s, Set<String> dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<String> result = new ArrayList<String>();
        if(s == null || dict.size() <= 0) return result;
        int length = s.length();
        boolean[][] inDict = new boolean[length][length + 1];
        for(int len = 1; len <= length; len++){
            for(int i = 0; i < length - len + 1; i++){
                String t = s.substring(i, i + len);
                if(dict.contains(t)){
                    inDict[i][len] = true;
                    continue;
                }
                for(int k = 1; k < len; k++){
                    if(inDict[i][k] && inDict[i + k][len - k]){
                        inDict[i][len] = true;
                        break;
                    }
                }
            }
        }
        if(!inDict[0][length]) return result;
        int depth = 0;
        dfs(s, inDict, 0, length, depth, result, new StringBuffer(), dict);
        return result;
    }
    
    private static void dfs(String s, boolean[][] inDict, int start, int length, int depth, ArrayList<String> result, StringBuffer sb, Set<String> dict){
        if(depth == length){
            String t = sb.toString();
            result.add(t.substring(0, t.length() - 1));
            return;
        }
        for(int len = 1; len <= length; len++){
            if(inDict[start][len]){
                String t = s.substring(start, start + len);
                if(!dict.contains(t)) continue;
                int beforeAppend = sb.length();
                sb.append(t).append(" ");
                dfs(s, inDict, start + len, length, start + len, result, sb, dict);
                sb.delete(beforeAppend, sb.length());
            }
        }
    }
}