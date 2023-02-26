#include <iostream>
#include <vector>
#include <string>

int sparse_search(const std::vector<std::string> &array, int index, std::string target)
{
    int start = index;
    if (index < 0 || index >= array.size())
    {
        return -1;
    }    
    while (start >= 0)
    {
        if (array[start] != "" && array[start] >= target)
        {
            break;
        }
        start--;
    }
    if (start < 0)
    {
        start = index;
        while (start < array.size())
        {
            if (array[start] != "" && array[start] <= target)
            {
                break;
            }
            start++;
        }
    }

    if (start >= 0 || start < array.size())
    {
        index = start;
    }
    if (array[index] == target)
    {
        return index;
    }

    if (array[index] < target)
    {
        return sparse_search(array, index + 1, target);
    }
    else
    {
        return sparse_search(array, index - 1, target);
    }
}

int main()
{
    std::vector<std::string> array = {"ai", "", "", "bat", "", "", "", "car"};
    std::cout << "Index should be 0, Got " << sparse_search(array, array.size() / 2, "ai") << std::endl;
    std::cout << "Index should be 7, Got " << sparse_search(array, array.size() / 2, "car") << std::endl;
    std::cout << "Index should be 3, Got " << sparse_search(array, array.size() / 2, "bat") << std::endl;
    std::cout << "Index should be -1, Got " << sparse_search(array, array.size() / 2, "t") << std::endl;
}