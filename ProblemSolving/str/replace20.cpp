#include <iostream>

std::string replace(std::string src, std::string from, std::string to)
{

    // Hi My Name is Mohit  -->  Calculate new space
    int found = 0;

    // Calculate How many sub string are there
    for (int i = 0; i < src.size(); i++)
    {
        if (src.substr(i, from.size()) == from)
        {
            found++;
        }
    }

    int prev_len = src.size();

    int new_len = src.size() + found * (abs(to.size() - from.size()));
    src.resize(new_len);
    int new_index = new_len - 1;
    for (int i = prev_len - 1; i >= 0; i--)
    {
        //Search for substring.
        if (src.substr(i, from.size()) == from)
        {
            for (int j = to.size() - 1; j >= 0; j--)
            {
                src[new_index - j] = to[to.size() - 1 - j];
            }
            new_index = new_index - to.size();
        }
        else
        {
            //else copy the string to new index.
            src[new_index] = src[i];
            new_index--;
        }
    }
    return src;
}

int main()
{
    std::string newString = "My Name is Mohit";

    std::cout << " In String '" << newString << "' Replaced String: " << replace(newString," ","%20") << std::endl;
}