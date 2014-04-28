#include <string>
#include <assert.h>
#include <ctype.h>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        removeIllegalSpaces(s);
        reverse(s, 0, s.size());
        int begin=0, end = 0;
        for (string::iterator i = s.begin(); i != s.end(); ++i, ++end)
        {
            if (isspace(*i))
            {
                reverse(s, begin, end);
                begin = end + 1;
            }
        }
        reverse(s, begin, end);
    }

    void reverse(string &s, int begin, int end) {
        while(begin < end-1){
            char i = s[begin];
            s[begin] = s[end-1];
            s[end-1] = i;
            ++begin;
            --end;
        }
    }

    void removeIllegalSpaces(string &s) {
        string temp;
        int flag = 1;
        for (string::iterator i = s.begin(); i != s.end(); ++i)
        {
            if (isspace(*i))
            {
               flag = 0;
            }else{
                if (flag == 0)
                {
                    temp.push_back(' ');
                    temp.push_back(*i);
                    flag = 1;
                }else{
                    temp.push_back(*i);
                }
            }
        }
        if (isspace(temp[0]))
        {
            s.assign(temp, 1, temp.size()-1);
        }else{
            s = temp;
        }
    }
};


void test() {
    string s1("the sky is blue");
    string s2(" the sky is blue ");
    string s3("the sky is   blue  ");
    Solution re;
    re.reverseWords(s1);
    re.reverseWords(s2);
    re.reverseWords(s3);
    string s("blue is sky the");
    assert(s == s1);
    assert(s == s2);
    assert(s == s3);
}

int main(){
    test();
}