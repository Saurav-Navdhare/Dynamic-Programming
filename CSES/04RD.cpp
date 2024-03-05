#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recur(int n, vector<int>& dp){
    if(dp[n]!=INT_MAX) return dp[n];
    string s = to_string(n);
    for(int i=0; i<s.length(); i++)
        dp[n] = min(dp[n], recur(n-(s[i]-'0'), dp)+1);
    return dp[n];
}

int main(){
    // dp[n] = no of steps to get to 0 from n
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[0]=0;
    recur(n, dp);
    cout << dp[n] << endl;
    return 0;
}