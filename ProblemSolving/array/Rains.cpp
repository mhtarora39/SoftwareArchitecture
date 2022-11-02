#include <iostream>
#include <vector>

/*
Hint :

Idea Here To find bound for every point in array.
That can be done by finding max from when we are traveling left to right
as well as when we are traveling right to left.

*/
using namespace std;
int trap(vector<int> &height)
{

    const int size = height.size();

    vector<int> left_max_height(size), right_max_height(size);

    left_max_height[0] = height[0];
    right_max_height[size - 1] = height[size - 1];
    for (int i = 1; i < size; i++)
    {
        left_max_height[i] = max(left_max_height[i - 1], height[i]);
        right_max_height[size - i - 1] = max(right_max_height[size - i], height[size - i - 1]);
    }

    int total_water = 0;
    for (int i = 0; i < size; i++)
    {
        total_water += min(left_max_height[i], right_max_height[i]) - height[i];
    }
    return total_water;
}

int main() {
    vector<int> res{4,2,0,3,2,5};
    std::cout << " Total Water " << trap(res) << std::endl;
}