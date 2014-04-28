class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        multimap<int, int> number_map;
        int i = 1;
        for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter, ++i) {
            number_map.insert(make_pair(*iter, i));
        }
        multimap<int, int>::iterator first_iter = number_map.begin();
        multimap<int, int>::iterator second_iter = --number_map.end();
        int j = 0;
        while(j < numbers.size()-1){
            if ((first_iter->first+second_iter->first)>target) {
                --second_iter;
                j++;
            } 
            else if((first_iter->first+second_iter->first)<target){
                ++first_iter;
                j++;
            }
            else {
                vector<int> result;
                result.push_back(first_iter->second);
                result.push_back(second_iter->second);
                sort(result.begin(), result.end());
                return result;
            }
            
        }
    }
};