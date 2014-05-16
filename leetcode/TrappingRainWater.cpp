class Solution {
public:
    int trap(int A[], int n) {
        int max = 0;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > A[max])
            {
                max = i;
            }
        }
        int water = 0;
        int left_max = 0;
        for (int i = 0; i < max; ++i)
        {
            if (A[i] > left_max)
            {
                left_max = A[i];
            }
            else {
                water += left_max - A[i];
            }
        }
        int right_max = 0;
        for (int i = n-1; i > max; --i)
        {
            if (A[i] > right_max)
            {
                right_max = A[i];
            }
            else {
                water += right_max - A[i];
            }
        }
        return water;
    }
};