#pragma once
#include "Monom.h"
#include <string>

class circle_list
{
public:
	circle_list(int);
	circle_list(const circle_list& tmp);
	~circle_list();

	const circle_list& operator=(const circle_list& tmp);
	const circle_list& operator+(const circle_list& tmp);
	const circle_list& operator-(const circle_list& tmp);
	const circle_list& operator*(const circle_list& tmp);
	const circle_list& operator*(const int& tmp);

	void add(Monom& tmp);
	void add(int a, int Sv);
	void erase(int a, int Sv);

	std::string to_string(int n = 6);



private:

	Monom* first;
	int counter;
	int maxSt;

};

circle_list::~circle_list()
{

}

circle_list::circle_list(int maxStNew = 10)
{
	first = new Monom;
	first->setFirst();
	counter = 1;
	maxSt = maxStNew;
}

circle_list::circle_list(const circle_list& tmp)
{
	this->first = new Monom;
	this->first->setFirst();
	this->counter = 1;
	this->maxSt = tmp.maxSt;
	Monom* monomTmp = tmp.first->getNext();

	for (int i = 2; i <= tmp.counter; i++) {

		this->add(monomTmp->getCoeff(), monomTmp->getSv());

		monomTmp = monomTmp->getNext();

	}

}


const circle_list& circle_list::operator=(const circle_list& tmp)
{
	if (this != &tmp) {
		this->first = new Monom;
		this->first->setFirst();
		this->counter = 1;
		this->maxSt = tmp.maxSt;
		Monom* monomTmp = tmp.first->getNext();

		for (int i = 2; i <= tmp.counter; i++) {

			this->add(monomTmp->getCoeff(), monomTmp->getSv());

			monomTmp = monomTmp->getNext();

		}
	}

	return *this;
}

const circle_list& circle_list::operator+(const circle_list& tmp) {

	circle_list* newThis = new circle_list(this->maxSt);

	Monom* a = this->first->getNext();
	Monom* b = tmp.first->getNext();

	for (int i = 2; i <= this->counter; i++) {

		newThis->add(a->getCoeff(), a->getSv());
		a = a->getNext();

	}


	for (int i = 2; i <= tmp.counter; i++) {

		newThis->add(b->getCoeff(), b->getSv());
		b = b->getNext();

	}

	return *newThis;

}



const circle_list& circle_list::operator-(const circle_list& tmp)
{
	circle_list* newThis = new circle_list(this->maxSt);

	Monom* a = this->first->getNext();
	Monom* b = tmp.first->getNext();

	for (int i = 2; i <= this->counter; i++) {

		newThis->add(a->getCoeff(), a->getSv());
		a = a->getNext();

	}


	for (int i = 2; i <= tmp.counter; i++) {

		newThis->add(b->getCoeff() * -1, b->getSv());
		b = b->getNext();

	}

	return *newThis;
}


const circle_list& circle_list::operator*(const circle_list& tmp) {

	circle_list* newThis = new circle_list(this->maxSt);


	if (this->counter == 1) {
		return *newThis;
	}

	Monom* monomThis = this->first->getNext();
	Monom* monomTmp = tmp.first->getNext();
	Monom monom ;


	for (int i = 2; i <= this->counter; i++) {

		for (int j = 2; j <= tmp.counter; j++) {

			if (j == 2) {
				monom = Monom(monomThis->getCoeff(), monomThis->getSv());
			}

			monom.monomMult(*monomTmp, maxSt);

			if (j == tmp.counter) {

				newThis->add(monom);

			}

			monomTmp = monomTmp->getNext();

		}

		monomTmp = tmp.first->getNext();

		monomThis = monomThis->getNext();

	}

	return *newThis;

}

const circle_list& circle_list::operator*(const int& tmp) {

	int a;

	circle_list* newThis = new circle_list(this->maxSt);

	Monom* iterMonom = this->first->getNext();

	while (true)
	{

		if (iterMonom->getFirst()) {
			break;
		}

		a = iterMonom->getCoeff();

		newThis->add(a * tmp, iterMonom->getSv());

		iterMonom = iterMonom->getNext();
	}

	return *newThis;

}


void circle_list::add(Monom& tmp)
{
	if (counter == 1) {
		counter++;
		first->setNext(new Monom(tmp.getCoeff(), tmp.getSv()));
		first->getNext()->setNext(first);
		return;
	}
	else
	{
		int newCoeff = -1;
		Monom* newMonom = first->getNext();

		for (int i = 2; i <= counter; i++) {

			if (newMonom->getSv() == tmp.getSv()) {

				newCoeff = newMonom->getCoeff() + tmp.getCoeff();

				if (newCoeff == 0) {
					erase(newMonom->getCoeff(), newMonom->getSv());
					return;
				}

				else
				{
					newMonom->setCoeff(newCoeff);
					return;
				}
			}
			if (i != counter) {
				newMonom = newMonom->getNext();
			}

		}

		newMonom->setNext(new Monom(tmp.getCoeff(), tmp.getSv()));

		counter++;

		newMonom->getNext()->setNext(first);
	}

}

void circle_list::add(int a, int Sv)
{

	if (counter == 1) {
		counter++;
		first->setNext(new Monom(a, Sv));
		first->getNext()->setNext(first);
		return;
	}
	else
	{
		int newCoeff = -1;
		Monom* newMonom = first->getNext();

		for (int i = 2; i <= counter; i++) {

			if (newMonom->getSv() == Sv) {

				newCoeff = newMonom->getCoeff() + a;

				if (newCoeff == 0) {
					erase(newMonom->getCoeff(), newMonom->getSv());
					return;
				}

				else
				{
					newMonom->setCoeff(newCoeff);
					return;
				}
			}
			if (i != counter) {
				newMonom = newMonom->getNext();
			}

		}

		newMonom->setNext(new Monom(a, Sv));

		counter++;

		newMonom->getNext()->setNext(first);
	}

}

void circle_list::erase(int a, int Sv)
{
	Monom* prev;
	Monom* cur = first->getNext();
	Monom* next = cur->getNext();

	if (counter == 1) {
		return;
	}

	if (cur->getCoeff() == a && cur->getSv() == Sv) {
		first->setNext(next);
		counter--;
		return;
	}

	prev = cur;
	cur = next;
	next = next->getNext();

	while (true)
	{

		if (cur->getFirst()) {
			return;
		}

		if (cur->getCoeff() == a && cur->getSv() == Sv && !cur->getFirst()) {
			prev->setNext(next);
			counter--;
			return;
		}

		prev = cur;
		cur = next;
		next = next->getNext();

	}

}

std::string circle_list::to_string(int n)
{


	if (counter == 1) {
		return "0";
	}

	std::string list;

	Monom* tmp = this->first->getNext();

	list = tmp->toString(n, maxSt);

	tmp = tmp->getNext();

	while (true)
	{
		if (tmp->getFirst()) {
			return list;
		}

		if (tmp->getCoeff() < 0) {
			list +=tmp->toString(n, maxSt);
		}
		else
		{
			list += "+" + tmp->toString(n, maxSt);
		}

		tmp = tmp->getNext();

	}
}


