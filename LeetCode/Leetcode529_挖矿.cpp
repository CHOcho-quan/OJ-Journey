//
//  Leetcode529_挖矿.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int Rays(vector<vector<char> > &board,int a,int b)
{
    int sum = 0;
    sum = (b < board[0].size()-1 && board[a][b+1]=='M') + (b > 0 && board[a][b-1]=='M') + (a < board.size()-1 && board[a+1][b]=='M') + (a > 0 && board[a-1][b]=='M') + (a < board.size()-1 && b > 0 && board[a+1][b-1]=='M') + (a > 0 && b > 0 && board[a-1][b-1]=='M') + (a > 0 && b < board[0].size()-1 && board[a-1][b+1]=='M') + (a < board.size()-1 && b < board[0].size()-1 && board[a+1][b+1]=='M');
    return sum;
}

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        else if (board[click[0]][click[1]]=='E')
        {
            if (Rays(board,click[0],click[1]) > 0)
            {
                board[click[0]][click[1]] = Rays(board,click[0],click[1])+'0';
                return board;
            }
            else
            {
                board[click[0]][click[1]] = 'B';
                if (click[0] > 0)
                {
                    click[0]--;
                    updateBoard(board,click);
                    click[0]++;
                }
                if (click[1] > 0)
                {
                    click[1]--;
                    updateBoard(board,click);
                    click[1]++;
                }
                if (click[0] < board.size()-1)
                {
                    click[0]++;
                    updateBoard(board,click);
                    click[0]--;
                }
                if (click[1] < board[0].size()-1)
                {
                    click[1]++;
                    updateBoard(board,click);
                    click[1]--;
                }
                if (click[0] < board.size()-1 && click[1] > 0)
                {
                    click[0]++;
                    click[1]--;
                    updateBoard(board,click);
                    click[0]--;
                    click[1]++;
                }
                if (click[0] < board.size()-1 && click[1] < board[0].size()-1)
                {
                    click[0]++;
                    click[1]++;
                    updateBoard(board,click);
                    click[0]--;
                    click[1]--;
                }
                if (click[0] > 0 && click[1] > 0)
                {
                    click[0]--;
                    click[1]--;
                    updateBoard(board,click);
                    click[0]++;
                    click[1]++;
                }
                if (click[0] > 0 && click[1] < board[0].size()-1)
                {
                    click[0]--;
                    click[1]++;
                    updateBoard(board,click);
                    click[0]++;
                    click[1]--;
                }
                return board;
            }
        }
        else return board;    
    }
};
