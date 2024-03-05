#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int maxn = 1e6+1;

vector<vector<int>> dp(1e6+1, vector<int>(2));
int main(){
    dp[0][0]=1;
    dp[0][1]=1;

    for(int i=1; i<maxn; i++){
        dp[i][0] = (2LL*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (4LL*dp[i-1][1] + dp[i-1][0])%MOD;
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (1LL*dp[n-1][0]+dp[n-1][1])%MOD << endl;
    }

    return 0;
}