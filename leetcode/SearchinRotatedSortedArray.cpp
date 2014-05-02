#include <assert.h>
class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0, end = n-1;
        while(begin <= end) {
            int mid = (begin+end)/2;
            if (A[mid] == target){
                return mid;
            }
            if (A[begin] <= A[mid]){
                if (A[begin] <= target && target < A[mid]){
                        end = mid - 1;
                }
                else{
                    begin = mid + 1;
                }
            }
            else{
                if (A[end] >= target && target > A[mid]){
                    begin = mid + 1;
                }
                else {
                    end = mid - 1;
                }

            }
        }
        return -1;
    }
};


void test() {
    Solution s;
    int A[] {0, 1, 2, 3, 4, 5, 6};
    assert(5 == s.search(A, 7, 5));
    int A1[] {6, 7, 8, 1, 2, 3, 4};
    assert(3 == s.search(A1, 7, 1));
    int A2[] {0, 1, 2, 3, 4, 5, 6};
    assert(-1 == s.search(A2, 7, 8));
    int A3[] {1, 3, 5};
    assert(0 == s.search(A3, 3, 1));
    int A4[] {3, 1};
    assert(1 == s.search(A4, 2, 1));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}