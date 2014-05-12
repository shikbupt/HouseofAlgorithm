
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        //if (num.size() <= 3) return accumulate(num.begin(), num.end());  //leetcode dont support accumulate.
        if (num.size() <= 3) {
            int sum = 0;
            for(auto i : num){
                sum +=i;
            }
            return sum;
        }
        sort(num.begin(), num.end());
        int closest = 1000000000;
        for (int i = 0; i < num.size()-2; ++i)
        {
            int pre = i + 1;
            int last = num.size()-1;
            int gap;
            while(pre < last) {
                gap = num[i] + num[pre] + num[last] - target;
                if (gap == 0)
                {
                    return target;
                }
                if (abs(gap) < abs(closest))
                {
                    closest = gap;
                }
                if (gap > 0)
                {
                    --last;
                    continue;
                }
                if (gap < 0)
                {
                    ++pre;
                    continue;
                }
            }
            

        }
        return closest+target;
    }
};