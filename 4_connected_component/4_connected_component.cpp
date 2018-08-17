#include <iostream>

using namespace std;

const int w = 5, h = 5;
int input[w][h] =  {{1,0,0,0,1},
                    {1,1,0,1,1},
                    {0,1,0,0,1},
                    {1,1,1,1,0},
                    {0,0,0,1,0}};
int component[w*h];
void doUnion(int a, int b)
{
  // get the root component of a and b, and set the one's parent to the other
  while (component[a] != a)
    a = component[a];
  while (component[b] != b)
    b = component[b];
  component[b] = a;
}
 
void unionCoords(int x, int y, int x2, int y2)
{
  if (y2 < h && x2 < w && input[x][y] && input[x2][y2])
    doUnion(x*h + y, x2*h + y2);
}
 
int main()
{
  // set up input
  for (int i = 0; i < w*h; i++)
    component[i] = i;
  for (int x = 0; x < w; x++)
  for (int y = 0; y < h; y++)
  {
    unionCoords(x, y, x+1, y);
    unionCoords(x, y, x, y+1);
  }
 
    for (int x = 0; x < w; x++)
    {
      for (int y = 0; y < h; y++)
      {
         if (input[x][y] == 0)
         {
            cout << ' ';
            continue;
         }
         int c = x*h + y;
         while (component[c] != c) c = component[c];
         cout << (char)('a'+c);
      }
      cout << "\n";
    }
}
