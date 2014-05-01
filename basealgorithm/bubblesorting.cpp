void BubbleSort(int A[], int n) {
	if (n <= 0) {
		return;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (A[j] < A[i]) { //this method is not correct when a[j]==a[i]
				A[j] ^= A[i];
				A[i] ^= A[j];
				A[j] ^= A[i];
			}
		}
	}
}