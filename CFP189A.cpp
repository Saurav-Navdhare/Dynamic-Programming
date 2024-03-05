#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n, a, b, c;
int maxRibb(int n, vector<int>& dp)
{
    if (n < 0) return -1e9;
    if (n == 0) return 0;
    if (dp[n]) return dp[n];

    return dp[n] = max({maxRibb(n - a, dp), maxRibb(n - b, dp), maxRibb(n - c, dp)}) + 1;
}

int main(){
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, 0);
    int res = maxRibb(n, dp);
    cout << res;
    return 0;
}