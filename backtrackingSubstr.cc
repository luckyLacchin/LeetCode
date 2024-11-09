#include <iostream>
#include <vector>
using namespace std;

// Funzione di backtracking per generare sottoinsiemi contigui
void backtrack(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& subsets) {
    // Aggiunge il sottoinsieme corrente alla lista dei sottoinsiemi
    subsets.push_back(currentSubset);

    // Prova ad aggiungere ogni elemento successivo al sottoinsieme corrente in modo contiguo
    for (int i = index; i < nums.size(); i++) {
        currentSubset.push_back(nums[i]);  // Aggiunge l'elemento corrente al sottoinsieme

        // Richiama ricorsivamente per il prossimo elemento contiguo
        backtrack(nums, i + 1, currentSubset, subsets); 

        currentSubset.pop_back();  // Rimuove l'ultimo elemento per tornare indietro
    }
}

// Funzione principale per testare l'implementazione
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets; // Vettore per memorizzare tutti i sottoinsiemi contigui
    vector<int> currentSubset; // Sottoinsieme corrente

    backtrack(nums, 0, currentSubset, subsets); // Avvia il backtracking

    // Stampa i risultati
    cout << "Sottoinsiemi contigui:" << endl;
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}