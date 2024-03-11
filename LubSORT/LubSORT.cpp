#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;
struct Top {
	int time;
	string name;
};
void bsort(int A[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
			}
		}
	}
}
void gsort(int A[], int size) {
	int i = 0;
	while (i < size) {
		if (i == 0 || A[i] >= A[i - 1]) {
			++i;
		}
		else {
			swap(A[i], A[i - 1]);
			--i;
		}
	}
}
void qsort(int A[], int size) {
    int i = 0;
    int j = size - 1;
    int mid = A[size / 2];
    do {
		while (A[i] < mid) { i++; }
		while (A[j] > mid) { j--; }
        if (i <= j) {
			swap(A[i], A[j]);
            i++;
            j--;
        }
    } while (i <= j);
	if (j > 0) { qsort(A, j + 1); }
	if (i < size) { qsort(&A[i], size - i); }
}
int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	srand(time(0));
	//
	int size;
	cout << "Введите колличество символов для сортировки: "; cin >> size;
	ofstream file("input.txt");
	int* A = new int[size];
	for (int i = 0; i < size; i++) { A[i] = rand() % size; file << A[i] << endl; /*cout << A[i] << endl;*/ }
	file.close();
	int* B = new int[size];
	Top top[3]{};
	top[0].name = "Пузырёк"; top[1].name = "Гном"; top[2].name = "Быстрая";
	//
	B = A;
	clock_t bs = clock();
	bsort(B, size);
	clock_t be = clock();
	double bt = static_cast<double>(be - bs); top[0].time = bt;
	//
	B = A;
	clock_t gs = clock();
	gsort(B, size);
	clock_t ge = clock();
	double gt = static_cast<double>(ge - gs); top[1].time = gt;
	//
	B = A;
	clock_t qs = clock();
	qsort(B, size);
	clock_t qe = clock();
	double qt = static_cast<double>(qe - qs); top[2].time = qt;
	//
	for (int i = 0; i < 3; i++) { cout << top[i].time << endl; }
	return 0;
}