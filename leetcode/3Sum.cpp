//time complexity O(n^2),the skipping reapeated elements is must,otherwise there is a TLE
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3) return result;
        sort(num.begin(), num.end());
        typedef vector<int>::iterator VECT_ITER;
        for(VECT_ITER i = num.begin(); i != num.end()-2; ++i){
            if(i>num.begin() && *i==*(i-1)) continue;  //skipping reapeated elements
            VECT_ITER pre = i+1;
            VECT_ITER last = num.end()-1;
            while(pre < last){
                if(*i+*pre+*last>0){
                    do{
                        --last;
                    }while(last<num.end()-2 && *last==*(last+1));   //skipping reapeated elements
                    
                }
                else if(*i+*pre+*last<0){
                    do{
                        ++pre;
                    }while(pre>num.begin()+1 && *pre==*(pre-1));   //skipping reapeated elements
                }
                else{
                    result.push_back({*i, *pre, *last});
                    ++pre;
                    --last;
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};