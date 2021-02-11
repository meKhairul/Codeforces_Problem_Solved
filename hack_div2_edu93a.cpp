    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    const int MOD = 1e9+7;
    const int maxn = 50010;
    int n, a[maxn];
    string s;

    int main()
    {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int t = 1;
        cin >> t;
        while(t--)
        {
            cin >> n;
            for(int i = 0; i < n; i++) cin >> a[i];
            for(int i = 0; i < n-1; i++)
            {
                for(int j = i+1; j < n-1; j++)
                {
                    if(a[i]+a[j]<=a[n-1])
                    {
                        cout << i+1 << " " << j+1 << " " << n << "\n";
                        goto cont;
                    }
                }
            }
            cout << -1 << "\n";
            cont: continue;
        }
    }
