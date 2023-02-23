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

int partition_clrs(std::vector<int>& array,int start_idx, int end_idx) {
    int i = start_idx-1;
    int pivot = array[end_idx];
    for(int j = start_idx; j < end_idx; j++) {
        if(array[j] < pivot) {
            i++;
            std::swap(array[i],array[j]);
        }
    }
    std::swap(array[i+1] , array[end_idx]);
    return i+1;
}

void quick_sort(std::vector<int>& array,int start_idx, int end_idx) 
{
    if(start_idx >= end_idx) {
        return;
    }

    int part_idx = partition_clrs(array,start_idx,end_idx);
    quick_sort(array,start_idx,part_idx-1);
    quick_sort(array,part_idx+1,end_idx); 

}

int main() {
    std::vector<int> arr = {10,5,2,0,7,6,4};
    std::cout << "Input Array " << std::endl;
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }

    quick_sort(arr,0,arr.size()-1);
    std::cout << "\n Sorted Array : \n"; 
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }
    std::cout<< "\n";
}