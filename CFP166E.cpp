#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int TOP = 1;
const int BOTTOM = 0;
const int MOD = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<vector<long long>> dp(2, vector<long long>(n+1, 0));
    dp[BOTTOM][0] = 0;
    dp[TOP][0] = 1;
    for(int i=1; i<=n; i++) {
        dp[TOP][i] = 3*dp[BOTTOM][i-1]%MOD;
        dp[BOTTOM][i] = (2*dp[BOTTOM][i-1]%MOD+dp[TOP][i-1])%MOD;
    }
    cout << dp[TOP][n];
    return 0;
}