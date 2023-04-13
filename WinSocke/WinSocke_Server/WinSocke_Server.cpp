/*
// IOģ��֮Selectģ��
#include "stdafx.h"
#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

int main()
{
	USHORT nPort = 5150;		// �˷����������Ķ˿ں�
	int         ret;
	unsigned long ul = 1;

	// Initialize Windows socket library
	WSADATA     wsaData;
	WSAStartup(0x0202, &wsaData);

	// ���������׽���
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//���óɷ�����ģʽ��selectģʽ��������
	//ret = ioctlsocket(sListen, FIONBIO, (unsigned long *)&ul);
	//����ʧ�ܡ�
	if (ret == SOCKET_ERROR)
	{
		printf("Set ioctlsocket Failed");
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(nPort);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	// ���׽��ֵ����ػ���
	if (::bind(sListen, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf(" Failed bind() \n");
		return -1;
	}

	// �������ģʽ
	::listen(sListen, 5);
	// select ģ�ʹ������
	// 1����ʼ��һ���׽��ּ���fdSocket����Ӽ����׽��־�����������

	fd_set fdSocket;				// ���п����׽��ּ���
	FD_ZERO(&fdSocket);
	FD_SET(sListen, &fdSocket);
	while (TRUE)
	{
		// 2����fdSocket���ϵ�һ������fdRead���ݸ�select ������
		// �����¼�����ʱ��select �����Ƴ�fdRead������û��δ��I/O�������׽��־����Ȼ�󷵻ء�
		fd_set fdRead = fdSocket;
		int nRet = ::select(0, &fdRead, NULL, NULL, NULL);
		if (nRet > 0)
		{

			// 3��ͨ����ԭ��fdSocket ������select �������fdRead���ϱȽϣ�
			// ȷ��������Щ�׽�����δ��I/O������һ��������ЩI/O��

			for (int i = 0; i < (int)fdSocket.fd_count; i++)
			{
				if (FD_ISSET(fdSocket.fd_array[i], &fdRead))
				{
					if (fdSocket.fd_array[i] == sListen)		// ��1�������׽��ֽ��յ�������
					{
						if (fdSocket.fd_count < FD_SETSIZE)
						{
							sockaddr_in addrRemote;
							int nAddrLen = sizeof(addrRemote);
							SOCKET sNew =
								::accept(sListen, (SOCKADDR*)&addrRemote, &nAddrLen);
							FD_SET(sNew, &fdSocket);
							printf("���յ����ӣ�%s��\n", ::inet_ntoa(addrRemote.sin_addr));
						}
						else
						{
							printf(" Too much connections! \n");
							continue;
						}
					}
					else
					{
						char szText[256];
						int nRecv = ::recv(fdSocket.fd_array[i], szText, strlen(szText), 0);
						if (nRecv > 0)  // ��2���ɶ�
						{
							szText[nRecv] = '\0';
							printf("���յ����ݣ�%s \n", szText);
							int nSend = ::send(fdSocket.fd_array[i], szText, strlen(szText), 0);
							if (nSend > 0)
							{
								printf("��Ӧ���ݣ�%s \n", szText);
							}
						}
						else // ��3�����ӹرա����������ж�
						{
							::closesocket(fdSocket.fd_array[i]);
							FD_CLR(fdSocket.fd_array[i], &fdSocket);
							printf("�Ͽ����ӣ�%d \n", fdSocket.fd_array[i]);
						}
					}
				}
			}
		}
		else
		{
			printf(" Failed select() \n");
			break;
		}
	}
	return 0;
}
*/


