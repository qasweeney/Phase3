#include <iostream>
#include <cmath>

using namespace std;

template <typename K>

class Heap
{
private:
  K *array;
  int size;
  int capacity;

  void buildMinHeap(K a[])
  {
    for (int i = floor(size / 2) - 1; i >= 0; i--)
    {
      heapify(a, i);
    }
  };

  void heapify(K arr[], int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && arr[l] < arr[i])
    {
      smallest = l;
    }
    if (r < size && arr[r] < arr[smallest])
    {
      smallest = r;
    }
    if (smallest != i)
    {
      swap(&arr[i], &arr[smallest]);
      heapify(arr, smallest);
    }
  };

  int left(int i)
  {
    return (2 * i) + 1;
  };

  int right(int i)
  {
    return (2 * i) + 2;
  };

  void swap(K *a, K *b)
  {
    K temp = *a;
    *a = *b;
    *b = temp;
  };

public:
  // Default constructor
  Heap()
  {
    size = 0;
    capacity = 10;
    array = new K[capacity];
  };
  // Constructor with array
  Heap(K k[], int s)
  {
    size = s;
    capacity = s;
    array = new K[size];
    for (int i = 0; i < size; i++)
    {
      array[i] = k[i];
    }
    buildMinHeap(array);
  };
  // Destructor
  ~Heap()
  {
    delete[] array;
  };
  // Prints the array
  void printKey()
  {
    for (int i = 0; i < size; i++)
    {
      cout << array[i] << " ";
    }
    cout << endl;
  };
};