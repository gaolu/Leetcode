class Solution{
	public:
	int lengthOfLastWord(const char *s){
		if(s == NULL || *s == '\0')
			return 0;
		int length = 0;
		int lastLength = 0;
		while(*s){
			if(*s == ' '){
				if(length > 0)
					lastLength = length;
			}
			else
				length++;
			s++;
		}
		if(lastLength > 0 && length == 0)
			return lastLength;
		return length;
	}
}
