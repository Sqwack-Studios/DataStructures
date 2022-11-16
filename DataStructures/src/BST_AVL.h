/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: BST_AVL.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 16/11/2022 20:34:32													 
//==============================================================================//

#ifndef _DataStructures_BST_AVL_H_
#define _DataStructures_BST_AVL_H_

#pragma once

namespace Sqwack
{
	//typename T MUST BE a comparable object/type

	template <typename T>
	class BST_AVL
	{
	public:

		using ValueType = T;

	private:

		struct AVL_Node
		{
			ValueType         m_Data;
			AVL_Node*         m_Left;
			AVL_Node*         m_Right;
			int               height;

			AVL_Node()
		};
	};

}
#endif // !_DataStructures_BST_AVL_H_

