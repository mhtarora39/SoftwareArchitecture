#include <vector>
#include <iostream>

int partition_index(std::vector<int> &array, int start, int end)
{

    int i = start - 1;
    int j = start;
    int pivot = array[end];
    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i+1],array[end]);
    return i+1;

}

int QuickSelect(std::vector<int> &array, int start, int end, int index)
{
    if(end - start <= 0) {
      return array[start];
    }
    int part_index = partition_index(array,start,end);
    if(part_index == index) {
        return array[part_index];
    }
    if(part_index > index) {
        return QuickSelect(array,start,part_index-1,index);
    }
    else {
        return QuickSelect(array,part_index+1,end,index);
    }
}

int main() {
    std::vector<int> array = {10,5,2,0,7,6,4};
    std::cout << "Value Should Be 5 , Result : " <<  QuickSelect(array,0,array.size()-1,3) << std::endl;
}