/*
// IOģ��֮WSAEventSelect(�첽ѡ��)ģ��
#include "stdafx.h"
#include <WinSock2.h>
#include <process.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

#pragma warning(disable:4996)
SOCKET		g_sClient[WSA_MAXIMUM_WAIT_EVENTS] = { INVALID_SOCKET };		//client socket����
WSAEVENT	g_event[WSA_MAXIMUM_WAIT_EVENTS];								//�����¼���������
SOCKET		g_sServer = INVALID_SOCKET;										//server socket 
WSAEVENT	g_hServerEvent;													//server �����¼�����
int			iTotal = 0;														//client����

//function OpenTCPServer             ��TCP������
//param _In_ unsigned short Port     �������˿�
//param  _Out_ DWORD* dwError        �������
//return  �ɹ�����TRUE ʧ�ܷ���FALSE
BOOL OpenTCPServer(_In_ unsigned short Port, _Out_ DWORD* dwError)
{
	BOOL bRet = FALSE;
	WSADATA wsaData = { 0 };
	SOCKADDR_IN ServerAddr = { 0 };
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(Port);
	ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	do
	{
		if (!WSAStartup(MAKEWORD(2, 2), &wsaData))
		{
			if (LOBYTE(wsaData.wVersion) == 2 || HIBYTE(wsaData.wVersion) == 2)
			{
				g_sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				g_hServerEvent = WSACreateEvent();						//���������¼�����
				WSAEventSelect(g_sServer, g_hServerEvent, FD_ACCEPT);	//Ϊserver socketע�������¼� 
				if (g_sServer != INVALID_SOCKET)
				{
					if (SOCKET_ERROR != bind(g_sServer, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr)))
					{
						if (SOCKET_ERROR != listen(g_sServer, SOMAXCONN))
						{
							bRet = TRUE;
							break;
						}
						*dwError = WSAGetLastError();
						closesocket(g_sServer);
					}
					*dwError = WSAGetLastError();
					closesocket(g_sServer);
				}
				*dwError = WSAGetLastError();
			}
			*dwError = WSAGetLastError();

		}
		*dwError = WSAGetLastError();
	} while (FALSE);
	return bRet;
}

//����client�����߳�
unsigned int __stdcall ThreadAccept(void* lparam)
{
	WSANETWORKEVENTS networkEvents;				//�����¼��ṹ
	while (iTotal < WSA_MAXIMUM_WAIT_EVENTS)	//���ֵ��64
	{
		if (0 == WSAEnumNetworkEvents(g_sServer, g_hServerEvent, &networkEvents))
		{
			if (networkEvents.lNetworkEvents & FD_ACCEPT)			//�������FD_ACCEPT�������Ϊ1
			{
				if (0 == networkEvents.iErrorCode[FD_ACCEPT_BIT])  //��������������
				{
					//��������
					SOCKADDR_IN addrServer = { 0 };
					int iaddrLen = sizeof(addrServer);
					g_sClient[iTotal] = accept(g_sServer, (SOCKADDR*)&addrServer, &iaddrLen);
					if (g_sClient[iTotal] == INVALID_SOCKET)
					{
						printf("accept failed with error code: %d\n", WSAGetLastError());
						return 1;
					}
					//Ϊ�µ�clientע�������¼�
					g_event[iTotal] = WSACreateEvent();
					WSAEventSelect(g_sClient[iTotal], g_event[iTotal], FD_READ | FD_WRITE | FD_CLOSE);
					iTotal++;
					printf("accept a connection from IP: %s,Port: %d\n", inet_ntoa(addrServer.sin_addr), htons(addrServer.sin_port));
				}
				else  //������
				{
					int iError = networkEvents.iErrorCode[FD_ACCEPT_BIT];
					printf("WSAEnumNetworkEvents failed with error code: %d\n", iError);
					return 1;
				}
			}
		}
		Sleep(100);
	}
	return 0;
}

//��������
unsigned int __stdcall ThreadRecv(void* lparam)
{
	char* buf = (char*)malloc(sizeof(char) * 128);
	while (1)
	{
		if (iTotal == 0)
		{
			Sleep(100);
			continue;
		}
		//�ȴ������¼�
		DWORD dwIndex = WSAWaitForMultipleEvents(iTotal, g_event, FALSE, 1000, FALSE);
		//��ǰ���¼�����
		WSAEVENT curEvent = g_event[dwIndex];
		//��ǰ���׽���
		SOCKET sCur = g_sClient[dwIndex];
		//�����¼��ṹ
		WSANETWORKEVENTS networkEvents;
		if (0 == WSAEnumNetworkEvents(sCur, curEvent, &networkEvents))
		{
			if (networkEvents.lNetworkEvents & FD_READ)  //�����ݿɶ�
			{
				if (0 == networkEvents.iErrorCode[FD_READ_BIT])
				{
					memset(buf, 0, sizeof(buf));
					int iRet = recv(sCur, buf, sizeof(buf), 0);  //��������
					if (iRet != SOCKET_ERROR)
					{
						buf[iRet] = '\0';
						if (strlen(buf) != 0)
							printf("Recv: %s\n", buf);
					}
				}
				else //������
				{
					int iError = networkEvents.iErrorCode[FD_ACCEPT_BIT];
					printf("WSAEnumNetworkEvents failed with error code: %d\n", iError);
					break;
				}
			}
			else if (networkEvents.lNetworkEvents & FD_CLOSE)	//client�ر�
				printf("%d downline\n", sCur);
		}
		Sleep(100);
	}
	if (buf)
		free(buf);
	return 0;
}

int main()
{
	DWORD dwError = 0;
	if (OpenTCPServer(5150, &dwError))
	{
		_beginthreadex(NULL, 0, ThreadAccept, NULL, 0, NULL);
		_beginthreadex(NULL, 0, ThreadRecv, NULL, 0, NULL);
	}
	Sleep(100000000);
	closesocket(g_sServer);
	WSACleanup();
	return 0;
}
*/



