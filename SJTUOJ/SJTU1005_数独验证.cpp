//
//  SJTU1005_数独验证.cpp
//  
//
//  Created by 铨 on 2019/1/17.
//
//

#include <iostream>
#include <set>

using namespace std;

bool isRight(int **sudoku) {
    set<int> s;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 9;j++) {
            for (int m = i * 3;m < (i+1)*3;m++) {
                s.insert(sudoku[j][m]);
                //                cout << sudoku[j][m] << ' ';
            }
            
            if ((j + 1) % 3 == 0) {
                //                cout << endl;
                if (s.size()!=9) return false;
                s.clear();
            }
        }
        //        if (s.size()!=9) return false;
        //        s.clear();
    }
    return true;
}

int main()
{
    int n;
    int **sudoku;
    cin >> n;
    sudoku = new int*[9];
    bool checkFlag = false;
    for (int i = 0;i < 9;i++) sudoku[i] = new int[9];
    set<int> s, ss;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < 9;j++) {
            for (int m = 0;m < 9;m++){
                cin >> sudoku[j][m];
            }
        }
        
        for (int j = 0;j < 9;j++) {
            for (int m = 0; m < 9; m++) {
                s.insert(sudoku[j][m]);
                ss.insert(sudoku[m][j]);
            }
            //            cout << s.size();
            if (s.size() != 9) {
                cout << "Wrong"<<endl;
                checkFlag = true;
                break;
            }
            if (ss.size() != 9) {
                cout << "Wrong"<<endl;
                checkFlag = true;
                break;
            }
            s.clear();
            ss.clear();
        }
        
        if (checkFlag) {
            checkFlag = false;
            s.clear();
            ss.clear();
            continue;
        }
        
        s.clear();
        ss.clear();
        //        cout << "laile!";
        
        if (isRight(sudoku)) cout << "Right" << endl;
        else cout << "Wrong" << endl;
    }
}
