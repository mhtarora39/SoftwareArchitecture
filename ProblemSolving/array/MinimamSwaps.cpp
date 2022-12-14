#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

/*
You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] 
without any duplicates. You are allowed to swap any two elements. 
Find the minimum number of swaps required to sort the array in ascending order.
*/


/*
IDEA : Compare with correct postion 
*/
int minimumSwaps(std::vector<int> arr) {
    std::unordered_map<int,int> elements;
    std::vector<int> tmp_vector{arr.begin(),arr.end()};
    std::sort(tmp_vector.begin(),tmp_vector.end());
    for(int i = 0; i  < tmp_vector.size(); i++) {
        elements[tmp_vector[i]] = i; 
    }
  
    auto swap = [](int i,int j,std::vector<int>& array) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    };
     
    int count = 0;
    for(int current_pos = 0; current_pos < arr.size(); current_pos++)
    {
        while(elements[arr[current_pos]] != current_pos) {
            int expected_pos = elements[arr[current_pos]];
            swap(current_pos,expected_pos,arr);
            count++;
        } 
    }

    return count;

}

int main() {
    std::cout << "Minimum Swaps : " << minimumSwaps({10,11,5,4,3,2,1}) << " Expected 4 " << std::endl;
}
