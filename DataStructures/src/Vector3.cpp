/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Vector3.cpp										
// Author			: Dani										 
// Version			:														     
// Creation time	: 08/11/2022 20:55:16													 
//==============================================================================//

#ifndef _DataStructures_Vector3_CPP_
#define _DataStructures_Vector3_CPP_

#pragma once
#include <iostream>
#include "Vector3.h"


Vector3::Vector3():
	Vector3(0)
{

}

Vector3::Vector3(const float& scalar):
	Vector3(scalar, scalar, scalar)
{

}

Vector3::Vector3(const float& x, const float& y, const float& z):
	m_X(x),
	m_Y(y),
	m_Z(z),
	m_memoryBlock(nullptr)
{
	m_memoryBlock = new int[5];
}

//Vector3::Vector3(const Vector3& otherVector) :
//	m_X(otherVector.m_X),
//	m_Y(otherVector.m_Y),
//	m_Z(otherVector.m_Z)
//{
//
//	std::cout << "Copying Vector3!" << std::endl;
//}

Vector3::Vector3(Vector3&& otherVector) noexcept :
	m_X(otherVector.m_X),
	m_Y(otherVector.m_Y),
	m_Z(otherVector.m_Z)
{
	m_memoryBlock = otherVector.m_memoryBlock;
	otherVector.m_memoryBlock = nullptr;
	std::cout << "Moving Vector3!" << std::endl;
}

Vector3::~Vector3()
{
	std::cout << "Destroying Vector3!" << std::endl;
	delete[] m_memoryBlock;
}

std::ostream& operator<<(std::ostream& outConsole, const Vector3& vector3)
{
	std::cout << "Vector3: (" << vector3.m_X << ", " << vector3.m_Y << ", " << vector3.m_Z << ")" << std::endl;
	return outConsole;
}

//Vector3& Vector3::operator=(const Vector3& otherVector)
//{
//	std::cout << "Copy assign operator" << std::endl;
//	m_X = otherVector.m_X;
//	m_Y = otherVector.m_Y;
//	m_Z = otherVector.m_Z;
//
//	return *this;
//}

Vector3& Vector3::operator=(Vector3&& otherVector) noexcept
{
	std::cout << "Move assign operator" << std::endl;
	m_X = otherVector.m_X;
	m_Y = otherVector.m_Y;
	m_Z = otherVector.m_Z;

	delete[] m_memoryBlock;

	m_memoryBlock = otherVector.m_memoryBlock;
	otherVector.m_memoryBlock = nullptr;

	return *this;
}


#endif // !_DataStructures_Vector3_CPP_

