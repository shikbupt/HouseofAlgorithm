int partition(int number[], int begin, int end) {
	if (begin < end) {
		int m = begin;
		for (int i =begin; i < end; ++i) {
			if (number[i] < number[end]) {
				int temp = number[m];
				number[m] = number[i];
				number[i] = temp;
				++m;
			}
		}
		int temp = number[m];
		number[m] = number[end];
		number[end] = temp;
		return m;
	}
}

void qsort(int number[], int begin, int end) {
	if (begin < end) {
		int mid = partition(number, begin, end);
		qsort(number, begin, mid-1);
		qsort(number, mid+1, end);
	}
}