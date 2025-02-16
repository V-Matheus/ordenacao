#include "ordenacao.cpp"
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

#ifdef _WIN32
  #include <direct.h>
  #define getcwd _getcwd
#else
  #include <unistd.h>
#endif

void testSortFunction(void (*sortFunc)(int[], unsigned int), int a[], unsigned int t, const std::string& sortName) {
  int* copy = new int[t];
  std::copy(a, a + t, copy);

  std::cout << "Testando " << sortName << "..." << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  sortFunc(copy, t);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;

  if (ordenado(copy, t)) {
    std::cout << "Array ordenado ";
    std::cout << "Tempo de execucao: " << duration.count() << " segundos" << std::endl;
  } else {
    std::cout << "Array nao ordenado ";
  }

  std::cout << "- - - - - - - - - - - - - - - - - - \n\n";

  delete[] copy;
}

int main() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == nullptr) {
    std::cerr << "Erro ao obter diretório atual." << std::endl;
    return 1;
  }

  std::string filePath = std::string(cwd) + "\\testes\\caso01\\exemplo-10000-1.txt";

  std::ifstream file(filePath);
  if (!file) {
    std::cerr << "Erro ao abrir o arquivo de teste: " << filePath << std::endl;
    return 1;
  }

  unsigned int t;
  file >> t;
  std::cout << "Tamanho do array: " << t << std::endl;

  int* a = new int[t];
  for (unsigned int i = 0; i < t; ++i) {
    file >> a[i];
  }

  file.close();

  testSortFunction(selecao, a, t, "Selecao");
  testSortFunction(insercao, a, t, "Insercao");
  testSortFunction([](int arr[], unsigned int t) { merge_sort(arr, 0, t - 1); }, a, t, "Merge Sort");

  delete[] a;
  return 0;
}
