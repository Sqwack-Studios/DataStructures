/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Vector3.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 08/11/2022 20:49:32													 
//==============================================================================//

#ifndef _DataStructures_Vector3_H_
#define _DataStructures_Vector3_H_

#pragma once
#include <iostream>

class Vector3
{
public:
	Vector3();
	Vector3(const float& scalar);
	Vector3(const float& x, const float& y, const float& z);
	Vector3(const Vector3& otherVector) = delete;
	Vector3(Vector3&& otherVector) noexcept;
	~Vector3();


	Vector3& operator=(const Vector3& otherVector) = delete;
	Vector3& operator=(Vector3&& otherVector) noexcept;

	friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector3);

private:
	float m_X, m_Y, m_Z;
	int* m_memoryBlock;

};
#endif // !_DataStructures_Vector3_H_

