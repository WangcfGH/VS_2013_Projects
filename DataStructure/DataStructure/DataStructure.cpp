// DataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node
{
public:
	Node(T objT);
	~Node();

public:
	T tData;
	Node<T>* pNext;
};

template<typename T>
Node<T>::Node(T objT)
{
	tData = objT;
	pNext = nullptr;
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
class MyLinkList
{
public:
	MyLinkList();
	~MyLinkList();

	// ����ͷ���
	Node<T>* PopNode();
	// ׷�ӽڵ�(�ӵ�β��)
	bool PushNode(Node<T>* pNode);
	// ��ȡָ��λ�ýڵ�
	Node<T>* GetNode(int nIndex);
	// ����ָ��λ�ýڵ�
	bool InsertNode(int nIndex, Node<T>* pNode);
	// ���ҽڵ�
	bool FindNode(Node<T>* pNode);
	// ɾ��ָ���ڵ�
	bool RemoveNode(int nIndex);
	// ��ӡ���нڵ�
	void PrintAllNode();


public:
	int m_nLen;
	Node<T>* m_pHead;
};

template<typename T>
MyLinkList<T>::MyLinkList()
{
	m_nLen = 0;
	m_pHead = nullptr;
}

// ����ͷ���
template<typename T>
Node<T>* MyLinkList<T>::PopNode()
{
	if (m_nLen == 0)
	{
		return nullptr;
	}

	Node<T>* pHeadTmep = m_pHead;	
	m_pHead = m_pHead.pNext;
	pHeadTmep->pNext = nullptr;

	m_nLen--;

	return pHeadTmep;
}

// ׷�ӽڵ�(�ӵ�β��)
template<typename T>
bool MyLinkList<T>::PushNode(Node<T>* pNode)
{
	// ������
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_nLen++;
		return true;
	}

	// �ǿ�����
	Node<T>* pHeadTmep = m_pHead;
	while (pHeadTmep->pNext != nullptr)
	{
		pHeadTmep = pHeadTmep->pNext;
	}

	pHeadTmep->pNext = pNode;
	pNode->pNext = nullptr;

	m_nLen++;

	return true;
}

// ��ȡָ��λ�ýڵ�
template<typename T>
Node<T>* MyLinkList<T>::GetNode(int nIndex)
{
	if (nIndex >= m_nLen)
	{
		return nullptr;
	}

	Node<T>* pHeadTemp = m_pHead;
	for (int i = 0; i < m_nLen; i++)
	{
		if (i == nIndex)
		{
			return pHeadTemp;
		}

		pHeadTemp = pHeadTemp->pNext; 
	}

	return nullptr;
}

// ����ָ��λ�ýڵ�
template<typename T>
bool MyLinkList<T>::InsertNode(int nIndex, Node<T>* pNode)
{
	// ������Χ
	if (nIndex < 0 || nIndex > m_nLen)
	{
		return false;
	}

	// ������ͷ��
	if (nIndex == 0)
	{
		pNode->pNext = m_pHead;
		m_pHead = pNode;
		m_nLen++;
		return true;
	}

	// �����ͷ��
	Node<T>* pPre = GetNode(nIndex - 1);
	pNode->pNext = pPre->pNext;
	pPre->pNext = pNode;
	m_nLen++;
	return true;
	
}

// ���ҽڵ�
template<typename T>
bool MyLinkList<T>::FindNode(Node<T>* pNode)
{	
	if (pNode == nullptr || m_nLen == 0)
	{
		return false;
	}

	for (int i == 0; i < m_nLen; i++)
	{
		if (GetNode(i) == pNode)
		{
			return true;
		}
	}

	return false;
}

// ɾ��ָ���ڵ�
template<typename T>
bool MyLinkList<T>::RemoveNode(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nLen)
	{
		return false;
	}

	// ɾ��ͷ�ڵ�
	Node<T>* pHeadTemp = m_pHead;
	if (nIndex == 0)
	{
		m_pHead = pHeadTemp->pNext;
		delete pHeadTemp;

		m_nLen--;
		return true;
	}

	// ɾ����ͷ�ڵ�
	for (int i = 0; i < m_nLen; i++)
	{
		if (i == nIndex - 1)
		{
			break;
		}

		pHeadTemp = pHeadTemp->pNext;
	}

	Node<T>* pNeedRemoveNode = pHeadTemp->pNext;
	pHeadTemp->pNext = pHeadTemp->pNext->pNext;
	delete pNeedRemoveNode;
	m_nLen--;

	return true;
}

// ��ӡ���нڵ�
template<typename T>
void MyLinkList<T>::PrintAllNode()
{
	Node<T>* pHeadTemp = m_pHead;
	while (pHeadTemp != nullptr)
	{
		cout << pHeadTemp->tData << " ";
		pHeadTemp = pHeadTemp->pNext;
	}

	cout << endl;
}

template<typename T>
MyLinkList<T>::~MyLinkList()
{
	while (m_pHead != nullptr && m_nLen > 0)
	{
		Node<T>* pHeadTemp = m_pHead->pNext;
		// ɾ��ͷ���
		delete m_pHead;

		// �ڵ�������һ
		m_nLen--;

		// ͷ�ڵ�ָ��������
		m_pHead = pHeadTemp;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyLinkList<string> myLList;
	myLList.PushNode(new Node<string>(string("Hello")));	
	myLList.PushNode(new Node<string>(string("World"))); 
	myLList.PushNode(new Node<string>(string("By")));
	myLList.PushNode(new Node<string>(string("Wcf")));
	myLList.PrintAllNode();

	myLList.InsertNode(0, new Node<string>(string("20230214")));
	myLList.PrintAllNode();

	myLList.RemoveNode(0);
	myLList.PrintAllNode();

	myLList.RemoveNode(3);
	myLList.PrintAllNode();

	myLList.RemoveNode(1);
	myLList.PrintAllNode();

	
	getchar();
	getchar();
	return 0;
}

