#include "ordenacao.cpp"
#include <iostream>
#include <chrono>

void testSortFunction(void (*sortFunc)(int[], unsigned int), int a[], unsigned int t, const std::string& sortName) {
  int* copy = new int[t];
  std::copy(a, a + t, copy);

  std::cout << "Testando " << sortName << "..." << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  sortFunc(copy, t);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;

  sortFunc(copy, t);

  if(ordenado(copy, t)) {
    std::cout << "Array ordenado \n\n";
    std::cout << "Tempo de execucao: " << duration.count() << " segundos" << std::endl;
  } else {
    std::cout << "Array não ordenado ";
  }

  std::cout << "- - - - - - - - - - - - - - - - - - \n\n";


  delete[] copy;
}

int main() {
  int a[10] = {2, 8, 5, 7, 3, 6, 4, 9, 1, 12};

  testSortFunction(selecao, a, 10, "Selecao");
  testSortFunction(insercao, a, 10, "Insercao");
  testSortFunction([](int arr[], unsigned int t) { merge_sort(arr, 0, t - 1); }, a, 10, "Merge Sort");

  return 0;
}