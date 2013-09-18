public class Solution {
    public String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s.length() == 0 || nRows == 1)
    		return s;
		int i;
		StringBuffer string = new StringBuffer();
		int diff = nRows + nRows - 2;
		for(i = 0; i < nRows; i++){
			int index = i;
			while(index < s.length()){
				string.append(s.charAt(index));
				index = index + diff;
				if(i != 0 && i != nRows - 1 && index - i - i < s.length()){
					string.append(s.charAt(index - i - i));
				}
			}
			//string.append('\n');
		}
		return string.toString();
    }
}