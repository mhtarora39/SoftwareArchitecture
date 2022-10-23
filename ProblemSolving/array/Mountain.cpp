//  You may recall that an array arr is a mountain array if and only if:

//     - arr.length >= 3
//     - There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//         - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//         - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

//     Given an integer array arr, return the length of the longest subarray, which is a    mountain. Return 0 if there is no mountain subarray.

#include <iostream>
#include <vector>

int findMountainWidth(std::vector<int>& arr) {
     if(arr.size() <= 2) {
            return 0;
        }
        int size = arr.size();
        int max_length = 0;
        std::vector<int> peak_indexes;
        /*
        Idea: Find all the lows. Mountain width always will be difference
        between the two lows.  
        */
 
        for(int i = 1; i <size -1; i++) {
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                peak_indexes.push_back(i);
            }
        }
        

        
        if(peak_indexes.size() > 0) {
            for(int idx :  peak_indexes) {
                int left = idx - 1;
                int right = idx + 1;
            
                
                while(left > 0) {
                    if(arr[left-1] < arr[left]) {
                        left--;
                    }
                    else {
                        break;
                    }
                }
                
                while(right < size) {
                     if(arr[right-1] > arr[right]) {
                        right++;
            
                    }
                    else {
                        break;
                    }
                    
                }
                
                
                right--;
              
                                       
            
                
                if(max_length < right-left+1) {
                    max_length = right-left+1;
                }
            }
        }
        
        
     return max_length;
        
    }
}

int main() {
    std::vector<int> arr {2,2,2};
    std::cout << "Max Width:"  << findMountainWidth(arr) << std::endl;
}