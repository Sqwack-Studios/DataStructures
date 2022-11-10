/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: ShallowDummy.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 09/11/2022 17:21:36													 
//==============================================================================//

#ifndef _DataStructures_ShallowDummy_CPP_
#define _DataStructures_ShallowDummy_CPP_

#pragma once
#include "ShallowDummy.h"

ShallowDummy::ShallowDummy():
	ShallowDummy(0)
{

}

ShallowDummy::ShallowDummy(const uint16_t& X):
	X(X)
{

}

ShallowDummy::ShallowDummy(const ShallowDummy& otherDummy):
	X(otherDummy.X)
{
	std::cout << "Copy constructor!" << std::endl;
}

ShallowDummy::ShallowDummy(ShallowDummy&& otherDummy) noexcept :
	X(otherDummy.X)
{
	std::cout << "Move constructor!" << std::endl;
}

ShallowDummy::~ShallowDummy()
{
	std::cout << "Destroying ShallowDummy!" << std::endl;
}

std::ostream& operator<<(std::ostream& outConsole, const ShallowDummy& dummy)
{
	
	std::cout << "This is ShallowDummy with Value: " << dummy.X << std::endl;

	return outConsole;
}

ShallowDummy& ShallowDummy::operator=(const ShallowDummy& otherDummy)
{
	X = otherDummy.X;
	std::cout << "Copy operator assignement!" << std::endl;

	return *this;
}

ShallowDummy& ShallowDummy::operator=(ShallowDummy&& otherDummy) noexcept
{
	X = otherDummy.X;
	std::cout << "Move operator assignement!" << std::endl;

	return *this;
}


#endif // !_DataStructures_ShallowDummy_CPP_

