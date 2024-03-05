#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    for(int i=0; i<=min(n, m); i++)
        dp[i][i]=0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            // vertical cut
            for(int k=1; k<i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            
            // horizontal cut
            for(int k=1; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            
        }    

    cout << dp[n][m] << endl;

    return 0;
}