/*
// IOģ��֮wsaasyncselectģ�ͣ����ܱ���ͨ��
#include "stdafx.h"
#include <WinSock2.h>
#include <process.h>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

#pragma warning(disable:4996)

#define WM_SOCKET (WM_USER + 101)        // �Զ�����Ϣ
#define MAX_LEN 1024


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main()
{
	// Initialize Windows socket library
	WSADATA     wsaData;
	WSAStartup(0x0202, &wsaData);

	WCHAR szClassName[] = TEXT("MainWClass");
	WNDCLASSEX wndclass;
	// �����������ڵĲ������WNDCLASSEX�ṹ
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = NULL;
	wndclass.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;
	wndclass.hIconSm = NULL;
	::RegisterClassEx(&wndclass);
	// ����������
	HWND hWnd = ::CreateWindowEx(
		0,
		szClassName,
		TEXT(""),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		NULL,
		NULL);
	if (hWnd == NULL)
	{
		::MessageBox(NULL, TEXT("�������ڳ���"), TEXT("error"), MB_OK);
		return -1;
	}

	USHORT nPort = 5150;    // �˷����������Ķ˿ں�

	// ���������׽���
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(nPort);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	// ���׽��ֵ����ػ���
	if (::bind(sListen, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf(" Failed bind() \n");
		return -1;
	}

	// ���׽�����Ϊ����֪ͨ��Ϣ���͡�
	::WSAAsyncSelect(sListen, hWnd, WM_SOCKET, FD_ACCEPT | FD_CLOSE);

	// �������ģʽ
	::listen(sListen, 5);

	// ����Ϣ������ȡ����Ϣ
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		// ת��������Ϣ
		::TranslateMessage(&msg);
		// ����Ϣ���͵���Ӧ�Ĵ��ں���
		::DispatchMessage(&msg);
	}
	// ��GetMessage����0ʱ�������
	return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SOCKET:
	{
		// ȡ�����¼��������׽��־��
		SOCKET s = wParam;
		// �鿴�Ƿ����
		if (WSAGETSELECTERROR(lParam))
		{
			::closesocket(s);
			return 0;
		}
		// ���������¼�
		switch (WSAGETSELECTEVENT(lParam))
		{
		case FD_ACCEPT:        // �����е��׽��ּ�⵽�����ӽ���
		{
			SOCKET client = ::accept(s, NULL, NULL);
			::WSAAsyncSelect(client, hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_CLOSE);
		}
		break;
		case FD_WRITE:
		{
		}
		break;
		case FD_READ:
		{
			char szText[MAX_LEN] = { 0 };
			int nRecv = ::recv(s, szText, MAX_LEN, 0);
			if (nRecv == -1)
				::closesocket(s);
			else
			{
				szText[nRecv] = '\0';
				printf("�������ݣ�%s\n", szText);
			}
		}
		break;
		case FD_CLOSE:
		{
			::closesocket(s);
			printf("���ӹر� \n");
		}
		break;
		}
	}
	return 0;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}

	// �����ǲ��������Ϣ����ϵͳ��Ĭ�ϴ���
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}
*/




