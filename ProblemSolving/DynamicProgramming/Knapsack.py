
def calculate(values,weight,idx,W,dp_map):

    if idx < 0:
        return 0
    
    if W < 0:
        return 0
    
    key = f"{idx}:{W}"
     
    if key in dp_map:
        return dp_map[key]

    
    dp_map[key] = max(values[idx] + calculate(values,weight,idx-1, W,dp_map),calculate(values,weight,idx-1, W - weight[idx] ,dp_map))
    
    return dp_map[key]


dp = {}
print(calculate([1,1,2,1,1],[1,2,2,1,1],4,5,dp))

print(dp)
