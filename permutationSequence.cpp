class Solution{
	public:
	string getPermutation(int n, int k){
		char* array = new char[n];
		int factor = 1;
		// construct the array and factor
		for(int i = 0; i < n; i++){
			array[i] = i + '1'; // convinient to convert to string
			factor *= (i + 1);
		}
		k--;
		k %= factor; // just in case k is bigger than n!
		factor /= n; // factor = (n - 1)! now
		for(int i = 0; i < n - 1; i++){
			int select = k / factor;
			k %= factor;
			factor /= (n - 1 - i);
			int temp = array[select + i];
			// put array[select] to be at position i, so need to shift the rest
			for(int j = select; j > 0; j--){
				array[i + j] = array[i + j - 1];
			}
			array[i] = temp;
		}
		return string(array, array + n);
	}
}