/*
// IOģ��֮�ص�(Overlapped)ģ�ͣ����ڡ�������̡�
#include "stdafx.h"
#include <WINSOCK2.H>
#include <stdio.h>
#include <queue>
#include <mutex>


#define PORT    5150
#define MSGSIZE 1024

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996

typedef struct
{
	WSAOVERLAPPED overlap;
	WSABUF        Buffer;
	char          szMessage[MSGSIZE];
	DWORD         NumberOfBytesRecvd;
	DWORD         Flags;
	SOCKET        sClient;
}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

DWORD WINAPI AcceptThread(LPVOID);
DWORD WINAPI WorkerThread(LPVOID);
void CALLBACK CompletionROUTINE(DWORD, DWORD, LPWSAOVERLAPPED, DWORD);

SOCKET				sListen;
std::queue<SOCKET>	g_queueClientSocket;
std::mutex			g_mutexClientSocket;

int main()
{
	WSADATA     wsaData;
	//SOCKET      sListen;
	SOCKADDR_IN local, client;
	DWORD       dwThreadId;
	int         iaddrSize = sizeof(SOCKADDR_IN);

	// Initialize Windows Socket library
	WSAStartup(0x0202, &wsaData);

	// Create listening socket
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Bind
	local.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	bind(sListen, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));

	// Listen
	listen(sListen, 3);

	// Create worker thread
	CreateThread(NULL, 0, AcceptThread, NULL, 0, &dwThreadId);
	CreateThread(NULL, 0, WorkerThread, NULL, 0, &dwThreadId);

	while (true)
	{
		Sleep(10000000);
	}
	
	return 0;
}

DWORD WINAPI AcceptThread(LPVOID lpParam)
{
	SOCKADDR_IN client;
	int         iaddrSize = sizeof(SOCKADDR_IN);
	while (TRUE)
	{
		// Accept a connection
		SOCKET sNewClientConnection = accept(sListen, (struct sockaddr *)&client, &iaddrSize);
		{
			std::lock_guard<std::mutex> lockClientSocket(g_mutexClientSocket);
			g_queueClientSocket.push(sNewClientConnection);
		}
		printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	}

	return 0;
}

DWORD WINAPI WorkerThread(LPVOID lpParam)
{
	LPPER_IO_OPERATION_DATA lpPerIOData = NULL;
	
	while (TRUE)
	{	
		BOOL bNewClientSocket = FALSE;
		SOCKET sNewClientConnection;
		{
			std::lock_guard<std::mutex> lockClientSocket(g_mutexClientSocket);
			if (g_queueClientSocket.size() > 0)
			{
				sNewClientConnection = g_queueClientSocket.front();
				bNewClientSocket = TRUE;
			}
		}
		
		if (bNewClientSocket)
		{
			// Launch an asynchronous operation for new arrived connection
			lpPerIOData = (LPPER_IO_OPERATION_DATA)HeapAlloc(
				GetProcessHeap(),
				HEAP_ZERO_MEMORY,
				sizeof(PER_IO_OPERATION_DATA));
			lpPerIOData->Buffer.len = MSGSIZE;
			lpPerIOData->Buffer.buf = lpPerIOData->szMessage;
			lpPerIOData->sClient = sNewClientConnection;

			WSARecv(lpPerIOData->sClient,
				&lpPerIOData->Buffer,
				1,
				&lpPerIOData->NumberOfBytesRecvd,
				&lpPerIOData->Flags,
				&lpPerIOData->overlap,
				CompletionROUTINE);
		}	

		SleepEx(1000, TRUE);//���������sleep,�����������������̵Ļص�,��һ������ʱ������ʵ���С
	}
	return 0;
}

void CALLBACK CompletionROUTINE(DWORD dwError,
	DWORD cbTransferred,
	LPWSAOVERLAPPED lpOverlapped,
	DWORD dwFlags)
{
	LPPER_IO_OPERATION_DATA lpPerIOData = (LPPER_IO_OPERATION_DATA)lpOverlapped;

	if (dwError != 0 || cbTransferred == 0)
	{
		// Connection was closed by client
		closesocket(lpPerIOData->sClient);
		HeapFree(GetProcessHeap(), 0, lpPerIOData);
	}
	else
	{
		lpPerIOData->szMessage[cbTransferred] = '\0';
		printf("�յ����ݣ�%s", lpPerIOData->szMessage);
		//send(lpPerIOData->sClient, lpPerIOData->szMessage, cbTransferred, 0);

		// Launch another asynchronous operation
		memset(&lpPerIOData->overlap, 0, sizeof(WSAOVERLAPPED));
		lpPerIOData->Buffer.len = MSGSIZE;
		lpPerIOData->Buffer.buf = lpPerIOData->szMessage;

		WSARecv(lpPerIOData->sClient,
			&lpPerIOData->Buffer,
			1,
			&lpPerIOData->NumberOfBytesRecvd,
			&lpPerIOData->Flags,
			&lpPerIOData->overlap,
			CompletionROUTINE);
	}
}
*/





