#include <assert.h>

class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0, end = n-1;
        while(begin <= end) {
            int mid = (begin + end)/2;
            if (A[mid] == target){
                    return true;
            }
            if (A[begin] < A[mid]){
                    if (A[begin] <= target && target < A[mid]){
                            end = mid -1;
                    }
                    else{
                            begin = mid + 1;
                    }
            }
            else if (A[begin] > A[mid]){
                    if (A[mid] < target && target <= A[end]){
                            begin = mid + 1;
                    }
                    else {
                            end = mid -1;
                    }
            }
            else {
                    ++begin;
            }
        }
        return false;
    }
};

void  test() {
    Solution s;
    int a[] {1, 1, 1, 1, 1};
    assert(true == s.search(a, 5, 1));
    int a1[] {1, 3, 1, 1, 1};
    assert(true == s.search(a1, 5, 3));
    int a2[] {1, 1, 3, 1, 1};
    assert(true == s.search(a2, 5, 3));
    int a3[] {1, 1, 1, 3, 1};
    assert(false == s.search(a3, 5, 2));
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}