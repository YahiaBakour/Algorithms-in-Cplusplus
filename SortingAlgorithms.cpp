/* THESE ARE THE SORTING ALGORITHMS USED SPECIFICALLY FOR Vectors */
/* INPUT : VECTOR OF SIZE M // OUTPUT : SORTED VECTOR OF SIZE M */
/* THIS CODE IS NOT 100% MINE */







/* TAKE WHATEVER YOU WOULD LIKE */
/* BY YOUR BOI: YAHIA B */
#include<iostream>
#include <iomanip>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include <string.h>

  using namespace std;

// SELECTION SORT
template < class T >
  vector < T > selection_sort_vector(vector < T > Vec) {
    int size = Vec.size();
    for (int i = 0; i != size; i++) {
      int min = i;
      for (int j = i + 1; j != size; j++) {
        if (Vec[j] < Vec[min]) min = j;
      }
      if (min != i) {
		  swap(Vec[i],Vec[min]);
      }
    }
    return Vec;
  }

// BUBBLE SORT With Swapped Flag(BEST CASE : O(n) if nearly sorted)
template < class T >
  vector < T > bubble_sort_vector(vector < T > vec) {
    int temp;
    int size = vec.size();
    for (int i = 0; i != size; i++) {
      bool swapped_flag = false;
      for (int j = 0; j != size - 1; j++) {
        if (vec[j] > vec[j + 1]) {
          temp = vec[j];
          vec[j] = vec[j + 1];
          vec[j + 1] = temp;
          swapped_flag = true;
        }
      }
      if (swapped_flag = false) break;
    }
    return vec;
  }

// INSERTION SORT
template < class T >
  vector < T > insertion_sort_vector(vector < T > vec) { // NOTE : LOOK UP FURTHER
    int i, j, value, y;
    int size = vec.size();
    for (i = 0; i != size; i++) {
      value = vec[i];
      y = i - 1;
      while (y >= 0 && vec[y] > value) {
        vec[y + 1] = vec[y];
        y--;
      }
      vec[y + 1] = value;
    }
    return vec;
  }

// HEAPSORT
template < class T >
  void Max_Heapify(vector < T > & V, int I, int size) {
    int left = 2 * I + 1;
    int right = 2 * I + 2;
    int Largest_Index = I;
    if (left < size && V[left] > V[Largest_Index]) Largest_Index = left;
    if (right < size && V[right] > V[Largest_Index]) Largest_Index = right;
    if (Largest_Index != I) {
      swap(V[I], V[Largest_Index]);
      Max_Heapify(V, Largest_Index, size);
    }
  }

template < class T >
  void Build_Max_Heap(vector < T > & V) {
    int size = V.size();
    for (int i = size / 2 - 1; i >= 0; i--)
      Max_Heapify(V, i, size);
  }

template < class T >
  vector < T > Heap_Sort_Vector(vector < T > & V) {
    vector < T > Vec = V;
    int size = Vec.size();
    Build_Max_Heap(Vec);
    for (int x = size - 1; x >= 0; x--) {
      swap(Vec[0], Vec[x]);
      Max_Heapify(Vec, 0, x);
    }
    return Vec;
  }
  
// Merge Sort
template < class T >
  void Merge(vector < T > & V, int l, int r, int m) {
    int I1, I2, X;
    int size1, size2;
    vector < T > V1, V2;
    for (int i = l; i <= m; i++) {
      V1.push_back(V[i]);
    }
    for (int j = m + 1; j <= r; j++) {
      V2.push_back(V[j]);
    }
    I1 = 0;
    I2 = 0;
    X = l;
    for (int I1 = 0, I2 = 0; I1 != V1.size(), I2 != V2.size(); I1++, I2++) {}
    while (I1 < V1.size() && I2 < V2.size()) {
      if (V1[I1] <= V2[I2]) {
        V[X] = V1[I1];
        I1++;
      } else {
        V[X] = V2[I2];
        I2++;
      }
      X++;
    }
    while (I1 < V1.size()) {
      V[X] = V1[I1];
      I1++;
      X++;
    }
    while (I2 < V2.size()) {
      V[X] = V2[I2];
      I2++;
      X++;
    }
  }

template < class T >
  void Merge_sort(vector < T > & V, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    Merge_sort(V, l, m);
    Merge_sort(V, m + 1, r);
    Merge(V, l, r, m);
  }

template < class T >
  vector < T > Merge_Sort_Vector(vector < T > & V) {
    vector < T > vec = V;
    int l = 0;
    int r = V.size() - 1;
    Merge_sort(vec, l, r);
    return vec;
  }


int main() {
  vector < int > V;
  V.push_back(1);
  V.push_back(5);
  V.push_back(4);
  V.push_back(21);
  V.push_back(3);
  V.push_back(9);
  V.push_back(2);
  V.push_back(3);
  V.push_back(1);
  for (int x = 0; x != V.size(); x++) {
    cout << V[x] << " ";
  }
  cout << endl;
  V = Merge_Sort_Vector(V); // CHANGE DEPENGING ON WHICH SORTING ALGORITHM YOU WANT TO USE
  for (int x = 0; x != V.size(); x++) {
    cout << V[x] << " ";
  }
  return 0;
}

