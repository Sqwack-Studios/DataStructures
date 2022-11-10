/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: ShallowDummy.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 09/11/2022 17:18:16													 
//==============================================================================//

#ifndef _DataStructures_ShallowDummy_H_
#define _DataStructures_ShallowDummy_H_

#pragma once
#include <stdint.h>
#include <iostream>

class ShallowDummy
{
public:
	ShallowDummy();
	ShallowDummy(const uint16_t& X);
	ShallowDummy(const ShallowDummy& otherDummy);
	ShallowDummy(ShallowDummy&& otherDummy) noexcept;
	~ShallowDummy();

	ShallowDummy& operator=(const ShallowDummy& otherDummy);
	ShallowDummy& operator=(ShallowDummy&& otherDummy) noexcept;

	void PrintHi()
	{
		std::cout << "Hi" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& stream, const ShallowDummy& dummy);


private:
	uint16_t      X;
};
#endif // !_DataStructures_ShallowDummy_H_

