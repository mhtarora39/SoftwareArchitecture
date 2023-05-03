/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input Format

You will be given matrix of 0's and 1's

Constraints

1 <= len(grid), len(grid[0]) <= 300
grid[i][j] is '0' or '1'.

Output Format

Return the number of Island

Sample Input 0
*/
#include <iostream>
#include <vector>

constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {1, -1, 0, 0};

void dfs(std::vector<std::vector<int>> &island, int x_, int y_)
{
    for (int i = 0; i < 4; i++)
    {
        int x = x_ + dx[i];
        int y = y_ + dy[i];

        if (x >= island.size() || x < 0 || y >= island[0].size() || y < 0 || island[x][y] == -1 || island[x][y] == 0)
        {
            continue;
        }
        island[x][y] = -1;
        dfs(island, x, y);
    }
}

std::string print(std::vector<std::vector<int>> island)
{
    for (auto &clm : island)
    {
        std::cout << " \n";
        for (auto &ele : clm)
        {
            std::cout << ele << " ";
        }
    }
    std::cout << "\n--------------\n";
    return "";
}

int countIsland(int n, int m, std::vector<std::vector<int>> island)
{
    // step 1) I iterate through all the nodes in matrix
    int num_island = 0;
    // step 2) If node is not visited mark visited and make count = count + 1
    // print(island);
    for (int i = 0; i < island.size(); i++)
    {
        // std::cout << "Before";
        // print(island);
        for (int j = 0; j < m; j++)
        {
            if (island[i][j] != -1 && island[i][j] != 0)
            {
                island[i][j] = -1;
                num_island++;
                // step 3) Do depth first search from each node and mark all the neighbors visited
                dfs(island, i, j);
            }
        }
    }
    return num_island;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1,1,1,1,0,},
                                            {1,1,0,1,0,},
                                            {1,1,0,0,0,},
                                            {0,0,0,0,0,},};
    std::cout << "for matrix " << print(matrix) ; 
    std::cout << " Count should be 1 == got " <<   countIsland(4,5,matrix) << std::endl;
}
