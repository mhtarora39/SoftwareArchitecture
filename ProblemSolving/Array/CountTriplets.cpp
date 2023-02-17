#include <vector>
#include <iostream>
#include <algorithm>

#define TwoDArray  std::vector<std::vector<int>>

/*

Given an array of N integers, and a number sum, the task is to find the number of triplets of integers in the array whose sum is equal to sum.
Conditions:
- All the numbers in the triples should be sorted.
- All the triples should be sorted.

*/


TwoDArray GetPairs(const std::vector<int>& array, int targetSum , int left ,int right) {
    TwoDArray pairs;
    while(left < right) {
        int sum = array[left] + array[right];
        if(sum == targetSum) {
          pairs.push_back({array[left] , array[right]});
          left++;
          right--;   
        }
        else if(sum < targetSum) {
            left++;
        }
        else {
            right--;
        }
    }
    return pairs;
 
}

TwoDArray GetTriplets(std::vector<int> array, int targetSum) {

    // Approach 1:
    // Traverse  Array => for each new_sum  = target - curr_element find pair of 2. 
    // Then Sort each array in triplets. 
    // Time and Space Complexity O(N^2) and O(N)

    // But given that sort algorithm is already N*log(N) which is less then 
    // N*N So we can sort the array first then find the array without using any space.


    // Approach 2:
    // Step 1: Sort the array.
    // Step 2: Find the pair for remaining elements
    // Time and Space Complexity O(N^2) and O(1)
    std::sort(array.begin(),array.end());
    TwoDArray triplets;
    for(int i = 0; i < array.size(); i++ ) {
        auto pairs = GetPairs(array,targetSum - array[i],i+1,array.size()-1);
        for(const auto& pair : pairs) {
            triplets.push_back({array[i],pair[0],pair[1]});
        }
    }
    return triplets;
}
  


int main() {
  std::vector<int> arr {1,2,3,4,5,6,7,8,9,15};
  //std::cout << "Total number of triplets. " << countPairs(arr,5) << std::endl;
  auto triplets = GetTriplets(arr,18);
  for(auto& triple : triplets) {
    std::cout << "Triples : " << triple[0] << "," << triple[1] <<","<<  triple[2] << std::endl; 
  }

}