/*
// IOģ��֮�ص�(Overlapped)ģ�ͣ������¼�֪ͨ
#include "stdafx.h"
#include <winsock2.h>
#include <stdio.h>
#define PORT		5150
#define MSGSIZE		1024
#pragma comment (lib, "Ws2_32.lib")
#pragma warning(disable:4996

BOOL WinSockInit()
{
	WSADATA data = { 0 };
	if (WSAStartup(MAKEWORD(2, 2), &data))
		return FALSE;
	if (LOBYTE(data.wVersion) != 2 || HIBYTE(data.wVersion) != 2){
		WSACleanup();
		return FALSE;
	}
	return TRUE;
}

typedef struct
{
	WSAOVERLAPPED overlap;
	WSABUF Buffer;
	char szMessage[MSGSIZE];
	DWORD NumberOfBytesRecvd;
	DWORD Flags;
}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

int g_iTotalConn = 0;
SOCKET g_CliSocketArr[MAXIMUM_WAIT_OBJECTS];
WSAEVENT g_CliEventArr[MAXIMUM_WAIT_OBJECTS];
LPPER_IO_OPERATION_DATA g_pPerIODataArr[MAXIMUM_WAIT_OBJECTS];


DWORD WINAPI WorkerThread(LPVOID);
void Cleanup(int);

int main()
{
	SOCKET sListen, sClient;
	SOCKADDR_IN local, client;
	DWORD dwThreadId;
	int iaddrSize = sizeof(SOCKADDR_IN);
	// ��ʼ������
	WinSockInit();
	// ��������socket
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// ��
	local.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	bind(sListen, (struct sockaddr *)&local, sizeof(SOCKADDR_IN));
	// ����
	listen(sListen, 3);
	// �����������߳�
	CreateThread(NULL, 0, WorkerThread, NULL, 0, &dwThreadId);
	while (TRUE)
	{
		// ��������
		sClient = accept(sListen, (struct sockaddr *)&client, &iaddrSize);
		printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
		g_CliSocketArr[g_iTotalConn] = sClient;

		// ����һ����io�������ݽṹ
		g_pPerIODataArr[g_iTotalConn] = (LPPER_IO_OPERATION_DATA)HeapAlloc(
			GetProcessHeap(),
			HEAP_ZERO_MEMORY,
			sizeof(PER_IO_OPERATION_DATA));
		//��ʼ����io�ṹ
		g_pPerIODataArr[g_iTotalConn]->Buffer.len = MSGSIZE;
		g_pPerIODataArr[g_iTotalConn]->Buffer.buf = g_pPerIODataArr[g_iTotalConn]->szMessage;
		g_CliEventArr[g_iTotalConn] = g_pPerIODataArr[g_iTotalConn]->overlap.hEvent = WSACreateEvent();
		// ��ʼһ���첽����
		WSARecv(
			g_CliSocketArr[g_iTotalConn],
			&g_pPerIODataArr[g_iTotalConn]->Buffer,
			1,
			&g_pPerIODataArr[g_iTotalConn]->NumberOfBytesRecvd,
			&g_pPerIODataArr[g_iTotalConn]->Flags, 
			&g_pPerIODataArr[g_iTotalConn]->overlap,
			NULL);
		g_iTotalConn++;
	}

	closesocket(sListen);
	WSACleanup();
	return 0;
}
DWORD WINAPI WorkerThread(LPVOID lpParam)
{
	int ret, index;
	DWORD cbTransferred;
	while (TRUE)
	{
		//�ж��Ƿ����ź�
		ret = WSAWaitForMultipleEvents(g_iTotalConn, g_CliEventArr, FALSE, 1000, FALSE);
		if (ret == WSA_WAIT_FAILED || ret == WSA_WAIT_TIMEOUT)
			continue;
		index = ret - WSA_WAIT_EVENT_0;
		//�ֶ�����Ϊ���ź�
		WSAResetEvent(g_CliEventArr[index]);
		//�жϸ��ص����õ����ǳɹ�������ʧ��
		WSAGetOverlappedResult(
			g_CliSocketArr[index],
			&g_pPerIODataArr[index]->overlap,
			&cbTransferred,
			TRUE,
			&g_pPerIODataArr[g_iTotalConn]->Flags);
		//������ʧ��
		if (cbTransferred == 0)
			Cleanup(index);//�رտͻ�������
		else
		{
			//�����ݱ��浽szMessage���			
			g_pPerIODataArr[index]->szMessage[cbTransferred] = '\0';
			printf("�յ����ݣ�%s \n", g_pPerIODataArr[index]->szMessage);
			//����ֱ�Ӿ�ת����ȥ��
			send(g_CliSocketArr[index], g_pPerIODataArr[index]->szMessage, cbTransferred, 0);
			// ������һ���첽����
			WSARecv(g_CliSocketArr[index],
				&g_pPerIODataArr[index]->Buffer,
				1,
				&g_pPerIODataArr[index]->NumberOfBytesRecvd,
				&g_pPerIODataArr[index]->Flags,
				&g_pPerIODataArr[index]->overlap,
				NULL);
		}
	}
	return 0;
}
void Cleanup(int index)
{
	closesocket(g_CliSocketArr[index]);
	WSACloseEvent(g_CliEventArr[index]);
	HeapFree(GetProcessHeap(), 0, g_pPerIODataArr[index]);
	if (index < g_iTotalConn - 1)
	{
		g_CliSocketArr[index] = g_CliSocketArr[g_iTotalConn - 1];
		g_CliEventArr[index] = g_CliEventArr[g_iTotalConn - 1];
		g_pPerIODataArr[index] = g_pPerIODataArr[g_iTotalConn - 1];
	}
	g_pPerIODataArr[--g_iTotalConn] = NULL;
}
*/



