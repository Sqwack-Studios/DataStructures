/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: Vector.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 08/11/2022 17:32:10													 
//==============================================================================//

#ifndef _DataStructures_Vector_H_
#define _DataStructures_Vector_H_

#pragma once
#include <assert.h>

//Specifications:
//- Default, copy, move constructors
//- Copy, move operators
//- [] operator
// 
//

namespace Sqwack
{
	template<typename Vector>
	class VectorIterator
	{
	public:
		using ValueType = typename Vector::ValueType;
		using PointerType = ValueType*;
		using ReferenceType = ValueType&;
	public:
		VectorIterator(PointerType ptr):
			m_Ptr(ptr)
		{

		}

		VectorIterator& operator++()
		{
			m_Ptr++;
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator iterator = *this;
			++(*this);
			return iterator;
		}

		VectorIterator& operator--()
		{
			m_Ptr--;
			return *this;
		}

		VectorIterator operator--(int)
		{
			VectorIterator iterator = *this;
			--(*this);
			return iterator;
		}

		ReferenceType operator[](size_t index)
		{
			return *(m_Ptr + index);
		}

		PointerType operator->()
		{
			return m_Ptr;
		}

		ReferenceType operator*()
		{
			return *m_Ptr;
		}

		bool operator==(const VectorIterator& other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator !=(const VectorIterator& other) const
		{
			return m_Ptr != other.m_Ptr;
		}

	private:

		PointerType m_Ptr;

	};

	template<typename T>
	class Vector
	{
	public:
		using ValueType = T;
		using Iterator = VectorIterator<Vector<ValueType>>;

	public:
		Vector():
			m_Data(nullptr),
			m_Size(0),
			m_Capacity(0)
		{
			//We have to allocate memory for the first time

			SetCapacity(2);
			ReAlloc(2);
		}

		~Vector()
		{
			Clear();
			::operator delete(m_Data, GetCapacity() * sizeof(T));
		}

		inline size_t GetSize() const { return m_Size; }
		inline size_t GetCapacity() const { return m_Capacity; }

		T& PushBack(const T& value)
		{
			if (GetSize() >= GetCapacity())
			{
				ReAlloc(GetCapacity() + GetCapacity() / 2);
			}
			
			new(&m_Data[m_Size++]) T(value);
			
			return m_Data[m_Size - 1];

		}

		T& PushBack(T&& value)
		{
			if (GetSize() >= GetCapacity())
			{
				ReAlloc(GetCapacity() + GetCapacity() / 2);
			}

			new(&m_Data[m_Size++]) T(std::move(value));

			return m_Data[m_Size - 1];
		}

		const T& operator[](size_t index) const
		{
			assert(!(index >= GetSize()));

			return m_Data[index];
		}

		T& operator[](size_t index)
		{
			assert(!(index >= GetSize()));

			return m_Data[index];
		}

		template<typename...Args>
		T& EmplaceBack(Args&&...args)
		{
			if (GetSize() >= GetCapacity())
			{
				ReAlloc(GetCapacity() + GetCapacity() / 2);
			}

			new(&m_Data[m_Size++]) T(std::forward<Args>(args)...);

			return m_Data[m_Size - 1];
		}

		void PopBack()
		{
			if (GetSize() > 0)
			{
				--m_Size;
				m_Data[m_Size].~T();
			}
		}

		void Clear()
		{
			for (size_t i = 0; i < m_Size; i++)
			{
				m_Data[i].~T();
			}
			m_Size = 0;
		}

		void Resize()
		{

		}

		void Reserve()
		{

		}

		Iterator begin()
		{
			return Iterator(m_Data);
		}

		Iterator end()
		{
			return Iterator(m_Data + GetSize());
		}
		
	private: 
		//Remember to check if we should adjust the size
		void AdjustSizeForCapacity(size_t newCapacity)
		{
			if (GetSize() > newCapacity)
				m_Size = newCapacity;
		}

		inline void SetCapacity(size_t newCapacity) { m_Capacity = newCapacity; }

		void ReAlloc(size_t NewCapacity)
		{
			//In order to realloc new memory, we have to copy the contents of the old block of memory to the newly created one
			//We need to be able to allocate and deallocate memory in such a way that there are no constructors or 
			//destructors involved, so that we can clear and delete memory properly...

			T* newBlock = static_cast<T*>(::operator new(NewCapacity * sizeof(T)));

			size_t oldSize{ GetSize() };

			AdjustSizeForCapacity(NewCapacity);
			size_t currentSize{ GetSize() };

			for (size_t i = 0; i < currentSize; ++i)
			{
				new(&newBlock[i]) T(std::move(m_Data[i]));
			}
			for (size_t i = 0; i < oldSize; ++i)
			{
				m_Data[i].~T();
			}




			//We are freeing just a block of memory. That's why we have to manually call the class destructor.
			::operator delete(m_Data, GetCapacity() * sizeof(T));
			SetCapacity(NewCapacity);
			m_Data = newBlock;
		}


	private:
		T*                     m_Data;
		size_t                 m_Capacity; //Maximum available space to push new objects of type T
		size_t                 m_Size;     //Current amount of objects in m_Data

	};


	

}








#endif // !_DataStructures_Vector_H_

