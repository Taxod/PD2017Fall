#include <iostream>
using namespace std;

const int NODE_CNT = 4;

void inputGraphInfo(int* neighbors[], int degrees[]);
void printGraph(int* neighbors[], int degrees[]);
void releaseMemory(int* neighbors[]);
bool isNeighbor(int* neighbors[], int degrees[], int node1, int node2);

int main()
{
  int* neighbors[NODE_CNT] = {0};
  int degrees[NODE_CNT] = {0};

  inputGraphInfo(neighbors, degrees);
  printGraph(neighbors, degrees);
  releaseMemory(neighbors);
  
  return 0;
}

void inputGraphInfo(int* neighbors[], int degrees[])
{
  for(int i = 0; i < NODE_CNT; i++)
  {
//    cout << "Node " << i << "\'s degree is: ";
    cin >> degrees[i];
    neighbors[i] = new int[degrees[i]];
//    cout << "Node " << i << "\'s neighbors: ";
    for(int j = 0; j < degrees[i]; j++)
      cin >> neighbors[i][j];
  }  
}

void printGraph(int* neighbors[], int degrees[])
{
  for(int i = 0; i < NODE_CNT; i++)
  {
    for(int j = 0; j < NODE_CNT; j++)
      cout << isNeighbor(neighbors, degrees, i, j) << " ";    
    cout << "\n";
  }  
}

void releaseMemory(int* neighbors[])
{
  for(int i = 0; i < NODE_CNT; i++)
    delete [] neighbors[i];
}

bool isNeighbor(int* neighbors[], int degrees[], int node1, int node2)
{
  for(int i = 0; i < degrees[node1]; i++)
  {
    if(node2 == neighbors[node1][i])
      return true;
  }
  return false;
}
