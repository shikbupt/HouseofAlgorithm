#include <vector>
using namespace std;

const int queen_number = 8;
int position[queen_number] = {-1};
int total_number = 0;
vector<vector<int> > queen_positions;
vector<int> one_qualified_psition(8, -1);

void search(int cur) {
	if (cur == queen_number) {
		queen_positions.push_back(one_qualified_psition);
		++total_number;
		return;
	}
	for (int i = 0; i < queen_number; ++i) {
		position[cur] = i;
		int ok = 1;
		for (int j = 0; j < cur; ++j) {
			if (position[j] == position[cur] || cur-position[cur] == j-position[j] ||
				cur+position[cur] == j+position[j]) {
					ok = 0;
					break;
			}
		}
		if (ok) {
			one_qualified_psition[cur] = i;
			search(cur+1);
			one_qualified_psition[cur] = -1;
		}
	}
}
void EightQueen() {
	search(0);
}