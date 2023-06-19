#include <vector>

int count_steps(int target,int step ,std::vector<int>& steps_array, std::map<int,int>& dp ) {

    if(target  == 0) 
    {
        return 1;
    }
    if(target < 0) 
    {
        return 0;
    }
    if(dp.find(step) != dp.end()) 
    {
        return dp[step];
    }
    int count = 0; 
    for( int i = 0; i < steps_array.size()l; i++) {
        count += count_steps(n - steps_array[i],steps_array[i],steps_array,dp); 
        dp[steps_array[i]] = count;
        total_count += count;
    }
    return total_count;
}