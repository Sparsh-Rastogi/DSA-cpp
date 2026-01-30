# Dynamic Programming

## Precomputation

### Prefix Sum
pfx array where pfx[i] = pfx[i-1]+v[i]

diff array where diff[i] = v[i]-v[i-1]

## KnapSack Problems

### Standard subset questions

for(int j=maxSum-v[i];j>=0;j--){
    dp[j+v[i]] += dp[j];
}

:dp[j] = number of subsets possible with sum j
