#pragma once
class Vector {
	int size;
	int* mass;

public:
	Vector();
	Vector(int len);
	Vector(Vector& V);
	Vector(Vector&& V) noexcept;
	~Vector();

	void setSize();
	int getSize();
	int* getMass();
	int quantity();
	int getElem(int index);
	void setElem(int elem, int index);


	void Plus(int num);
	void Minus(int num);
	void Mul(int num);
	void Div(int num);

	double lengthVec();
	int operator[] (int index);
	void operator +=(Vector& V);
	void operator -=(Vector& V);
	void operator *=(Vector& V);
	void operator /=(Vector& V);
	void operator =(Vector& V);

	void input();
	void output();
	void random();
	int min(int& min);

	//void operator*(int num);// перегрузка оператора, как метода класса
	

};

Vector operator*(Vector& vector, int num);

