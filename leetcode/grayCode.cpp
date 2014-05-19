class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        for (int i = 0; i < n; ++i) {
            int temp = 1 << i;
            for (int j = result.size()-1; j >= 0; --j) {
                result.push_back(temp | result[j]);
            }
        }
        return result;      
    }
    
};