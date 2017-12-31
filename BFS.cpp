#include <iostream>
using namespace std;

void distFromSource(const bool adjacent[][500], 
                    int BFS[], int vallige, int source);

int main()
{
  bool adjacent[500][500] = 
      {{1, 1, 0, 0, 1}, 
       {1, 1, 1, 0, 0}, 
       {0, 1, 1, 1, 0}, 
       {0, 0, 1, 1, 1},
       {1, 0, 0, 1, 1}};
  
  int vallige = 5;


  int BFS[500][500] = {0};

  for (int source = 0; source < vallige; ++source)
  {
    distFromSource(adjacent, BFS[source] , vallige, source);
  }


  for (int j = 0; j < vallige; ++j)
  {
    for (int i = 0; i < vallige; ++i)
    {
      cout << BFS[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}

void distFromSource(const bool adjacent[][500], 
                    int BFS[], int vallige, int source)
{
  for(int i = 0; i < vallige; i++){
    BFS[i] = vallige;
  }
  
  BFS[source] = 0;
  int curDist = 1; 
  int complete = 1;
  
  while(complete < vallige)
  {
 
    for(int i = 0; i < vallige; i++)
    {
      if(BFS[i] == curDist - 1)
      {
        for(int j = 0; j < vallige; j++)
        {
          if(adjacent[i][j] == true && BFS[j] == vallige)
          {
            BFS[j] = curDist; 
            complete++;
          }          
        }
      }
    }
       

    curDist++;
  }
}