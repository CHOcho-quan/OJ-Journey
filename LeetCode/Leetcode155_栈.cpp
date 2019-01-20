//
//  Leetcode155_栈.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class MinStack {
private:
    vector<int> a;
    int min;
    int min_index;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = 2147483647;
        min_index = 0;
    }
    
    void push(int x) {
        a.insert(a.begin(),x);
        bool flag = false;
        if (a.size()==1)
        {
            min_index = 0;
            min = x;
            flag = true;
        }
        if (!flag)
        {
            if (x < min)
            {
                min_index = 0;
                min = x;
            }
            else
            {
                min_index++;
            }
        }
    }
    
    void pop() {
        bool flag = false;
        if (min_index==0)
        {
            if (a.size()>1) {min = a[1];min_index = 1;}
            else flag = true;
            for (int j = 1;j < a.size();j++)
            {
                if (flag) break;
                if (a[j] < min)
                {
                    min = a[j];
                    min_index = j;
                }
            }
        }
        else min_index--;
        a.erase(a.begin());
        if (min_index > 0)min_index--;
    }
    
    int top() {
        return a[0];
    }
    
    int getMin() {
        return min;
    }
};
