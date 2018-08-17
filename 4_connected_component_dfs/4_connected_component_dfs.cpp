#include <iostream>

#define MAX     5

using namespace std;

// direction vectors
const int dx[] = {+1, 0, -1, 0};
const int dy[] = {0, +1, 0, -1};

// matrix dimensions
int row_count = MAX;
int col_count = MAX;

// the input matrix
int m[MAX][MAX] = {{1,0,0,0,1},
                    {1,1,0,1,1},
                    {0,1,0,0,1},
                    {1,1,1,1,0},
                    {0,0,0,1,0}};

// the labels, 0 means unlabeled
int label[MAX][MAX] = {{0}, {0}};

void dfs(int x, int y, int current_label) {
  if (x < 0 || x == row_count) return; // out of bounds
  if (y < 0 || y == col_count) return; // out of bounds
  if (label[x][y] || !m[x][y]) return; // already labeled or not marked with 1 in m

  // mark the current cell
  label[x][y] = current_label;

  // recursively mark the neighbors
  for (int direction = 0; direction < 4; ++direction)
    dfs(x + dx[direction], y + dy[direction], current_label);
}

void find_components() {
  int component = 0;
  for (int i = 0; i < row_count; ++i) 
    for (int j = 0; j < col_count; ++j) 
      if (!label[i][j] && m[i][j]) dfs(i, j, ++component);
}


int main()
{
    int w = row_count;
    int h = col_count;

    find_components();
 
    for (int x = 0; x < w; x++)
    {
      for (int y = 0; y < h; y++)
      {
         if (label[x][y] == 0)
            cout << ' ';
         else
            cout << label[x][y];
      }
      cout << "\n";
    }
}
