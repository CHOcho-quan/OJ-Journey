//
//  SJTU1241_欢总GPA.cpp
//  
//
//  Created by 铨 on 2019/4/6.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp;
    double gpa = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        if (tmp >= 95) gpa+=4.3;
        else
        {
            if (tmp >=90) gpa+=4.0;
            else
            {
                if (tmp >= 85) gpa+=3.7;
                else
                {
                    if (tmp >= 80) gpa+=3.3;
                    else
                    {
                        if (tmp >= 75) gpa+=3.0;
                        else
                        {
                            if (tmp >= 70) gpa+=2.7;
                            else
                            {
                                if (tmp >= 67) gpa+=2.3;
                                else
                                {
                                    if (tmp >= 65) gpa+=2;
                                    else
                                    {
                                        if (tmp >= 62) gpa+=1.7;
                                        else gpa+=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(2) << gpa / n;
}
