void InsertSort(int number[], int n) {
	for (int i = 0; i < n; ++i) {
		int t = number[i];
		int j = i;
		for (; j > 0 && number[j-1]>t; --j) {
			number[j] = number[j-1];
		}
		number[j] = t;
	}
}