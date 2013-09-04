public class Solution{
	public int[][] generateMatrix(int n){
		int [][] matrix = new int[n][n];
		int start = 0, end = n - 1, num = 1;
		while(start < end){
			for(int j = start; j < end; j++){
				matrix[start][j] = num;
				num++;
			}
			for(int i = start; i < end; i++){
				matrix[i][end] = num;
				num++;
			}
			for(int j = end; j > start; j--){
				matrix[end][j] = num;
				num++;
			}
			for(int i = end; i > start; i--){
				matrix[i][start] = num;
				num++;
			}
			start++;
			end--;
			
				
		}
		if(start == end)
			num[start][end] = num;
		return matrix;
	}
}
