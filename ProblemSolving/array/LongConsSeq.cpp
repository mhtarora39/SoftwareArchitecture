
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/

#include <vector>
#include <unordered_set>
#include <iostream>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> for_search;
    for(int num : nums) {
        for_search.insert(num);
    }
    int max_len = 0;
    int count = 0;
    for(auto num : for_search) {
        if(for_search.find(num-1) == for_search.end()) {
            count++;
            while(true) {
                if(for_search.find(++num) != for_search.end()) {
                    count++;
                }
                else {
                    break;
                }
            }
            
        }
        if(max_len < count) {
            max_len = count;
        }
        count = 0;
    }
    return max_len;
}


int main() {
    std::cout << "Longest Consecutive of {1,0,3,2,4,6,7,8,9,10} : " << longestConsecutive({1,0,3,2,4,6,7,8,9,10}) << std::endl;
}
