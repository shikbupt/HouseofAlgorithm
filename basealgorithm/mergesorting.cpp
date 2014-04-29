void merge(int A[], int begin, int end) {
    int* temp = new int[end-begin];
    int i = begin, j = (begin+end)/2, k = 0;
    while(i<(begin+end)/2 && j<end) {
        if (A[i]<=A[j])
        {
            temp[k] = A[i];
            ++i;
        }
        else{
            temp[k] = A[j];
            ++j;
        }
        ++k;
    }
    if (i != (begin+end)/2)
    {
        for (; i<(begin+end)/2; ++i)
        {
            temp[k]=A[i];
            ++k;
        }
    }
    for (int m = begin; m < k+begin; ++m)
    {
        A[m] = temp[m-begin];
    }
    delete[] temp;
}


void mergesort(int A[], int begin, int end) {
    if (begin+1 < end) {
        mergesort(A, begin, (begin+end)/2);
        mergesort(A, (begin+end)/2, end);
        merge(A, begin, end);
    }
   
}

void test(){
    int a[] = {2, 5, 1, 3, 2, 6, 7};
    int b[] = {1, 2, 3, 4, 5, 6, 7};
    int c[] = {9, 8, 7, 6, 5, 4};
    mergesort(a, 0, sizeof(a)/sizeof(int));
    mergesort(b, 0, sizeof(b)/sizeof(int));
    mergesort(c, 0, sizeof(c)/sizeof(int));
    return;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}