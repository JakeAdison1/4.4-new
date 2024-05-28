#include <iostream>
#include <ctime>
#include "Header.h"
using namespace std;

Vector::Vector() { //������ ��� ���������� 
	cout << "������� ������:";
	cin >> size;
	mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = 5;
	}
}
Vector::Vector(int size) { //������ � ���������� ���������� 
	this->size = size;
	mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = 1;
	}
}
Vector::Vector(Vector& V) { // ������ ����������� 
	size = V.size;
	mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = V.mass[i];
		V.mass[i] = 0;
	}
}
Vector::Vector(Vector&& V) noexcept { //����������� �����������
	size = V.size;
	mass = new int[size];
	for (int i = 0; i < size; i++) {
		mass[i] = V.mass[i];
	}
	V.size = 0;
	delete[] V.mass;
	V.mass = nullptr;
}
Vector::~Vector() {
	delete[] mass;
	cout << endl;
	cout << "���������� ��������";
}


void Vector::setSize() {//������������ 
	this->size = size;
}
int Vector::getSize() {//������������ 
	return size;
}
int* Vector::getMass() {//������������ 
	return mass;
}



int Vector::quantity() {//���-�� ���������
	return size;
}

int Vector::getElem(int index) {//��������� ������� �� �������
	if (index < size) {
		return mass[index];
	}
	else
		cout << "��������";
}

void Vector::setElem(int elem, int index) {//��������� ����.
	if (index < size) {
		mass[index] = elem;
	}
	else {
		cout << "������";
	}
}

void Vector::Plus(int num)
{
	for (int i = 0; i < size; i++)
		mass[i] += num;
}

void Vector::Minus(int num)
{
	for (int i = 0; i < size; i++)
		mass[i] -= num;
}

void Vector::Mul(int num)
{
	for (int i = 0; i < size; i++)
		mass[i] *= num;
}

void Vector::Div(int num)
{
	for (int i = 0; i < size; i++)
		mass[i] /= num;
}

double Vector::lengthVec() {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result += mass[i] * mass[i];
	}
	return sqrt(result);
}

int Vector:: operator [] (int index)
{
	return mass[index];
}

void Vector:: operator +=(Vector& V)
{
	if (size == V.quantity())
	{
		for (int i = 0; i < size; i++)
		{
			mass[i] += V[i];
		}
	}
	else
		cout << "dif sizes" << endl;
}

void Vector:: operator -=(Vector& V)
{
	if (size == V.quantity())
	{
		for (int i = 0; i < size; i++)
		{
			mass[i] -= V[i];
		}
	}
	else
		cout << "dif sizes" << endl;
}

void Vector:: operator *=(Vector& V)
{
	if (size == V.quantity())
	{
		for (int i = 0; i < size; i++)
		{
			mass[i] *= V[i];
		}
	}
	else
		cout << "dif sizes" << endl;
}

void Vector:: operator /=(Vector& V)
{
	if (size == V.quantity())
	{
		for (int i = 0; i < size; i++)
		{
			mass[i] /= V[i];
		}
	}
	else
		cout << "dif sizes" << endl;
}
void Vector:: operator = (Vector& V)
{
	size = V.size;
	mass = new int[size];
	for (int i = 0; i < size; i++)
		mass[i] = V.mass[i];
}
void Vector::input() { //������ ��� ���������� 
	mass = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> mass[i];
	}
}
void Vector::output() {

	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
}
void Vector::random() {

	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 100;

	}
}
int Vector::min(int& min) {
	min = mass[0];
	for (int i = 0; i < size; i++) {
		if (mass[i] <= min) {
			min = mass[i];
		}
	}
	cout << endl << "���������� �������:" << min;
	return min;
}


//void Vector::operator*(int num)// ���������� ���������, ��� ������ ������
//{
//	for (int i = 0; i < size; i++)
//		mass[i] *= num;
//}
Vector operator* (Vector& V, int num) {
	int* massive = V.getMass();
	for (int i = 0; i < V.quantity(); i++) {
		massive[i] *= num;
		cout << massive[i]<<" ";
	}
	return V;
}



//Vector operator*(Vector V, int num, int size) // ���������� ��������� ����� ������� �������
//{
//	for (int i = 0; i < size; i++)
//	{
//		V.mass[i] *= num;
//	}
//	return V;
//}

//friend Vector& operator*(Vector& V, int num) // ���������� ��������� ����� ������� �������
//{
//	for (int i = 0; i < V.size; i++)
//	{
//		V.mass[i] *= num;
//	}
//	return V;
//}

