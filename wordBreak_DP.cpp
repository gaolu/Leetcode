public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s == null || dict.size() <= 0){
            return false;
        }
        
        int length = s.length();
        // seg(i, j) means substring t start from i and length is j can be segmented into 
        // dictionary words
        boolean[][] seg = new boolean[length][length + 1];
        for(int len = 1; len <= length; len++){
            for(int i = 0; i < length - len + 1; i++){
                String t = s.substring(i, i + len);
                if(dict.contains(t)){
                    seg[i][len] = true;
                    continue;
                }
                for(int k = 1; k < len; k++){
                    if(seg[i][k] && seg[i+k][len-k]){
                        seg[i][len] = true;
                        break;
                    }
                }
            }
        }
        return seg[0][length];
    }
}