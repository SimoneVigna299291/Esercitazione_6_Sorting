#include "sortingalgorithm.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace SortLibrary;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <dimensione_vettore>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    cout << "Dimensione del vettore di test: " << n << endl;

    vector<int> v(n);

    // Riempimento del vettore con valori casuali
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    for (int& elem : v) {
        elem = dis(gen);
    }

    // Creazione di una copia del vettore per MergeSort
    vector<int> v_merge = v;

    // Timing per BubbleSort
    auto start_bubble = high_resolution_clock::now();
    BubbleSort(v);
    auto stop_bubble = high_resolution_clock::now();
    auto duration_bubble = duration_cast<microseconds>(stop_bubble - start_bubble);

    // Timing per MergeSort
    auto start_merge = high_resolution_clock::now();
    MergeSort(v_merge);
    auto stop_merge = high_resolution_clock::now();
    auto duration_merge = duration_cast<microseconds>(stop_merge - start_merge);

    // Stampa dei tempi di esecuzione
    cout << "Tempo di esecuzione BubbleSort: " << duration_bubble.count() << " microsecondi" << endl;
    cout << "Tempo di esecuzione MergeSort: " << duration_merge.count() << " microsecondi" << endl;

    return 0;
}