/*
//iocpģ��demo
#include "stdafx.h"
#include <iostream>
#include <winsock2.h>
#include <stdio.h>
#define DefaultPort		5150
#define DataBuffSize	8 * 1024
#pragma comment (lib, "Ws2_32.lib")
#pragma warning(disable:4996)

typedef struct
{
	OVERLAPPED overlapped;
	WSABUF databuff;
	CHAR buffer[DataBuffSize];
	DWORD bytesSend;
	DWORD bytesRecv;
}PER_IO_OPERATEION_DATA, *LPPER_IO_OPERATION_DATA;

typedef struct
{
	SOCKET socket;
}PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

using namespace std;

#pragma comment( lib, "Ws2_32.lib" )

DWORD WINAPI ServerWorkThread(LPVOID CompletionPortID);

void main()
{

	SOCKET acceptSocket;
	HANDLE completionPort;
	LPPER_HANDLE_DATA pHandleData;
	LPPER_IO_OPERATION_DATA pIoData;
	DWORD recvBytes;
	DWORD flags;

	WSADATA wsaData;
	DWORD ret;
	if (ret = WSAStartup(0x0202, &wsaData) != 0)
	{
		std::cout << "WSAStartup failed. Error:" << ret << std::endl;
		return;
	}

	completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
	if (completionPort == NULL)
	{
		std::cout << "CreateIoCompletionPort failed. Error:" << GetLastError() << std::endl;
		return;
	}

	SYSTEM_INFO mySysInfo;
	GetSystemInfo(&mySysInfo);

	// ���� 2 * CPU���� + 1 ���߳�
	DWORD threadID;
	for (DWORD i = 0; i < (mySysInfo.dwNumberOfProcessors * 2 + 1); ++i)
	{
		HANDLE threadHandle;
		threadHandle = CreateThread(NULL, 0, ServerWorkThread, completionPort, 0, &threadID);
		if (threadHandle == NULL)
		{
			std::cout << "CreateThread failed. Error:" << GetLastError() << std::endl;
			return;
		}

		CloseHandle(threadHandle);
	}

	// ����һ������socket
	SOCKET listenSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (listenSocket == INVALID_SOCKET)
	{
		std::cout << " WSASocket( listenSocket ) failed. Error:" << GetLastError() << std::endl;
		return;
	}

	SOCKADDR_IN internetAddr;
	internetAddr.sin_family = AF_INET;
	internetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	internetAddr.sin_port = htons(DefaultPort);

	// �󶨼����˿�
	if (bind(listenSocket, (PSOCKADDR)&internetAddr, sizeof(internetAddr)) == SOCKET_ERROR)
	{
		std::cout << "Bind failed. Error:" << GetLastError() << std::endl;
		return;
	}

	if (listen(listenSocket, 5) == SOCKET_ERROR)
	{
		std::cout << "listen failed. Error:" << GetLastError() << std::endl;
		return;
	}

	// ��ʼ��ѭ������������
	while (1)
	{
		acceptSocket = WSAAccept(listenSocket, NULL, NULL, NULL, 0);
		if (acceptSocket == SOCKET_ERROR)
		{
			std::cout << "WSAAccept failed. Error:" << GetLastError() << std::endl;
			return;
		}

		pHandleData = (LPPER_HANDLE_DATA)GlobalAlloc(GPTR, sizeof(PER_HANDLE_DATA));
		if (pHandleData == NULL)
		{
			std::cout << "GlobalAlloc( HandleData ) failed. Error:" << GetLastError() << std::endl;
			return;
		}

		pHandleData->socket = acceptSocket;
		if (CreateIoCompletionPort((HANDLE)acceptSocket, completionPort, (ULONG_PTR)pHandleData, 0) == NULL)
		{
			std::cout << "CreateIoCompletionPort failed. Error:" << GetLastError() << std::endl;
			return;
		}

		pIoData = (LPPER_IO_OPERATION_DATA)GlobalAlloc(GPTR, sizeof(PER_IO_OPERATEION_DATA));
		if (pIoData == NULL)
		{
			std::cout << "GlobalAlloc( IoData ) failed. Error:" << GetLastError() << std::endl;
			return;
		}

		ZeroMemory(&(pIoData->overlapped), sizeof(pIoData->overlapped));
		pIoData->bytesSend = 0;
		pIoData->bytesRecv = 0;
		pIoData->databuff.len = DataBuffSize;
		pIoData->databuff.buf = pIoData->buffer;

		flags = 0;
		if (WSARecv(acceptSocket, &(pIoData->databuff), 1, &recvBytes, &flags, &(pIoData->overlapped), NULL) == SOCKET_ERROR)
		{
			if (WSAGetLastError() != ERROR_IO_PENDING)
			{
				std::cout << "WSARecv() failed. Error:" << GetLastError() << std::endl;
				return;
			}
			else
			{
				//std::cout << "WSARecv() io pending" << std::endl;
				//return;
			}
		}
	}
}

DWORD WINAPI ServerWorkThread(LPVOID CompletionPortID)
{
	HANDLE complationPort = (HANDLE)CompletionPortID;
	DWORD bytesTransferred;
	LPPER_HANDLE_DATA pHandleData = NULL;
	LPPER_IO_OPERATION_DATA pIoData = NULL;
	DWORD sendBytes = 0;
	DWORD recvBytes = 0;
	DWORD flags;

	while (1)
	{
		if (GetQueuedCompletionStatus(complationPort, &bytesTransferred, (PULONG_PTR)&pHandleData, (LPOVERLAPPED *)&pIoData, INFINITE) == 0)
		{
			std::cout << "GetQueuedCompletionStatus failed. Error:" << GetLastError() << std::endl;
			return 0;
		}

		// ��������Ƿ��Ѿ���������
		if (bytesTransferred == 0)
		{
			std::cout << " Start closing socket..." << std::endl;
			if (CloseHandle((HANDLE)pHandleData->socket) == SOCKET_ERROR)
			{
				std::cout << "Close socket failed. Error:" << GetLastError() << std::endl;
				return 0;
			}

			GlobalFree(pHandleData);
			GlobalFree(pIoData);
			continue;
		}

		// ���ܵ����Ƿ�������
		if (pIoData->bytesRecv == 0)
		{
			pIoData->bytesRecv = bytesTransferred;
			pIoData->bytesSend = 0;
		}
		else
		{
			pIoData->bytesSend += bytesTransferred;
		}

		// ����û�з��꣬��������
		if (pIoData->bytesRecv > pIoData->bytesSend)
		{
			ZeroMemory(&(pIoData->overlapped), sizeof(OVERLAPPED));
			pIoData->databuff.buf = pIoData->buffer + pIoData->bytesSend;
			pIoData->databuff.len = pIoData->bytesRecv - pIoData->bytesSend;

			// �������ݳ�ȥ
			if (WSASend(pHandleData->socket, &(pIoData->databuff), 1, &sendBytes, 0, &(pIoData->overlapped), NULL) == SOCKET_ERROR)
			{
				if (WSAGetLastError() != ERROR_IO_PENDING)
				{
					std::cout << "WSASend() failed. Error:" << GetLastError() << std::endl;
					return 0;
				}
				else
				{
					std::cout << "WSASend() failed. io pending. Error:" << GetLastError() << std::endl;
					return 0;
				}
			}

			std::cout << "Send " << pIoData->buffer << std::endl;
		}
		else
		{
			pIoData->bytesRecv = 0;
			flags = 0;

			ZeroMemory(&(pIoData->overlapped), sizeof(OVERLAPPED));
			pIoData->databuff.len = DataBuffSize;
			pIoData->databuff.buf = pIoData->buffer;

			if (WSARecv(pHandleData->socket, &(pIoData->databuff), 1, &recvBytes, &flags, &(pIoData->overlapped), NULL) == SOCKET_ERROR)
			{
				if (WSAGetLastError() != ERROR_IO_PENDING)
				{
					std::cout << "WSARecv() failed. Error:" << GetLastError() << std::endl;
					return 0;
				}
				else
				{
					std::cout << "WSARecv() io pending" << std::endl;
					return 0;
				}
			}
		}
	}
}
*/


