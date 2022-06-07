#include "List.h"

#pragma once


class Poli
{
private:

	int maxSt;
	int countv;
	circle_list circle;

public:

	Poli(std::string str, int _countv, int _maxst);
	Poli(const Poli& tmp);
	~Poli();
	Poli& operator=(Poli& tmp);
	Poli& operator +(Poli& tmp);
	Poli& operator-(Poli& tmp);
	Poli& operator*(Poli& tmp);
	Poli& operator*(int& k);
	std::string polinomToString();
	void erase(std::string str);
	void add(std::string str);

	void setCountv(int);
	void setMaxSt(int);



};



Poli::Poli(std::string str = "", int _countv = 6, int _maxSt = 10)
{
	this->countv = _countv;
	this->maxSt = _maxSt;
	this->circle = circle_list(_maxSt);

	if (str == "") {
		return;
	}

	int begin = 0;
	int k = 0;
	Monom kl;

	for (int i = 0; i < str.length(); i++) {

		if ((str[i] == '+' || str[i] == '-' || i == str.length() - 1) && i != 0) {


			if (k > 0) {
				kl = Monom(str.substr(begin, i - begin + 1), maxSt);
				this->circle.add(kl.getCoeff(), kl.getSv());

			}
			else
			{
				kl = Monom(str.substr(begin, i - begin), maxSt);
				this->circle.add(kl.getCoeff(), kl.getSv());
			}

			k++;

			begin = i + 1;

		}

	}
}



Poli::Poli(const Poli& tmp)
{
	this->maxSt = tmp.maxSt;
	this->countv = tmp.countv;
	this->circle = circle_list(tmp.circle);
}


Poli::~Poli()
{

}


Poli& Poli::operator=(Poli& tmp)
{
	this->maxSt = tmp.maxSt;
	this->countv = tmp.countv;
	this->circle = tmp.circle;
	return *this;
}


Poli& Poli::operator +(Poli& tmp)
{
	Poli* res = new Poli("", tmp.countv, tmp.maxSt);
	res->circle = this->circle + tmp.circle;
	return *res;
}


Poli& Poli::operator-(Poli& tmp)
{
	Poli* res = new Poli("", tmp.countv, tmp.maxSt);
	res->circle = circle - tmp.circle;
	return *res;
}


Poli& Poli::operator*(Poli& tmp)
{
	Poli* res = new Poli("", tmp.countv, tmp.maxSt);
	res->circle = circle * tmp.circle;
	return *res;
}


Poli& Poli::operator*(int& k)
{
	Poli* res = new Poli("", countv,maxSt);
	res->circle = circle * k;
	return *res;
}


std::string Poli::polinomToString()
{
	std::string tmp = this->circle.to_string(countv);
	return tmp;
}

void Poli::erase(std::string tmp) {

	Monom a(tmp, maxSt);
	this->circle.erase(a.getCoeff(), a.getSv());

}

void Poli::add(std::string tmp) {
	Monom a(tmp, maxSt);
	this->circle.add(a);

}

void Poli::setCountv(int a) {
	countv = a;
}

void Poli::setMaxSt(int a) {
	maxSt = a;
}