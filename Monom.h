#pragma once
#include <string>

#pragma once
class Monom
{

private:
	int coeff;
	int Sv;
	Monom* next;
	bool first = false;

public:
	Monom(int a_, int Sv_);
	Monom(const Monom& tmp);
	Monom(std::string tmp, int maxSt);
	~Monom();

	void monomMult(Monom& tmp, int maxSt);

	int getCoeff();
	void setCoeff(int newCoeff);
	int getSv();
	void setSv(int newSv);
	Monom* getNext();
	void setNext(Monom* tmp);
	void setFirst();
	bool getFirst();

	Monom& operator=(const Monom& tmp);
	std::string toString(int countv, int maxst);
};

Monom::Monom(int a_ = 0, int Sv_ = -1) {
	coeff = a_;
	Sv = Sv_;
	next = this;
}

Monom::Monom(const Monom& tmp) {
	coeff = tmp.coeff;
	Sv = tmp.Sv;
	next = this;
}

Monom::Monom(std::string tmp, int maxSt) {
	int count = 0;
	int counterG;
	int counterK;
	int tmpInt;

	coeff = 0;
	Sv = 0;
	next = this;

	while (true)
	{
		if (count == 0 && tmp[count] == 'x') {

			coeff = 1;
			break;

		}

		if (tmp[count] == 'x')
		{
			coeff = std::stoi(tmp.substr(0, count));
			break;
		}
		count++;
	}




	for (int i = count; i < tmp.length(); i++)
	{

		if (tmp[i] == '^')
		{
			counterG = i;
			counterK = i;

			while ((tmp[counterG] != 'x' && tmp[counterK] != 'x') || (tmp[counterK] != 'x' && counterG != tmp.length())) {
				if (tmp[counterK] != 'x') {
					counterK--;
				}
				if (tmp[counterG] != 'x' || counterG != tmp.length()) {
					counterG++;
				}
			}

			tmpInt = std::stoi(tmp.substr(counterK + 1, i - counterK + 1));


			Sv += std::stoi(tmp.substr(i + 1, counterG - 1 - i)) * pow(maxSt, (tmpInt - 1));
		}
	}

}


Monom::~Monom() {

}


void Monom::monomMult(Monom& tmp, int maxSt) {

	int tmpSv = 0;
	int tmpSv2 = 0;
	int counter = 0;
	int* arrThis;
	int* arrTmp;
	int Tmp;



	if (this->Sv > tmp.Sv) {
		tmpSv2 = this->Sv;
		tmpSv = tmp.Sv;
	}
	else
	{
		tmpSv2 = tmp.Sv;
		tmpSv = this->Sv;
	}

	Tmp = tmpSv;

	while (tmpSv != 0)
	{
		counter++;
		tmpSv = tmpSv / maxSt;
	}

	tmpSv = Tmp;


	arrThis = new int[counter];
	arrTmp = new int[counter];


	for (int i = 0; i < counter; i++) {

		Tmp = tmpSv % maxSt;
		tmpSv = tmpSv / maxSt;

		arrThis[i] = Tmp;

		Tmp = tmpSv2 % maxSt;
		tmpSv2 = tmpSv2 / maxSt;

		arrTmp[i] = Tmp;

		if (arrThis[i] + arrTmp[i] >= maxSt) {
			return;
		}

	}

	this->Sv = this->Sv + tmp.Sv;
	this->coeff = this->coeff * tmp.coeff;


}

int Monom::getCoeff() {
	return coeff;
}

void Monom::setCoeff(int newCoeff) {
	coeff = newCoeff;
}


int Monom::getSv() {
	return Sv;
}

void Monom::setSv(int newSv) {
	Sv = newSv;
}

Monom* Monom::getNext() {
	return next;
}

void Monom::setNext(Monom* tmp) {
	next = tmp;
}

void Monom::setFirst()
{
	first = true;
}

bool Monom::getFirst()
{
	return first;
}

Monom& Monom::operator=(const Monom& tmp) {
	if (this != &tmp) {
		this->coeff = tmp.coeff;
		this->Sv = tmp.Sv;
		this->next = this;
	}
	return *this;
}

std::string Monom::toString(int countv, int maxSt)
{


	int* k = new int[countv];

	for (int i = 0; i < countv; i++) {
		k[i] = 0;
	}

	std::string monom = std::to_string(coeff);

	int tmpSv = Sv;
	int i = countv - 1;

	while (tmpSv != 0)
	{

		k[i--] = tmpSv % maxSt;
		tmpSv = tmpSv / maxSt;

	}

	for (int j = 1; j <= countv; j++) {

		if (k[countv - j] > 1) {
			monom = monom + "x" + std::to_string(j) + "^" + std::to_string(k[countv - j]);
		}
		else
		{
			if (k[countv - j] == 1) {
				monom = monom + "x" + std::to_string(j) + "^" + "1";
			}

		}

	}

	return monom;

}