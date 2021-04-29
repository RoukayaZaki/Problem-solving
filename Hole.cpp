#include <bits/stdc++.h>

using namespace std;
const int N = 1030;
int n, k, a[N][N], pref[N][N], ans;
bool check(int i, int j, int l)
{
    if((i + l - 1) > n || (j + l - 1) > n) return 0;
    if(pref[i + l - 1][j + l - 1] - pref[i + l - 1][j - 1] - pref[i - 1][j + l - 1] + pref[i - 1][j - 1] == 0) return 1;
    return 0;
}
int solve(int i, int j)
{
    int s = 1, e = n, mid, m = -1;
    while(s <= e)
    {
        mid = (s + e) >> 1;
        if(check(i, j, mid))
        {
            m = max(m, mid);
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return m;
}
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x + 1][y + 1] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans = max(ans, solve(i, j));
        }
    }
    printf("%d\n", ans);
}
