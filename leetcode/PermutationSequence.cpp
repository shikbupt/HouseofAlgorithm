class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> seq;
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            seq.push_back(i+1);
        }
        
        int j = factorial(--n);
        for (int i = k-1; i != 0 || n != 0; j = factorial(--n))
        {
            int num = i/j;
            i = i%j;
            result.push_back(seq[num]);
            seq.erase(seq.begin()+num);
        }
        result.push_back(seq[0]);
        string temp;
        for (int i = 0; i < result.size(); ++i) {
            temp.push_back(result[i]+'0');
        }
        return temp;
    }
    int factorial(int n) {
        if (n == 0)
        {
            return 1;
        }
        return n*factorial(n-1);
    }
};