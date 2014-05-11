//bitset can also fulfuill the goal, but the space complexity must be high. And leetcode say that the bitset not belong to STL, i dont know why. However the hash is the //best method.
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
       unordered_map<int, bool> num_map;
       for(int i : num) num_map[i] = false;
       int max_len = -1;
       for(int i : num) {
           if(num_map[i]) continue;
           int len = 1;
           for(int j = i+1; num_map.find(j) != num_map.end(); ++j){
               ++len;
               num_map[j] = true;
           }
            for (int j = i-1; num_map.find(j) != num_map.end(); --j){
                ++len;
               num_map[j] = true;
            }
            max_len = len > max_len ? len : max_len;
       }
    return max_len;
    }
};