#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool issafe(int row, int col, vector<string> board, int n)
    {
        int r = row;
        int c = col;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row = r;
        col = c;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }

        row = r;
        col = c;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (issafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNqueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

int main()
{
    int n = 4; // we are taking 4*4 grid and 4 queens
    Solution obj;
    vector<vector<string>> ans = obj.solveNqueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}