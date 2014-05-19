//iteration
class Solution {
public:
    int climbStairs(int n) {
        int pre = 0; 
        int cur = 1;
        for (int i = 0; i < n; ++i)
        {
            int temp =cur;
            cur += pre;
            pre = temp;
        }
        return cur;
    }
};

//memory search
class Solution {
public:
    int climbStairs(int n) {
        a = new int[n+1];
        memset(a,-1,(n+1)*4); 
        return getFibonacci(n);

    }
    int getFibonacci(int n) {
        if (n <= 0)
        {
            a[0] = 1;
            return a[0];
        }
        if (n == 1)
        {
            a[1] = 1;
            return a[1];
        }
        if (a[n] != -1)
        {
            return a[n];
        }
        a[n] = getFibonacci(n-1) + getFibonacci(n-2);
        return a[n];
    }
    ~Solution(){
        delete []a;
    }
private:
    int* a;
};

