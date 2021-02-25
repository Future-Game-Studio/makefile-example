#include <vector>
#include <list>
#include <tuple> 

using namespace std;

typedef list<int> listType;
typedef vector<vector<int>> heapType;

void fillHeap(heapType &heap, listType &l1, listType &l2);
void printHeap(heapType &heap);