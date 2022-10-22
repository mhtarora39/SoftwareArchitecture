#include <set>
#include <vector>
#include <iostream>


/*
Given an array of N integers, and a number sum, the task 
is to find the number of pairs of integers in the array 
whose sum is equal to sum.
*/

int countPairs(const std::vector<int>& array,int targetSum) {

// Algo

//1) Check complement number exists in set ?
//2) If no add it to set.
//3) If exist count it as pair.

//Code
    int count = 0;
    std::set<int> keeper;
    for(const int& ele : array) {
        int number = targetSum - ele;
        if(keeper.find(ele) != keeper.end()) {
            count++;
        }
        else {
            keeper.insert(number);
        }
    }

    return count;

// Learning :

// First adding to the sets there will be case of number can count it self as valid pair.
// And each number will be counted twice.

}
int main() {
  std::vector<int> arr {1,2,-3,8,3};
  std::cout << "Total number of pairs. " << countPairs(arr,5) << std::endl;
}