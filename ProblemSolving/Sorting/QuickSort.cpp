#include <vector>
#include <iostream>


int partition_a(std::vector<int>& array,int start_idx, int end_idx) {

    int pivot_idx = end_idx;
    int pivot = array[pivot_idx];
    int left  = start_idx;
    int right = pivot_idx - 1;
    while(left <= right) {
        if(array[right] >= pivot) {
            right--;
        }
        else{
            while(array[left] < pivot) {
                left++;
            }
            if(left < right) {
                std::swap(array[left],array[right]);
                left++;
                right--;
            }
        }
    }
    std::swap(array[pivot_idx],array[right+1]);
    return right+1;

}

void quick_sort(std::vector<int>& array,int start_idx, int end_idx) 
{
    if(array.size() <= 1) {
        return;
    }

    int part_idx = partition_a(array,start_idx,end_idx);
    if (part_idx > 0) {
       quick_sort(array,0,part_idx-1); 
    }
    if(part_idx < array.size() -1) {
       quick_sort(array,part_idx+1,array.size()-1);
    } 
    

}

int main() {
    std::vector<int> arr = {-1,4,-3,2,9,1,2,7,5,2};
    std::cout << "Input Array " << std::endl;
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }

    quick_sort(arr,0,arr.size()-1);
    std::cout << "\n Sorted Array : \n"; 
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }       
}