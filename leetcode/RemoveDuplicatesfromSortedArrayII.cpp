//soultion 1: we can record the duplicates numbers, we only need one variable to do that because of the sorted array .
//the different duplicates_numbers result in different duplicates number array.
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 3) {
			return n;
		}
		const int duplicates_numbers = 2;
		int index = duplicates_numbers;
		int end = duplicates_numbers;
		while (end < n) {
			if (A[end] != A[index -duplicates_numbers]) {
				A[index++] = A[end];
			}
			++end;
		}
		return index;
	}
};

//the use of three pointers indicate the boundry of differnt number
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 3) {
			return n;
		}
		int index = 0;
		int i = 0;
		while (i < n) {
			if (i > 0 && i < n-1 && A[i] == A[i-1] && A[i] == A[i+1]) {		
				++i;
				continue;
			}
			A[index++] = A[i++];
		}
		return index;
	}
};