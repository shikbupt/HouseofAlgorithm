class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4)
        {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; ++i)
        {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < num.size() - 2; ++j)
            {
                if (j > i+1 && num[j] == num[j-1]) continue;
                int pre = j + 1;
                int last = num.size()-1;
                while(pre < last) {
                    if (num[i]+num[j]+num[pre]+num[last] == target)
                    {
                        result.push_back({num[i], num[j], num[pre], num[last]});
                        --last;
                        ++pre;
                    }
                    if (num[i]+num[j]+num[pre]+num[last] > target)
                    {
                        --last;
                    }
                    else
                    {
                        ++pre;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};