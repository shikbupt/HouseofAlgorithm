#include <utility>
#include <assert.h>

using std::swap;

int Partition(int a[], int begin, int end) {
        if (begin > end){
                return -1;
        }
        int p = begin;
        for (int i = begin; i < end+1; ++i){
                if (a[i] < a[end]){
                        swap(a[p++], a[i]);
                }
        }
        swap(a[p], a[end]);
        return p;
}

int FindKth(int a[], int begin, int end, int k) {
        if (begin > end){
                return -1;
        }
        int mid = Partition(a, begin, end);
        if (k == mid + 1){
                return a[mid];
        }
        if (k > mid + 1){
                FindKth(a, mid+1,  end, k);
        }
        else{
                FindKth(a, begin, mid-1, k);
        }
}

void test() {
        int L[]={1, 2, 3, 4, 5};
        assert(3 == FindKth(L, 0, 4, 3));
        int L1[]={5, 4, 3, 2, 1};
        assert(3 == FindKth(L1, 0, 4, 3));
         int L2[]={5, 4, 3, 2, 1, 1, 2};
        assert(5 == FindKth(L2, 0, 6, 7));
}

int main(int argc, char const *argv[])
{
        test();
        return 0;
}