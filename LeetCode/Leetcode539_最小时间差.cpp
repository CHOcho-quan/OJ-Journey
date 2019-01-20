//
//  Leetcode539_最小时间差.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int minus_time(string a1,string a2)
{
    int time_a1 = ((a1[0]-'0')*10 + (a1[1]-'0'))*60 + (a1[3]-'0')*10 + (a1[4]-'0');
    int time_a2 = ((a2[0]-'0')*10 + (a2[1]-'0'))*60 + (a2[3]-'0')*10 + (a2[4]-'0');
    
    return abs(time_a1 - time_a2);
}


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        for (int i = 0;i < timePoints.size();i++)
        {
            if (timePoints[i][0]=='0')
            {
                string ss = "";
                switch(timePoints[i][1])
                {
                    case '0':
                    {
                        ss+="24:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '1':
                    {
                        ss+="25:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '2':
                    {
                        ss+="26:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '3':
                    {
                        ss+="27:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '4':
                    {
                        ss+="28:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '5':
                    {
                        ss+="29:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '6':
                    {
                        ss+="30:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    case '7':
                    {
                        ss+="31:";
                        ss+=timePoints[i][3];
                        ss+=timePoints[i][4];
                        break;
                    }
                    default: break;
                }
                if (ss!="")timePoints.push_back(ss);
            }
        }
        for (int i = 0;i < timePoints.size();i++) cout << timePoints[i] << ' ';
        sort(timePoints.begin(),timePoints.end());
        int min = 2147483647;
        for (int i = 1;i < timePoints.size();i++)
        {
            cout << min << endl;
            if (minus_time(timePoints[i],timePoints[i-1]) < min) min = minus_time(timePoints[i],timePoints[i-1]);
        }
        return min; 
    }
};
