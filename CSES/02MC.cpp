#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, x;

int main(){
    cin >> n >> x;
    vector<long long> coins(n), dp(x+1, INT_MAX);
    for(int i=0; i<n; i++) cin >> coins[i];
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int weight = 0; weight <= x; weight++)
			if (weight - coins[i - 1] >= 0) 
				dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);

	cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
    return 0;
}