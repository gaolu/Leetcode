package regularExpressionMatching;
// not really working should come back to this later!!!
public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(isMatch("aa", "a"));
	}

	public static boolean isMatch(String s, String p){
		if(p.length() == 0 && s.length() != 0)
			return false;
		int i, j;
		for(i = 0; i < s.length(); i++){
			char current = s.charAt(i);
			for(j = 0; j < p.length(); j++){
				if(p.charAt(j) == current || p.charAt(j) == '.' || p.charAt(j) == '*')
					break;
			}
			while(i < s.length()){
				if(s.charAt(++i) != p.charAt(++j) && p.charAt(j) != '.' && p.charAt(j) != '*')
					return false;
			}
		}
		return true;
	}
}
