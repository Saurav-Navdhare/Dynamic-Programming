#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<float> price(n), pages(n);
    for(int i=0; i<n; i++)
        cin >> price[i];

    for(int i=0; i<n; i++)
        cin >> pages[i];
/*
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // dp[i][j] = max value that can be attained from i elements such that j weight is allowed
    // base case dp[0][j] = 0, dp[i][0] = 0 because no weight is allowed
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<=x; j++){
            int weight = price[i-1];
            int page = pages[i-1];
            int pick = (j-weight>=0) ? dp[i-1][j-weight] + page : 0;
            int skip = dp[i-1][j];
            dp[i][j] = max(pick, skip);
        }
    
    cout << dp[n][x] << endl;
*/

    vector<int> dp(x+1, 0);
    for(int i=1; i<=n; i++){
        vector<int> curr(x+1);
            int w = price[i-1];
            int p = pages[i-1];
        for(int j=0; j<=x; j++){
            if(j-w>=0)
                curr[j] = max(dp[j-w] + p, dp[j]);
            else
                curr[j] = dp[j];
        }
        dp = curr;
    }
    
    cout << dp[x] << endl;

    
    return 0;
}