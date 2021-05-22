#include <bits/stdc++.h>

using namespace std;
int n, ans;
vector <int> myvec[1002][12];
string s;
bool check(int a, int b, int c, int d)
{
    for(int i = 0; i < n; i++)
    {
        if(!myvec[i][a].size()) return 0;
        if(!myvec[i][b].size()) return 0;
        if(!myvec[i][c].size()) return 0;
        if(!myvec[i][d].size()) return 0;
        int f = myvec[i][a][0];
        auto x = lower_bound(myvec[i][b].begin(), myvec[i][b].end(), f);
        if(x == myvec[i][b].end()) return 0;
        f = myvec[i][b][x - myvec[i][b].begin()];
        x = lower_bound(myvec[i][c].begin(), myvec[i][c].end(), f);
        if(x == myvec[i][c].end()) return 0;
        f = myvec[i][c][x - myvec[i][c].begin()];
        x = lower_bound(myvec[i][d].begin(), myvec[i][d].end(), f);
        if(x == myvec[i][d].end()) return 0;
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y >> s;
        for(int j = 0; j < y; j++)
        {
            myvec[i][s[j] - '0'].push_back(j);
        }

    }
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
        {
            for(int c = 0; c < 10; c++)
            {
                for(int d = 0; d < 10; d++)
                {
                    if(check(a, b, c, d)) ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
}
