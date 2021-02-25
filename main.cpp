// dynamic arrays and range-based for loop
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include "main.h"
// this works only on windows
// sudo apt-get install libncurses5-dev libncursesw5-dev
//#include <conio.h>

using namespace std;

int main()
{
    cout << "C++ 20: vector init in range based for - " << endl;

    for (auto thing = list<int>({1, 2, 3, 4}); auto &x : thing)
    {
        cout << x << endl;
    }
    cout << endl;

    vector<vector<int>> v = {
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5}};

    reverse(v[1].begin(), v[1].end());

    int i = 0;
    for (auto t1 : v)
    {
        int j = 0;
        for (auto t2 : t1)
            cout << t2 << " (" << i << "," << j++ << ")"
                 << "   ";
        cout << '\n';
        i++;
    }
    cout << "Input N: ";
    int n;
    cin >> n;

    int *arr1 = new int(n);
    int *arr2 = new int(n);

    heapType heap;
    list<int> list1(*arr1);
    list<int> list2(*arr2);
    delete arr2;
    delete arr1;

    printHeap(heap);

    fillHeap(heap, list1, list2);

    printHeap(heap);
    heap.clear();

    cin.clear();
    cin.sync();
    cin.ignore();
    
    // this works only on windows
    //system("pause");
}

void printHeap(heapType &heap)
{
    // iterating over heap
    cout << '\n'
         << string(10, '-') << "<heap>" << string(10, '-') << '\n';

    if (heap.size() == 0)
    {
        cout << "Empty" << '\n';
    }
    else
    {
        for (auto &i : heap)
        {
            for (auto &j : i)
                cout << "(" << j << ")"
                     << " ";

            cout << '\n';
        }
    }
    cout << string(10, '-') << "<!heap>" << string(10, '-') << '\n';
}

/// Inflates heap randomizing pairs
void fillHeap(heapType &heap, listType &l1, listType &l2)
{
    for (auto &&i : l1)
    {
        vector<int> g;
        for (auto &&j : l2)
        {
            // randomizing pairs
            i = 1 + rand() % 9 + j;
            g.push_back(i);
        }
        heap.push_back(g);
    }
}