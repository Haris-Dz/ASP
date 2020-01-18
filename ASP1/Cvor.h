#pragma once
struct Cvor
{
	int info;
	Cvor* next;
	Cvor(int info, Cvor* next = nullptr)
	{
		this->info = info;
		this->next = next;
	}
}; 
