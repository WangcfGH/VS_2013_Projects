// DataStructure.cpp : 定义控制台应用程序的入口点。
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

	// 弹出头结点
	Node<T>* PopNode();
	// 追加节点(加到尾部)
	bool PushNode(Node<T>* pNode);
	// 获取指点位置节点
	Node<T>* GetNode(int nIndex);
	// 插入指定位置节点
	bool InsertNode(int nIndex, Node<T>* pNode);
	// 查找节点
	bool FindNode(Node<T>* pNode);
	// 删除指定节点
	bool RemoveNode(int nIndex);
	// 打印所有节点
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

// 弹出头结点
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

// 追加节点(加到尾部)
template<typename T>
bool MyLinkList<T>::PushNode(Node<T>* pNode)
{
	// 空链表
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_nLen++;
		return true;
	}

	// 非空链表
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

// 获取指点位置节点
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

// 插入指定位置节点
template<typename T>
bool MyLinkList<T>::InsertNode(int nIndex, Node<T>* pNode)
{
	// 超出范围
	if (nIndex < 0 || nIndex > m_nLen)
	{
		return false;
	}

	// 插入至头部
	if (nIndex == 0)
	{
		pNode->pNext = m_pHead;
		m_pHead = pNode;
		m_nLen++;
		return true;
	}

	// 插入非头部
	Node<T>* pPre = GetNode(nIndex - 1);
	pNode->pNext = pPre->pNext;
	pPre->pNext = pNode;
	m_nLen++;
	return true;
	
}

// 查找节点
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

// 删除指定节点
template<typename T>
bool MyLinkList<T>::RemoveNode(int nIndex)
{
	if (nIndex < 0 || nIndex >= m_nLen)
	{
		return false;
	}

	// 删除头节点
	Node<T>* pHeadTemp = m_pHead;
	if (nIndex == 0)
	{
		m_pHead = pHeadTemp->pNext;
		delete pHeadTemp;

		m_nLen--;
		return true;
	}

	// 删除非头节点
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

// 打印所有节点
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
		// 删除头结点
		delete m_pHead;

		// 节点数量减一
		m_nLen--;

		// 头节点指针往后移
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

