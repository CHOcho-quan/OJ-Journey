#include <iostream>
#include <map>

using namespace std;

int dfs(int* map, int &result)
{
    for (int i = 0;i < 26;i++)
    {
        if (map[i])
        {
            map[i]--;
            result++;
            dfs(map, result);
            map[i]++;
        }
    }

    return result;
}

int numTilePossibilities(string tiles) 
{
    int map[26] = {0};
    int result = 0;
    for (auto tile : tiles) map[(tile - 'A')] += 1;
    //for (int i = 0;i < 26;i++) cout << map[i] << ' ';

    dfs(map, result);
    return result;
}

int main()
{
    cout << numTilePossibilities("AAABBC");
}