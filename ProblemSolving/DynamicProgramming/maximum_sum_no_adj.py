def calculate(arr,idx,dp):

    if idx < 0:
        return 0
    
    if idx == 0:
        return arr[idx]
    
    if idx in dp:
        return dp[idx]
    
    dp[idx] = max(arr[idx], max(calculate(arr,idx-1,dp),arr[idx] + calculate(arr,idx-2,dp)))
    return dp[idx]

print(calculate([-5, -5, -10, 100, -10, -5],5,{}))


