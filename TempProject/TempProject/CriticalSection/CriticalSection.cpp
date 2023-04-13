// CriticalSection.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "afxwin.h"
#include "windows.h"
using namespace std;

CRITICAL_SECTION cs;		//�������Ϊ����һ����Դ
static int n_AddValue = 0;	//����һ����̬��ȫ������n_AddValue

//��һ���߳�
UINT FirstThread(LPVOID lParam)
{
	EnterCriticalSection(&cs);//���� �������Ĵ��봦������в����������߳̽��в�������������LeaveCriticalSection
	for (int i = 0; i < 10; i++){
		n_AddValue++;
		cout << "n_AddValue in FirstThread is " << n_AddValue << endl;

	}
	LeaveCriticalSection(&cs);//���� ��EnterCriticalSection֮�������Դ�Ѿ��ͷ��ˣ������߳̿��Խ��в���   
	return 0;
}

//��һ���߳�
UINT FirstThread_2(LPVOID lParam)
{
	for (int i = 0; i < 10; i++){
		EnterCriticalSection(&cs);//���� �������Ĵ��봦������в����������߳̽��в�������������LeaveCriticalSection
		n_AddValue++;
		cout << "n_AddValue in FirstThread_2 is " << n_AddValue << endl;
		LeaveCriticalSection(&cs);//���� ��EnterCriticalSection֮�������Դ�Ѿ��ͷ��ˣ������߳̿��Խ��в���   
	}
	return 0;
}

//�ڶ����߳�
UINT SecondThread(LPVOID lParam)
{
	EnterCriticalSection(&cs);//����
	for (int i = 0; i < 10; i++){
		n_AddValue++;
		cout << "n_AddValue in SecondThread is " << n_AddValue << endl;

	}
	LeaveCriticalSection(&cs);//����

	return 0;
}

//�ڶ����߳�
UINT SecondThread_2(LPVOID lParam)
{
	for (int i = 0; i < 10; i++){
		EnterCriticalSection(&cs);//����
		n_AddValue++;
		cout << "n_AddValue in SecondThread_2 is " << n_AddValue << endl;
		LeaveCriticalSection(&cs);//����
	}

	return 0;
}

//��������������´���
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��/n"));
		nRetCode = 1;
	}
	else
	{

		InitializeCriticalSection(&cs);//��ʼ���ṹCRITICAL_SECTION


		CWinThread *pFirstThread, *pSecondThread;//�洢����AfxBeginThread���ص�CWinThreadָ��

		pFirstThread = AfxBeginThread(FirstThread, LPVOID(NULL));//������һ���߳�
		pSecondThread = AfxBeginThread(SecondThread, LPVOID(NULL));//�����ڶ����߳�

		HANDLE hThreadHandle[2];
		hThreadHandle[0] = pFirstThread->m_hThread;
		hThreadHandle[1] = pSecondThread->m_hThread;

		//�ȴ��̷߳���
		WaitForMultipleObjects(2, hThreadHandle, TRUE, INFINITE);

		CWinThread *pFirstThread_2, *pSecondThread_2;//�洢����AfxBeginThread���ص�CWinThreadָ��

		pFirstThread_2 = AfxBeginThread(FirstThread_2, LPVOID(NULL));//������һ���߳�
		pSecondThread_2 = AfxBeginThread(SecondThread_2, LPVOID(NULL));//�����ڶ����߳�

		HANDLE hThreadHandle_2[2];
		hThreadHandle_2[0] = pFirstThread_2->m_hThread;
		hThreadHandle_2[1] = pSecondThread_2->m_hThread;

		//�ȴ��̷߳���
		WaitForMultipleObjects(2, hThreadHandle_2, TRUE, INFINITE);
	}

	getchar();
	getchar();

	return nRetCode;
}