class Solution{
	bool canJump(int[] A, int n){
		int reach = 1;
		for(int i = 0; i < n, i++){
			reach = max(reach, A[i] + i + 1);
		}
		return reach >= n;
	}
}
