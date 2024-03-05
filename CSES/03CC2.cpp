#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
// wrong

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    
    for(int i=0; i<n; i++)
        dp[i][0]=1;
    
    for(int i=n-1;i>=0; i--)
        for(int sum=1; sum<=x; sum++){
            int skipping = dp[i+1][sum];
            int taking = (sum-coins[i]>=0) ? dp[i][sum-coins[i]] : 0;
            dp[i][sum] = (skipping + taking)%MOD;
        }

    cout << dp[0][x] << endl;
    
    return 0;
}