/*
//������һ������Epollʵ��Reactorģʽ�ļ�ʵ��(���߳�)��
//�������ʵ���˼򵥵�Echo������������ʵ�־��ǣ�
//��ʼ������socket������ӵ�Epoll�С�
//ѭ������Epoll��epoll_wait�������ȴ��¼���
//����Ǽ���socket���¼����ʹ����µ��������󣬰�����socket��ӵ�Epoll�С�
//���������socket���¼����ʹ���ͻ������󲢻�����Ӧ������ͻ��˶Ͽ����ӣ��Ͱ�����socket��Epoll��ɾ�������ر�����socket��

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_NUM 10
#define MAX_EVENTS_NUM 10

int init_listen_socket(int port) {
	int listen_fd;
	struct sockaddr_in server_addr;

	if ((listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) == -1) {
		std::cout << "create socket fd error!" << std::endl;
		return -1;
	}

	int flag = 1;
	if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == -1) {
		std::cout << "setsockopt error!" << std::endl;
		return -1;
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
		std::cout << "bind error!" << std::endl;
		return -1;
	}

	if (listen(listen_fd, MAX_CLIENT_NUM) == -1) {
		std::cout << "listen error!" << std::endl;
		return -1;
	}

	return listen_fd;
}

void handle_new_connection(int epoll_fd, int listen_fd) {
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int conn_fd;

	while ((conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len)) != -1) {
		std::cout << "new connection from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << std::endl;

		if (fcntl(conn_fd, F_SETFL, O_NONBLOCK) == -1) {
			std::cout << "fcntl error!" << std::endl;
			close(conn_fd);
			continue;
		}

		struct epoll_event ev;
		ev.data.fd = conn_fd;
		ev.events = EPOLLIN | EPOLLET;
		if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &ev) == -1) {
			std::cout << "epoll_ctl error!" << std::endl;
			close(conn_fd);
			continue;
		}
	}

	if (errno != EAGAIN && errno != EWOULDBLOCK) {
		std::cout << "accept error!" << std::endl;
	}
}

void handle_client_request(int epoll_fd, int fd) {
	char buf[1024];
	int recv_len;

	while ((recv_len = recv(fd, buf, sizeof(buf), 0)) > 0) {
		std::cout << "recv message from fd " << fd << ": " << std::string(buf, recv_len) << std::endl;
		send(fd, buf, recv_len, 0);
	}

	if (recv_len == 0) {
		std::cout << "close connection from fd " << fd << std::endl;
		if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL) == -1) {
			std::cout << "epoll_ctl error!" << std::endl;
		}
		close(fd);
	}

	if (recv_len == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
		std::cout << "recv error! fd " << fd << std::endl;
		if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL) == -1) {
			std::cout << "epoll_ctl error!" << std::endl;
		}
		close(fd);
	}
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./server <port>" << std::endl;
		return 0;
	}

	int listen_fd = init_listen_socket(atoi(argv[1]));
	if (listen_fd == -1) {
		std::cout << "init_listen_socket error!" << std::endl;
		return 0;
	}

	int epoll_fd = epoll_create(1);
	if (epoll_fd == -1) {
		std::cout << "epoll_create error!" << std::endl;
		return 0;
	}

	struct epoll_event ev;
	ev.data.fd = listen_fd;
	ev.events = EPOLLIN | EPOLLET;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev) == -1) {
		std::cout << "epoll_ctl error!" << std::endl;
		return 0;
	}

	struct epoll_event events[MAX_EVENTS_NUM];
	while (true) {
		int ready_num = epoll_wait(epoll_fd, events, MAX_EVENTS_NUM, -1);
		if (ready_num == -1) {
			std::cout << "epoll_wait error!" << std::endl;
			return 0;
		}

		for (int i = 0; i < ready_num; ++i) {
			if (events[i].data.fd == listen_fd) {
				handle_new_connection(epoll_fd, listen_fd);
			}
			else {
				handle_client_request(epoll_fd, events[i].data.fd);
			}
		}
	}

	close(listen_fd);
	close(epoll_fd);

	return 0;
}
*/



