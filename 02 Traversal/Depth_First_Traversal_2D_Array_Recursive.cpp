#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

void fillMatrix(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < col; j++)
			cin >> matrix[i][j];
	}
}
void DFSUtil(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {

	int H = grid.size();
	int L = grid[0].size();

	if (row < 0 || col < 0 || row >= H || col >= L || visited[row][col])
		return;

	// Mark the cell visited
	visited[row][col] = true;
	cout << grid[row][col] << " ";
	DFSUtil(grid, row + 1, col, visited); // Go Right
	DFSUtil(grid, row - 1, col, visited); // Go Left
	DFSUtil(grid, row, col + 1, visited); // Go Down
	DFSUtil(grid, row, col - 1, visited); // Go Up
}

void DFS(vector<vector<int>>& grid) {

	int h = grid.size();
	if (h == 0)
		return;
	int l = grid[0].size();

	//created visited array
	vector<vector<bool>> visited(h, vector<bool>(l));
	cout << "Depth-First Search: ";
	DFSUtil(grid, 0, 0, visited);
}



/*
INPUT:
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
int main(void)
{
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int>> matrix(rows, vector<int>(cols));
	vector<vector<bool>> visited(rows, vector<bool>(cols));
	fillMatrix(matrix);
	
	DFS(matrix);

	return 0;
}