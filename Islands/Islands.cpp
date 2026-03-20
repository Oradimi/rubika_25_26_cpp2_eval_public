#include <vector>
#include <assert.h>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

void checkSides(std::vector<std::vector<char>>& grid, std::vector<std::vector<char>>& checked, int& count, int& i, int& j)
{
    int k = j + 1;
    if (k < grid[i].size() && checked[i][k] == '0' && grid[i][k] == '1')
    {
        checked[i][k] = '1';
        checkSides(grid, checked, count, i, k);
    }

    k = i + 1;
    if (k < grid.size() && checked[k][j] == '0' && grid[k][j] == '1')
    {
        checked[k][j] = '1';
        checkSides(grid, checked, count, k, j);
    }

    k = j - 1;
    if (k >= 0 && checked[i][k] == '0' && grid[i][k] == '1')
    {
        checked[i][k] = '1';
        checkSides(grid, checked, count, i, k);
    }

    k = i - 1;
    if (k >= 0 && checked[k][j] == '0' && grid[k][j] == '1')
    {
        checked[k][j] = '1';
        checkSides(grid, checked, count, k, j);
    }
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    int count = 0;
    std::vector<std::vector<char>> checked = grid;
    for (std::vector<char>& row : checked)
        for (char& var : row)
            var = '0';
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (checked[i][j] == '1')
                continue;

            checked[i][j] = '1';
            if (grid[i][j] == '0')
                continue;

            if (grid[i][j] == '1')
            {
                count++;
                checkSides(grid, checked, count, i, j);
            }
        }
    }
        
	return count;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    {
        std::vector<std::vector<char>> grid = {
            {'1','1','1'},
            {'0','1','0'},
            {'1','1','1'}
        };
        assert(count_islands(grid) == 1);
    }

    return 0;
}