/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include "thread_pool.h"
#include "event_handler.h"

using namespace std;

void AcceptHandler(int fd) {
	cout << "AcceptHandler" << endl;

	while (true) {
		struct sockaddr_in client_addr;
		socklen_t addr_len = sizeof(client_addr);

		int conn_fd = accept4(fd, (struct sockaddr *)&client_addr, &addr_len, SOCK_NONBLOCK);
		if (conn_fd == -1) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				break;
			}
			else {
				perror("accept4");
				break;
			}
		}

		cout << "New connection: " << conn_fd << endl;

		// �����Ӽ����¼�����������ע EPOLLIN �� EPOLLET
		EventHandler::GetInstance().AddDescriptor(conn_fd, EPOLLIN | EPOLLET, ReadHandler);
	}
}

void ReadHandler(int fd) {
	cout << "ReadHandler" << endl;

	// ���ȴ�socket�ж�ȡ��������
	char buffer[1024];
	int n = read(fd, buffer, 1024);
	if (n == -1) {
		if (errno != EAGAIN && errno != EWOULDBLOCK) {
			perror("read");
			CloseHandler(fd);
		}
	}
	else if (n == 0) {
		CloseHandler(fd);
	}
	else {
		// ��ȡ�����ݺ󣬽�������̷�װ��һ�� Task �У���ӵ��̳߳���ִ��
		ThreadPool::GetInstance().AddTask([=]() {
			char *buf = new char[n];
			for (int i = 0; i < n; ++i) {
				buf[i] = toupper(buffer[i]);
			}
			write(fd, buf, n);
			delete[] buf;
		});
	}
}

void CloseHandler(int fd) {
	cout << "CloseHandler" << endl;

	// ���¼����������Ƴ��ѹر�����
	EventHandler::GetInstance().RemoveDescriptor(fd);
	// �ر�����
	close(fd);
}

int main() {
	int listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (listen_fd == -1) {
		perror("socket");
		return -1;
	}

	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(8080);

	int opt = 1;
	if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt)) == -1) {
		perror("setsockopt");
	}

	if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
		perror("bind");
		close(listen_fd);
		return -1;
	}

	if (listen(listen_fd, SOMAXCONN) == -1) {
		perror("listen");
		close(listen_fd);
		return -1;
	}

	// �����̳߳�
	ThreadPool::GetInstance().InitThreadPool(8);

	// �����첽�¼�������
	EventHandler::GetInstance().CreateEpollFd();

	// ��Server Socket��ӵ��¼��������У������ûص�����ΪAcceptHandler
	EventHandler::GetInstance().AddDescriptor(listen_fd, EPOLLIN | EPOLLET, AcceptHandler);

	// �����¼�ѭ��
	EventHandler::GetInstance().EventLoop();

	close(listen_fd);

	return 0;
}
*/

