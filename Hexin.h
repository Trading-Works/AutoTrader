/*
	��Ŀ�����õ��ĺ�����
	���ڶ�ͬ��˳�µ���������������
	���ʹ�õ�ͬ��˳�汾��ͬ��˳ͬһ���µ��ͻ��� (5,18,92,119)

*/

#pragma once

#include "stdafx.h"
#include "struct_.h"

class CHexin
{
public:

	CHexin();
	~CHexin();

public:	

	static HWND FindWindowChildEx(HWND hwndParent, HWND hwndChild, LPCTSTR lpszClass, LPCTSTR lpszWindow, int count);
	static void SendVirtualKey(HWND hwnd, SHORT vk);

public:
	
	bool GetTradeBalance();	
	bool GetAllHwnd();

	HWND GetHexinHwnd();	
	HWND GetBuyStockHwnd();
	HWND GetSellStockHwnd();	
	HWND GetToolBarHolderHwnd();
	HWND GetToolBarBoxHwnd();
	HWND GetAfxMDIFrame42sHwnd();
	HWND GetToolBarMarketHwnd();

	bool KeepHexinActivate();
	TradeBalance& GetTradeBalance_();

	//ͬ��˳Ԥ������
	CString GetStockCodeBuy();
	CString GetStockNameBuy();
	CString GetStockCodeSell();
	CString GetStockNameSell();

	int GetBidAmount();
	int GetAskAmount();
	int GetCanBidAmount();
	int GetCanAskAmount();
	double GetHighLimit();
	double GetLowLimit();
	
	int HexinWarnBuy(int amount);
	int HexinWarnSell(int amount);

	//�����µ�����
	bool FlashBuyStock(CString strStock,CString strPrice,CString strAmount);
	bool FlashSellStock(CString strStock, CString strPrice, CString strAmount);
	bool WaitForDone(HWND hWndCtrl, enum WaitForClass nClass, char *szValue, int nInterval, int nTimeout);

private:

	TradeBalance m_balance;
	HWND hHexin = NULL;
	HWND hAfxMDIFrame42s = NULL;
	HWND hBuyStock = NULL;//���Ʊ����
	HWND hSellStock = NULL;//����Ʊ����
	HWND hToolBarBox = NULL;
	HWND hToolBarMarket = NULL;//�˵����г���
	HWND hToolBarHolder = NULL;//�˵����ɶ��ʻ���
};

