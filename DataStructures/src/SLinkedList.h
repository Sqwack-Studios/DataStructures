/*===============================================================================/
/ Sqwack Studios, 2022															 /
/===============================================================================*/
//==============================================================================//
// Name				: SLinkedList.h											 
// Author			: Dani										
// Version			:														     
// Creation time	: 09/11/2022 16:40:20													 
//==============================================================================//

#ifndef _DataStructures_SLinkedList_H_
#define _DataStructures_SLinkedList_H_


// SLinkedList class manages the nodes and hold references to the head of the list
// 
//   NODE                    NODE
// |=======|    Next      |=======|    Next
// |P|DATA |  --------->  |P| DATA| ----------->  ....
// |=======|			  |=======|
//

// Specially careful with copy and move semantics. Watch-out deleting data.


namespace Sqwack
{
	template<typename T> class SLinkedList;
	template<typename SLinkedList> class Node;


#pragma once
	template<typename List>
	class Node
	{
	public:
		using DataType = typename List::DataType;
		using ReferenceType = DataType&;
		using NodePtr = Node<List>*;

	public:
		//How do I initialize data that is templated????

	

		template<typename...Args>
		Node(Args&&...args):
			m_NextNode(nullptr),
			m_Data(std::forward<Args>(args)...)
		{

		}

		~Node()
		{
			m_NextNode = nullptr;
		}

		inline DataType& GetData()
		{
			return m_Data;
		}

		inline const DataType& GetData() const
		{
			return m_Data;
		}

		NodePtr Next()
		{
			return m_NextNode;
		}

	private:
		friend class SLinkedList<DataType>;

		

		void SetNextNode(NodePtr nextNode)
		{
			m_NextNode = nextNode;
		}

		DataType                          m_Data;
		NodePtr                           m_NextNode;

	};


	template<typename T>
	class SLinkedList
	{
	public:
		using DataType = T;
		using PointerType = DataType*;
		using ReferenceType = DataType&;
		using NodePtr = Node<SLinkedList<DataType>>*;

	public:
		SLinkedList() :
			m_Head(nullptr)
		{

		}

		~SLinkedList()
		{
			NodePtr headToClean{ GetFirstNode() };
			NodePtr nextHead{ GetFirstNode() };

			while (nextHead)
			{
				nextHead = headToClean->Next();
				delete headToClean;
				headToClean = nextHead;
			}
		}

		NodePtr GetFirstNode()
		{
			return m_Head;
		}

		const NodePtr GetFirstNode() const
		{
			return m_Head;
		}

		

		NodePtr InsertBack(const DataType& data)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>;
			newNode->m_Data = data;

			//Check for the first insertion
			if (GetFirstNode() == nullptr)
			{
				m_Head = newNode;
			}
			//Look for the last element in the linked list and connect the last element with the new one
			else
			{
				NodePtr lastNode = GetLastNode();
				lastNode->SetNextNode(newNode);
			}

			
			

			return newNode;

		}

		NodePtr InsertFront(const DataType& data)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>;
			newNode->m_Data = data;

			NodePtr oldHead = GetFirstNode();
			m_Head = newNode;
			

			if (!GetFirstNode())
			{
				m_Head->SetNextNode(oldHead);
				
			}

			return newNode;

		}


		NodePtr Append(const DataType& data, NodePtr appendedAfter)
		{
			if (FindNode(appendedAfter))
			{
				NodePtr newNode = new Node<SLinkedList<DataType>>;
				NodePtr oldNextNode = appendedAfter->Next();
				newNode->m_Data = data;

				appendedAfter->SetNextNode(newNode);
				newNode->SetNextNode(oldNextNode);

				return newNode;
			}
			
			return nullptr;


		}

		NodePtr InsertBack(DataType&& data)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>;
			newNode->m_Data = std::move(data);

			//Check for the first insertion
			if (GetFirstNode() == nullptr)
			{
				m_Head = newNode;
			}
			//Look for the last element in the linked list and connect the last element with the new one
			else
			{
				NodePtr lastNode = GetLastNode();
				lastNode->SetNextNode(newNode);
			}




			return newNode;

		}

		NodePtr InsertFront(DataType&& data)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>;
			newNode->m_Data = std::move(data);

			NodePtr oldHead = GetFirstNode();
			m_Head = newNode;


			if (!GetFirstNode())
			{
				m_Head->SetNextNode(oldHead);

			}

			return newNode;

		}


		NodePtr Append(DataType&& data, NodePtr appendedAfter)
		{
			if (FindNode(appendedAfter))
			{
				NodePtr newNode = new Node<SLinkedList<DataType>>;
				NodePtr oldNextNode = appendedAfter->Next();
				newNode->m_Data = std::move(data);

				appendedAfter->SetNextNode(newNode);
				newNode->SetNextNode(oldNextNode);

				return newNode;
			}

			return nullptr;


		}

		template<typename...Args>
		NodePtr EmplaceBack(Args&&... args)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>(std::forward<Args>(args)...);

			//Check for the first insertion
			if (GetFirstNode() == nullptr)
			{
				m_Head = newNode;
			}
			//Look for the last element in the linked list and connect the last element with the new one
			else
			{
				NodePtr lastNode = GetLastNode();
				lastNode->SetNextNode(newNode);
			}

			return newNode;
		}

		template<typename...Args>
		NodePtr EmplaceFront(Args&&... args)
		{
			NodePtr newNode = new Node<SLinkedList<DataType>>(std::forward<Args>(args)...);

			NodePtr oldHead = GetFirstNode();
			m_Head = newNode;


			if (!GetFirstNode())
			{
				m_Head->SetNextNode(oldHead);

			}

			return newNode;
		}

		template<typename...Args>
		NodePtr EmplaceAppend(Args&&... args, NodePtr appendedAfter)
		{
			if (FindNode(appendedAfter))
			{
				NodePtr newNode = new Node<SLinkedList<DataType>>(std::forward<Args>(args)...);
				NodePtr oldNextNode = appendedAfter->Next();


				appendedAfter->SetNextNode(newNode);
				newNode->SetNextNode(oldNextNode);

				return newNode;
			}

			return nullptr;
		}
		

		
	private:

		NodePtr GetLastNode()
		{

			NodePtr nextNode{ m_Head };
			NodePtr lastNode{ m_Head };

			while (nextNode != nullptr)
			{
				lastNode = nextNode;
				nextNode = nextNode->Next();
			}

			return lastNode;

		}

		bool FindNode(NodePtr nodeToFind)
		{
			NodePtr nextNode{ m_Head };
			while (nextNode != nodeToFind || !nextNode)
			{
				nextNode = nextNode->Next();
			}

			return nextNode;
		}

		
	private:
		NodePtr                 m_Head;
		
	};



}

#endif // !_DataStructures_SLinkedList_H_

