#include <iostream>
#include <vector>
#include "Vector.h"
#include "SLinkedList.h"
#include "ShallowDummy.h"
#include "Vector3.h"
#include <string>

template<typename T>
void PrintVector(const Sqwack::Vector<T>& vector)
{
	for (size_t i = 0; i < vector.GetSize(); ++i)
	{
		std::cout << vector[i] << std::endl;
		
	}

	std::cout << "---------------------------------------" << std::endl;
}


template<typename T>
void IterateList(Sqwack::SLinkedList<T>& list)
{
	auto ptr = list.GetFirstNode();

	while (ptr)
	{
		std::cout << ptr->GetData() << std::endl;
		ptr = ptr->Next();

	}
}




int main()
{	
	std::cout << "Hello World! \n";

	Sqwack::SLinkedList<std::string> test;

	
	test.EmplaceBack("1.0f");
	IterateList(test);


	
	

	return 0;
}