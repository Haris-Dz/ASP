#pragma once
template<class T>
struct Cvor
{
	T info;
	Cvor<T>* next;

	Cvor(T info, Cvor<T>* next = nullptr)
	{
		this->info = info;
		this->next = next;
	}
}; 
