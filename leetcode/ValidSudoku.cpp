//there are two versions, one based on comparsion, the other based on hash. 
//i think the hash will be faster than comparsion, but the result is contrary. i think the small data is the reason.
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i)
        {
            if(!CheckRowColumn(board, i, i)) return false;
        }
        for (int i = 0; i < 7; i += 3)
        {
            for (int j = 0; j < 7 ; j += 3)
            {
                if(!CheckGrid(board, i, j)) return false;
            }
        }
        return true;
    }
    bool CheckRowColumn(vector<vector<char> > &board, int i , int j) {
        for (int k = 0; k < 9; ++k)
        {
            if(board[i][k] == '.') continue;
            if (board[i][k] > '9' || board[i][k] < '1') return false;           
            for (int m = k+1; m < 9; ++m)
            {
                if(board[i][m] == '.') continue;
                if (board[i][k] == board[i][m] || board[i][m] > '9' || board[i][m] < '1')
                {
                    return false;
                }
            }
        }
        for (int k = 0; k < 9; ++k)
        {
            if(board[k][j] == '.') continue;
            if (board[k][j] > '9' || board[k][j] < '1') return false;           
            for (int m = k+1; m < 9; ++m)
            {
                if(board[m][j] == '.') continue;
                if (board[k][j] == board[m][j] || board[m][j] > '9' || board[m][j] < '1')
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool CheckGrid(vector<vector<char> > &board, int i, int j) {
        unordered_set<char> elem;
        for (int k = 0; k < 3; ++k)
        {
            for (int m = 0; m < 3; ++m)
            {
                if (board[i+k][j+m] == '.') continue;
                if (elem.find(board[i+k][j+m]) != elem.end())
                {
                    return false;
                }
                else
                {
                    elem.insert(board[i+k][j+m]);
                }              
            }
        }
        return true;
    }
};

//hash version
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i)
        {
            if(!CheckRowColumn(board, i, i)) return false;
        }
        for (int i = 0; i < 7; i += 3)
        {
            for (int j = 0; j < 7 ; j += 3)
            {
                if(!CheckGrid(board, i, j)) return false;
            }
        }
        return true;
    }
    bool CheckRowColumn(vector<vector<char> > &board, int i , int j) {
        unordered_set<char> elem;
        for (int k = 0; k < 9; ++k)
        {
            if (board[i][k] == '.') continue;
            if ('1' <= board[i][k] && board[i][k] <= '9' && elem.find(board[i][k]) == elem.end())
            {
                elem.insert(board[i][k]);
            }
            else {
                return false;
            }
        }
        elem.clear();
        for (int k = 0; k < 9; ++k)
        {
           if (board[k][j] == '.') continue;
            if ('1' <= board[k][j] && board[k][j] <= '9' && elem.find(board[k][j]) == elem.end())
            {
                elem.insert(board[k][j]);
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool CheckGrid(vector<vector<char> > &board, int i, int j) {
        unordered_set<char> elem;
        for (int k = 0; k < 3; ++k)
        {
            for (int m = 0; m < 3; ++m)
            {
                if (board[i+k][j+m] == '.') continue;
                if (elem.find(board[i+k][j+m]) != elem.end())
                {
                    return false;
                }
                else
                {
                    elem.insert(board[i+k][j+m]);
                }              
            }
        }
        return true;
    }
};


