void quicksort(int arr[], int left, int right){
	int i = left, j = right;
	int pivot = arr[(i + j) / 2];
	while(i <= j){
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;
		if(i <= j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if(left < j) quicksort(arr, left, j);
	if(i < right) quicksort(arr, i, right);
}
