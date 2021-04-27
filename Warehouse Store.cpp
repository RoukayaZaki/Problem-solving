#include <bits/stdc++.h>

using namespace std;
long long n, ans, a[2][250001], sum;
bool vis[250001];
priority_queue <pair <long long, long long> > pq;
void scan(int x)
{
    for(long long i = 0; i < n; i++)
    {
        scanf("%lld", &a[x][i]);
    }
}
int main()
{
    scanf("%lld", &n);
    scan(0);
    scan(1);
    for(long long i = 0; i < n; i++)
    {
        sum += a[0][i];
        long long x = a[1][i];
        if(sum >= x)
        {
            sum -= x;
            vis[i] = 1;
            pq.push(make_pair(x, i));
            ans++;
        }
        else if(!pq.empty())
        {
            if(pq.top().first > x)
            {
                sum += pq.top().first - x;
                vis[pq.top().second] = 0;
                pq.pop();
                pq.push(make_pair(x, i));
                vis[i] = 1;
            }
        }
    }
    printf("%lld\n", ans);
    for(long long i = 0; i < n; i++)
    {
        if(vis[i])
        {
            printf("%lld ", i + 1);
        }
    }
    puts("");
}
