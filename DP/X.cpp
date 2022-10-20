/*
Dp and space optimisation
*/
#include <bits/stdc++.h>
using namespace std;
// -------------------- Input Checker Start --------------------

long long readInt(long long l, long long r, char endd)
{
    long long x = 0;
    int cnt = 0, fi = -1;
    bool is_neg = false;
    while(true)
    {
        char g = getchar();
        if(g == '-')
        {
            assert(fi == -1);
            is_neg = true;
            continue;
        }
        if('0' <= g && g <= '9')
        {
            x *= 10;
            x += g - '0';
            if(cnt == 0)
                fi = g - '0';
            cnt++;
            assert(fi != 0 || cnt == 1);
            assert(fi != 0 || is_neg == false);
            assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
        }
        else if(g == endd)
        {
            if(is_neg)
                x = -x;
            if(!(l <= x && x <= r))
            {
                cerr << "L: " << l << ", R: " << r << ", Value Found: " << x << '\n';
                assert(false);
            }
            return x;
        }
        else
        {
            assert(false);
        }
    }
}

string readString(int l, int r, char endd)
{
    string ret = "";
    int cnt = 0;
    while(true)
    {
        char g = getchar();
        assert(g != -1);
        if(g == endd)
            break;
        cnt++;
        ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}

long long readIntSp(long long l, long long r) { return readInt(l, r, ' '); }
long long readIntLn(long long l, long long r) { return readInt(l, r, '\n'); }
string readStringSp(int l, int r) { return readString(l, r, ' '); }
string readStringLn(int l, int r) { return readString(l, r, '\n'); }
void readEOF() { assert(getchar() == EOF); }

vector<int> readVectorInt(int n, long long l, long long r)
{
    vector<int> a(n);
    for(int i = 0; i < n - 1; i++)
        a[i] = readIntSp(l, r);
    a[n - 1] = readIntLn(l, r);
    return a;
}

// -------------------- Input Checker End --------------------

int main() {
	int t;
	t = readIntLn(1, 100);
	int smn = 0;
	while(t--) {
	    int n;
	    n = readIntLn(1, 100);
	    smn += n;
	    assert(smn <= 100);
	    int r[n], b[n];
	    for(int i = 0; i < n - 1; i++) r[i] = readIntSp(1, 200);
	    r[n - 1] = readIntLn(1, 200);
	    for(int i = 0; i < n - 1; i++) b[i] = readIntSp(1, 200);
	    b[n - 1] = readIntLn(1, 200);
	    int dp[n][n*200 + 1];
	    memset(dp, -1, sizeof(dp));
	    dp[0][0] = b[0];
	    dp[0][r[0]] = 0;
	    for(int i = 0; i < n - 1; i++) {
	        for(int j = 0; j <= n*200 - r[i + 1]; j++)
	            dp[i + 1][j + r[i + 1]] = dp[i][j];
	        for(int j = 0; j <= n*200; j++)
	        if(dp[i][j] > -1)
	            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + b[i + 1]);
	    }
	    int ans = 0;
	    for(int j = 0; j <= n*200; j++) ans = max(ans, min(j, dp[n - 1][j]));
	    cout << ans << "\n";
	}
	return 0;
}
