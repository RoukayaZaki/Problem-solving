#include <bits/stdc++.h>

using namespace std;
int n, k, R, mn = 200001, cnt, a[200001], l, r, b, c, vis[200001];
map <int, int> mp;
bool flag[200001], check;
int main()
{
    scanf("%d %d %d", &n, &k, &R);
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < R; i++)
    {
        scanf("%d %d", &b, &c);
        vis[b] = c;
    }int i = 0;
    while(l < n && i < n)
    {
    //cout << "HERE\n";
    i++;
        while(cnt < R && r < n)
        {
            mp[a[r]]++;
            if(mp[a[r]] >= vis[a[r]] && vis[a[r]] != -1 && flag[a[r]] == 0)
            {
                cnt++;
                //cout << a[r] << ' ' << r << '\n';
                flag[a[r]] = 1;
            }
            r++;
        }
        while(cnt >= R)
        {
            mn = min(mn, r - l);
            check = 1;
            mp[a[l]]--;
            if(mp[a[l]] < vis[a[l]] && vis[a[l]] != -1 && flag[a[l]])
            {
                cnt--;
                flag[a[l]] = 0;
            }
            l++;
        }

    }
    if(check)
    printf("%d\n", mn);
    else puts("impossible");
}
