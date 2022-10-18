#include <iostream>
#include <cstdlib>
#include <ctime>

void fill_arr(int arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
void resize_arr(T*& arr, const int length, const int length2) {
	if (length <= 0)
		return;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	
	delete[] arr;
	arr = tmp;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
		
	//������ 1. ��� ������������ ������� � ����
	
	std::cout << "������ 1.\n������� ����� ������� A: ";
	std::cin >> n;
	int* arrA = new int[n];
	if (n < 0)
		std::cout << "������. ����� �� ����� ���� �������������.\n";
	else {
		std::cout << "������������ ������ A: \n";
		fill_arr(arrA, n, 25, 67);
		show_arr(arrA, n);
		std::cout << "\n";
	}
	std::cout << "������� ����� ������� B: ";
	std::cin >> m;
	int* arrB = new int[m];
	if (m < 0)
		std::cout << "������. ����� �� ����� ���� �������������.\n";
	else {
		std::cout << "������������ ������ B: \n";
		fill_arr(arrB, m, 12, 78);
		show_arr(arrB, m);
		std::cout << "\n";

	}

		int* arrC = new int [n + m];
		for (int i = 0; i < n; i++)
			arrC[i] = arrA[i];
		for (int i = n; i < n + m; i++)
			arrC[i] = arrB[i - n];

		std::cout << "������������ ������ C: \n";
		show_arr(arrC, n + m);


		delete[] arrA;
		delete[] arrB;
		std::cout << "\n";
	
		//������ 2. ��������� ����� ������������� ������� �� ����� �����.

		std::cout << "������ 2. \n������� ����� �������: ";
		int size3;
		std::cin >> size3;
		int* mass = new int[size3];
		if (size3 < 0)
			std::cout << "������. ����� �� ����� ���� �������������.\n";
		else {
			std::cout << "������������ ������: \n";
			fill_arr(mass, size3, 1, 11);
			show_arr(mass, size3);
			std::cout << "\n";
		}
		std::cout << "������� ����� ����� �������: ";
		int size4;
		std::cin >> size4;
		resize_arr(mass, size3, size4);
		std::cout << "����� ������: \n";
		fill_arr(mass, size4, 5, 20);
		show_arr(mass, size4); 


	return 0;
}