//soultion 1: Time complexity O(N^2), Space complexity O(1)
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 2) {
			return n;
		}
		int begin = 0, end = 1;
		while (end < n) {
			if (A[begin] == A[end]) {
				++end;
				continue;
			}
			for (int i = begin+1; i < end; ++i) {
				A[i] = A[end];
			} 
			++begin;
			++end;
		}
		return begin+1;
	}
};

//soultion 2: Time complexity O(N), Space complexity O(1)
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 2) {
			return n;
		}
		int begin = 0, end = 1;
		while (end < n) {
			if (A[begin] != A[end]) {
				A[++begin] = A[end];
			}
			++end;
		}
		return begin+1;
	}
};