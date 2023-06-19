

def coinChange(coins:list,idx,sum,sol_store):
  '''
  - 1) i can use one at time coin and store the results.
    2) When ever sum == 0  that means we have found the solution so return 1
    3) If sum went less the 0 that means invalid sol so return 1
    4) sum of either using this coin only or add next coin  
  '''

  if(idx >= len(coins)):
    return 0

  if sum == 0:
    return 1
  
  if sum < 0:
    return 0 

  sol =  coinChange(coins,idx,sum - coins[idx],sol_store) + \
         coinChange(coins,idx+1,sum,sol_store)
  return sol


if __name__ == "__main__":
  memo = {}
  coins = coinChange([1,2,3],0,4,memo)
  print("Total coins : ",coins)