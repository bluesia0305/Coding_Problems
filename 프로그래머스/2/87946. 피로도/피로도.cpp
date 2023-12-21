#include <string>
#include <vector>

using namespace std;

int Count;

void Play(int k, const vector<vector<int>>& dungeons, bool* const played, int idx, int cnt)
{
    if (!played[idx] && k >= dungeons[idx][0])
    {
        played[idx] = true;
        for (int i = 0; i < dungeons.size(); i++)
            Play(k - dungeons[idx][1], dungeons, played, i, cnt + 1);
        played[idx] = false;
    }
    else
    {
        if (Count < cnt)
            Count = cnt;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        bool played[8] = { 0, };
        Play(k, dungeons, played, i, 0);
    }    
    
    return Count;
}