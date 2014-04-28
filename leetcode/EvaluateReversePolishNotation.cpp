//using c++11
#include <vector>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::vector<int> result;
        //for (std::vector<string>::iterator i = tokens.begin(); i != tokens.end(); ++i)
        for (auto i : tokens)
        {
            if (i=="*"||i=="+"||i=="/"||i=="-")
            {
                int b = result.back();
                result.pop_back();
                int a = result.back();
                result.pop_back();
                result.push_back(Calculator(a, b, i));
            }else{
                int a = 0;
                istringstream(i) >> a;
                result.push_back(a);
            }
        }
        if (result.size() == 1)
        {
            return result.back();
        }else{
            return -1;
        }
    }

    int Calculator(int a, int b, const string& i) {
        switch (i[0]){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
       

    }
};


void test() {
    std::vector<string> v1 {"2", "1", "+", "3", "*"};
    std::vector<string> v2 {"4", "13", "5", "/", "+"};
    std::vector<string> v3 {"3","-4","+"};
    Solution test;
    assert(9==test.evalRPN(v1));
    assert(6==test.evalRPN(v2));
    assert(-1==test.evalRPN(v3));
}

int main() {
    test();
    return 1;
}