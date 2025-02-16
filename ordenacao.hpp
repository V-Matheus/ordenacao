#ifndef __ORDENACAO__
#define __ORDENACAO__

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
bool ordenado(const int a[], unsigned int t);   // O(n)

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por seleção.
  A ordenação é feita diretamente no vetor 'a'
*/
void selecao(int a[], unsigned int t);  // O(n^2)

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por inserção.
  A ordenação é feita diretamente no vetor 'a'
*/
void insercao(int a[], unsigned int t); // O(n^2)

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação merge-sort.
  A ordenação é feita diretamente no vetor 'a'
*/
void merge_sort(int a[], int left, int right); // O(n log n)

#endif