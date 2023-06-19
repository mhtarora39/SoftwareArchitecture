#include <unordered_map>
#include <iostream>
#include <vector>

// 3, 10, 2, 1 , 20

int findMaxSub(std::vector<int>& arr, int prev_idx, int current_idx, int& count,std::unordered_map<int,int>& dp) {
    if(current_idx >= arr.size()) {
        return 0;
    }
    if(dp.find(current_idx) != dp.end()) {
        return dp[current_idx];
    }
    int tmp = current_idx;
    if(arr[prev_idx] < arr[current_idx]) {
        tmp = ++current_idx;
        current_idx = prev_idx;
        count++;
        dp[tmp] =  1 + findMaxSub(arr,current_idx,tmp,count,dp);
    }
    else {
        dp[tmp] =  std::max(count,findMaxSub(arr,prev_idx,++current_idx,count,dp));
    }

    return dp[tmp];

}

int main() {
    std::vector<int> arr = {3,10,2,34,1,20};
    int count = 0;
    std::unordered_map<int,int> dp;
    int res =  findMaxSub(arr,0,1,count,dp);
    std::cout << "NUMs = " << count << std::endl;

}