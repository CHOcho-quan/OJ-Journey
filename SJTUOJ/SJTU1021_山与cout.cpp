//
//  SJTU1021_山与cout.cpp
//  
//
//  Created by 铨 on 2019/1/18.
//
//

#include <iostream>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int **a;
    a = new int*[n];
    for (int i = 0;i < n;i++) a[i] = new int[n];
    
    int t = 0, x = 0, y = 0, c = 1, way = 2, bx = n, by = n;
    while (t < n*n)
    {
        a[y][x] = c;
        t++;
        switch (way)
        {
            case 2: {
                //                cout << 2;
                c++;
                if (x < bx-1) x += 1;
                else {
                    y += 1;
                    way = 4;
                    //                    by -= 1;
                }
                break;
            }
            case 4: {
                //                cout << 4;
                c++;
                if (y < by-1) y+=1;
                else {
                    x -= 1;
                    way = 3;
                    //                    bx -= 1;
                }
                break;
            }
            case 3:{
                //                cout << 3;
                c++;
                if (x > n-bx) x -= 1;
                else {
                    y -= 1;
                    way = 1;
                    by -= 1;
                }
                break;
            }
            case 1: {
                //                cout << 1;
                c++;
                if (y > n-by) y-= 1;
                else {
                    x += 1;
                    way = 2;
                    bx -= 1;
                }
                break;
            }
        }
        //        cout << x << ' ' << y << endl;
    }
    
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }
}
