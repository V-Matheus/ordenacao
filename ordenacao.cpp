#include "ordenacao.hpp"
#include <vector> 

/* TODO: Implementar função */
bool ordenado(int a[],  unsigned int t){
    if (t < 1) {
        return false;
    }
  
    if (t == 1) {
      return true;
    }
  
    for (unsigned int i = 0; i < t - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

/* TODO: Implementar função */
void selecao(int a[], unsigned int t){
    for (unsigned int i = 0; i < t - 1; i++) {
        unsigned int min_idx = i;
        for (unsigned int j = i + 1; j < t; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
      }
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
    for (unsigned int i = 1; i < t; i++) {
        int key = a[i];
        unsigned int j;
        for (j = i; j > 0 && a[j - 1] > key; j--) {
            a[j] = a[j - 1];
        }
        a[j] = key; 
      } 
}

/* TODO: Implementar função */
void merge_sort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
  
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
  
        int n1 = mid - left + 1;
        int n2 = right - mid;
  
        std::vector<int> L(n1), R(n2);
  
        for (int i = 0; i < n1; i++)
            L[i] = a[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = a[mid + 1 + j];
  
        int i = 0, j = 0;
        for (int k = left; k <= right; k++) {
            if (i < n1 && (j >= n2 || L[i] <= R[j])) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
        }
    }
}
