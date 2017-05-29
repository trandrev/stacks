#pragma once

template <typename ELEM>
class Tstack
{
private:
	ELEM *mass;
	size_t maxSize;
	size_t currentElem;
public:
	Tstack() :maxSize(0), currentElem(0){
		mass = 0;
		mass = 0;
	};
	Tstack(size_t size) :currentElem(0),maxSize(size)
	{
		this->mass = new ELEM[size];
	}
	void printstack()
	{
		for (int i = currentElem-1; i >= 0; i--)
			std::cout << mass[i]<<"|";
	}
	void push(const ELEM& elem)
	{
		if (this->currentElem == this->maxSize) // Íå ïåðåïîëíåí ëè ñòåê?
			throw 1;
		
		this->mass[this->currentElem++] = elem;
	}
	ELEM pop()//Âîçâðàùàåò è âûðåçàåò ïîñëåäíèé
	{
		if (this->currentElem == 0) // Íå ïåðåïîëíåí ëè ñòåê?
			throw 2;

		return this->mass[--this->currentElem];
	}
	ELEM back()
	{
		if (this->currentElem == 0) // Íå ïåðåïîëíåí ëè ñòåê?
			throw 2;

		return this->mass[this->currentElem-1];
	}

	void resize(size_t newSize)
	{
		ELEM *tmp;
		size_t tmpMS = maxSize;
		maxSize = newSize;
		if(currentElem > maxSize)
    		currentElem = maxSize;
		tmp = new ELEM[maxSize];
		for (size_t i = 0; i < maxSize && i < tmpMS; i++)
			tmp[i] = mass[i];
		

		delete mass;
		mass = tmp;
	}

};
