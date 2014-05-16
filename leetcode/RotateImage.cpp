
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        //get transpose of matrix
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i+1; j < matrix.size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            
        }
        //reverse each row
        for (std::vector<vector<int> >::iterator i = matrix.begin(); i != matrix.end(); ++i)
        {
            reverse(i->begin(), i->end());
        }

    }
};