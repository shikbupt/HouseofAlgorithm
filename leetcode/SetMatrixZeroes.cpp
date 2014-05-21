class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool first_row_has_0 = false;
        bool first_col_has_0 = false;
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            if (matrix[0][i] == 0)
            {
                first_row_has_0 = true;
                break;
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                first_col_has_0 = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 1; j < matrix.size(); ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < matrix[0].size(); ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row_has_0)
        {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (first_col_has_0)
        {
            for (int i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};