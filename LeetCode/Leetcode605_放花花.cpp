//
//  Leetcode605_放花花.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int last,now = 0,next = now+1,cal,sum=0;
        bool flag = false;
        for (int i = 0;i < flowerbed.size();i++)
        {
            if (flowerbed[now]==0)
            {
                if (now==0 && now!=flowerbed.size()-1)
                {
                    if (flowerbed[next]==0)
                    {
                        flowerbed[now] = 1;
                        sum++;
                    }
                }
                else if (now==flowerbed.size()-1 && now!=0)
                {
                    if (flowerbed[last]==0)
                    {
                        sum++;
                    }
                }
                else
                {
                    if (flowerbed[next]==0 && flowerbed[last]==0)
                    {
                        flowerbed[now] = 1;
                        sum++;
                    }
                }
            }
            else
            {
                if ((now!=flowerbed.size()-1 && flowerbed[next]==1) || (now!=0 && flowerbed[last]==1)) return false;
            }
            last = now;
            now = next;
            next++;
            if (sum >= n)
            {
                flag = true;
                break;
            }	
        }
        if (flowerbed.size()==1) sum = flowerbed[0];
        return flag;         
    }
};
