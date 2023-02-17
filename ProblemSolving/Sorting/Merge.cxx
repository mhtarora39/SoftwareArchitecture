#include<iostream>
#include<vector> 

void partition(std::vector<int>& arr, int start , int mid ,int end) {
    int right = mid+1;
    int left = start;
    //Here Assumption is that both the vectors are sorted
    //We can't do in place swapping as this will disturb the 
    //sorting of two partition
    std::vector<int> tmp_array;  
    while(start <= mid && right <= end) {
        if(arr[start] >=  arr[right]) {
            tmp_array.push_back(arr[right]);
            right++;
        }
        else {
            tmp_array.push_back(arr[start]);
            start++;
        }    
    }
    while(start <= mid) {
        tmp_array.push_back(arr[start]);
        start++;
    }
    while(right <= end) {
        tmp_array.push_back(arr[right]);
        right++;
    }
    int j = 0;
    for(int i = left;i <= end;i++) {
        arr[i] = tmp_array[j];
        j++;
    }

}

void merge(std::vector<int>& arr, int start, int end) {
    if(end - start < 1) {
        return;
    }
    int mid = (start + end) / 2;
    merge(arr,start,mid);    
    merge(arr,mid+1,end);
    partition(arr,start, mid,end);
}

int main() {
    std::vector<int> arr = {-1,4,-3,2,9,1,2,7,5,2};
    std::cout << "Input Array " << std::endl;
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }

    merge(arr,0,arr.size()-1);
    std::cout << "\n Sorted Array : \n"; 
    for(int i=0;i < arr.size(); i++) {
        std::cout<< arr[i] << " ";
    }
        
}