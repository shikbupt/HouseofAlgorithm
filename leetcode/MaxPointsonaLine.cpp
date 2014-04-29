#include <vector>
#include <assert.h>
#include <unordered_map>
#include <limits>
#include <stdio.h>

using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        if (points.size() < 3){
            return points.size();
        }
        unordered_map<double, int> same_slope;
        for (int i = 0; i < points.size()-1; ++i){
            same_slope.clear();
            int same_points = 0;
            int point_max = 0;
            for (int j = i+1; j < points.size(); ++j){
                double slope;
                if (points[i].x == points[j].x){
                    slope = numeric_limits<double>::infinity();
                    if (points[i].y == points[j].y){
                        ++same_points;
                        continue;
                    }
                }
                else{
                    slope = static_cast<double>(points[i].y-points[j].y)/(points[i].x-points[j].x);
                }
                ++same_slope[slope];
            }
            for(auto i : same_slope) {
                if (point_max < i.second){
                    point_max = i.second;
                }
            }
            result = result > (point_max + same_points + 1) ? result : (point_max + same_points + 1);
        }
        return result;
    }
};

void test() {
    Solution s;
    std::vector<Point> t1 {Point(0, 0), Point(1, 2), Point(2, 4), Point(0, 0)};
    assert(s.maxPoints(t1) == 4);
    std::vector<Point> t2 {Point(0, 0), Point(1, 2), Point(2, 4), Point(5, 6)};
    assert(s.maxPoints(t2) == 3);
    std::vector<Point> t3 {Point(1, 1), Point(1, 1), Point(1, 1)};
    assert(s.maxPoints(t3) == 3);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}