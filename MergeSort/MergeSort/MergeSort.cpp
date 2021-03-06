// MergeSort.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::ifstream arquivo;
std::vector<int> vetor;

void merge(int inicio, int meio, int fim) { 
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;

	std::vector<int> Dir;
	std::vector<int> Esq;

	for (i = 0; i < n1; i++)
		Esq.push_back(vetor[inicio + i]);
	for (j = 0; j < n2; j++)
		Dir.push_back(vetor[meio + 1 + j]);

	i = 0;
	j = 0;
	k = inicio;

	while (i < n1 && j < n2) {
		if (Esq[i] <= Dir[j]) {
			vetor[k] = Esq[i];
			i++;
		}
		else {
			vetor[k] = Dir[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		vetor[k] = Esq[i];
		i++;
		k++;
	}
	while (j < n2) {
		vetor[k] = Dir[j];
		j++;
		k++;
	}
}



void mergeSort(int inicio, int fim) {
	if (inicio < fim) {
		int meio = (inicio + fim-1) / 2;
		mergeSort(inicio, meio);
		mergeSort(meio + 1, fim);
		merge(inicio, meio, fim);
	}
}
int main() {
	std::string arquivoname;
	std::cout << "MergeSort:" << std::endl << "Digite o nome do arquivo(ex. exemplo.txt): ";
	std::cin >> arquivoname;

	arquivo.open(arquivoname.data());
	if (!arquivo.is_open()) {
		system("pause");
		return -1;
	}
	int i;
	std::string stringer;
	while (!arquivo.eof()) {
		std::getline(arquivo, stringer);
		int num = std::stoi(stringer);
		vetor.push_back(num);
	}
	mergeSort(0, vetor.size() - 1);
	for (i = 0; i < vetor.size(); i++) {
		std::cout << vetor[i] << " " << std::endl;
	}
	system("pause");
	return 0;
}

