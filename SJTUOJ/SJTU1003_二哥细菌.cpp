//
//  SJTU1003_二哥细菌.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>

using namespace std;

int FullCell(int L, int **cells)
{
    int result = 0;
    bool breakFlag = true;
    while(1)
    {
        result++;
        for (int i = 0;i < L;i++)
        {
            for (int j = 0;j < L;j++)
            {
                if (cells[i][j]==1){
                    if (i-1 > 0 && cells[i-1][j] == 0) cells[i-1][j] = 1;
                    if (i+1 < L && cells[i+1][j] == 0) cells[i+1][j] = 1;
                    if (j+1 < L && cells[i][j+1] == 0) cells[i][j+1] = 1;
                    if (j-1 > 0 && cells[i][j-1] == 0) cells[i][j-1] = 1;
                }
                else {
                    if (cells[i][j]==0) breakFlag = false;
                    continue;
                }
            }
        }
        
        if (breakFlag) return result;
        else breakFlag = true;
    }
}

int main()
{
    int L;
    int **cells;
    cin >> L;
    cells = new int *[L];
    for (int i = 0;i < L;i++) cells[i] = new int[L];
    for (int i = 0;i < L;i++) {
        for (int j = 0;j < L;j++) {
            cin >> cells[i][j];
        }
    }
    
    //    cells[0][1] = 100;
    
    //    for (int i = 0;i < L;i++) {
    //        for (int j = 0;j < L;j++) {
    //            cout << cells[i][j] << ' ';
    //        }
    //        cout << endl;
    //    }
    
    
    int result = 0;
    bool breakFlag = true, resultFlag = false;
    while(1)
    {
        for (int i = 0;i < L;i++)
        {
            for (int j = 0;j < L;j++)
            {
                if (cells[i][j]==1){
                    if (i-1 >= 0 && cells[i-1][j] == 0) {
                        resultFlag = true;
                        cells[i-1][j] = 3;
                        //                        cout << i-1 << ' ' << j << endl;
                    }
                    
                    if (i+1 < L && cells[i+1][j] == 0) {
                        resultFlag = true;
                        cells[i+1][j] = 3;
                        //                        cout << i+1 << ' ' << j << endl;
                    }
                    
                    if (j+1 < L && cells[i][j+1] == 0) {
                        resultFlag = true;
                        cells[i][j+1] = 3;
                    }
                    
                    if (j-1 >= 0 && cells[i][j-1] == 0) {
                        resultFlag = true;
                        cells[i][j-1] = 3;
                    }
                    
                }
                else {
                    if (cells[i][j]==0) breakFlag = false;
                    continue;
                }
            }
        }
        
        if (resultFlag) {
            result++;
            resultFlag = false;
        }
        
        for (int i = 0;i < L;i++) {
            for (int j = 0;j < L;j++) {
                if (cells[i][j] == 3) cells[i][j] = 1;
            }
        }
        
        if (breakFlag) {
            cout << result;
            break;
        }
        else breakFlag = true;
    }
}
