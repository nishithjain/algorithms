#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> dRow = { -1, 0, 1, 0 };
vector<int> dCol = { 0, 1, 0, -1 };

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

bool isValid(vector<vector<bool>> vis, int row, int col)
{
	int ROW = vis.size();
	int COL = vis[0].size();

	if (row < 0 || col < 0 || row >= ROW || col >= COL)
		return false;

	if (vis[row][col])
		return false;

	return true;
}

void BFS(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int c)
{
	queue<pair<int, int>> q;

	q.push(make_pair(r, c));
	visited[r][c] = true;

	while (!q.empty())
	{
		auto cell = q.front();
		int x = cell.first;
		int y = cell.second;

		cout << matrix[x][y] << " ";
		q.pop();

		for (int i = 0; i < 4; i++) {

			int adjx = x + dRow[i];
			int adjy = y + dCol[i];

			if (isValid(visited, adjx, adjy)) {
				q.push({ adjx, adjy });
				visited[adjx][adjy] = true;
			}
		}
	}
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
	
	BFS(matrix, visited, 0, 0);

	return 0;
}