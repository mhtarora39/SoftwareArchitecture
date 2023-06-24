def toPalindrome(subStr,start,end,dp_map):

    if start >= end:
        return 0
    
    key = f'{start} | {end}'
    
    if key in dp_map:
        return dp_map[key]
    
    if subStr[start] ==  subStr[end]:
        dp_map[key] = toPalindrome(subStr,start+1,end-1,dp_map)
    
    else:
        dp_map[key] = 1 + min(toPalindrome(subStr,start,end-1,dp_map) , toPalindrome(subStr,start+1,end,dp_map))
    
    return dp_map[key]

if __name__ == "__main__":
    Str = "abefbac"
    dp_map = {}
    print("Minimum element of deletions 2 == ",toPalindrome(Str,0,len(Str)-1,dp_map))
    Str = "ACBCDBAA"
    print("Minimum element of deletions 3 == ",toPalindrome(Str,0,len(Str)-1,dp_map))

 
