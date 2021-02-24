// dynamic arrays and range-based for loop
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <conio.h>

using namespace std;

typedef list<int> listType;
typedef vector<vector<tuple<int, int>>> heapType;

void fillHeap(heapType &heap, listType &l1, listType &l2);
void printHeap(heapType &heap);

int main()
{
    std::cout << "C++ 20: vector init in range based for - ";

    for (auto thing = list<int>({1, 2, 3, 4}); auto &x : thing)
    {
        std::cout << x << endl;
    }
    vector<vector<int>> v = {
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5}};
 
    std::reverse(v[1].begin(), v[1].end());

    int i = 0;
    for (auto t1 : v)
    {
        int j = 0;
        for (auto t2 : t1)
            std::cout << t2 << " (" << i << "," << j++ << ")"
                      << "   ";
        std::cout << '\n';
        i++;
    }

    // How about dynamic arrays?

    //cout << "Введіть розмір матриць: ";
    std::cout << "Input N: ";
    int n;
    cin >> n;

    int *arr1 = new int(n);
    int *arr2 = new int(n);

    heapType heap;
    std::list<int> list1(*arr1);
    std::list<int> list2(*arr2);
    delete arr2;
    delete arr1;

    printHeap(heap);

    fillHeap(heap, list1, list2);

    heap.clear();

    getch();
}

void printHeap(heapType &heap)
{
    // iterating over heap
    std::cout << '\n'
              << string(10, '-') << "<heap>" << string(10, '-') << '\n';

    if (heap.size() == 0)
    {
        std::cout << "Empty";
    }
    else
    {
        for (auto &i : heap)
        {
            for (auto &j : i)
                std::cout << "(" << get<0>(j) << "," << get<1>(j) << ")"
                          << " ";

            std::cout << '\n';
        }
    }
    std::cout << '\n'
              << string(10, '-') << "<!heap>" << string(10, '-') << '\n';
}

/// Inflates heap randomizing pairs
void fillHeap(heapType &heap, listType &l1, listType &l2)
{
    for (auto &&i : l1)
    {
        vector<tuple<int, int>> g;
        for (auto &&j : l2)
        {
            // randomizing pairs
            i = 1 + rand() % 9;
            j = 1 + rand() % 9;
            g.push_back(std::make_tuple(i, j));
        }
        heap.push_back(g);
    }
}