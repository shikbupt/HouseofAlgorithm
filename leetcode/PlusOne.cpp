class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        int adding = 1;
        for (int i = digits.size()-1 ; i >= 0; --i)
        {
            int sum = digits[i] + adding;
            adding = sum / 10;
            result.push_back(sum%10);   
        }
        if (adding > 0)
        {
            result.push_back(adding);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};