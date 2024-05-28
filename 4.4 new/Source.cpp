#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;


int main() {
	int size, min;
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	cout << "**************Выполнение задания*************\n";
	cout << "Введите размер массивов:";
	cin >> size;
	Vector C(size);
	Vector A(size);
	A.random();
	A.output();
	A.min(min);
	int min1 = min;
	cout << endl;
	Vector B(size);
	B.random();
	B.output();
	B.min(min);
	int min2 = min;

	cout << endl;
	for (int i = 0; i < size; i++) {
		C.setElem(A[i]*min1-B[i]*min2,i);
	}
	C.output();
	cout << endl;
	cout << "**************Работа конструктора*************\n";
	Vector D(A);
	D.output();
	cout << endl;

	Vector H(size);
	Vector J = move(H);
	J.random();
	J.output();
	cout << endl;

	cout << "**************Перегрузка оператора*************\n";
	Vector S(size);
	Vector F(S);
	F.random();
	F.output();
	cout << endl << endl;
	F * 2;
	cout << endl<<endl;
	F.output();
	/*cout << endl;
	F * 5;*/

	return 0;
}