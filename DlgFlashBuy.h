#pragma once
#include "afxwin.h"
#include "ButtonEx.h"

// CDlgFlashBuy �Ի���

class CDlgFlashBuy : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFlashBuy)

public:
	CDlgFlashBuy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFlashBuy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_QUCIKINS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	CStatic m_labCode;
	CButtonEx m_btnBuy;
	CButton m_chk1_1;
	CButton m_chk1_2;
	CButton m_chk1_3;
	CButton m_chk1_4;

	CFont m_font_1;
	CFont m_font_2;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedLabCode();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedChk1();
	afx_msg void OnBnClickedChk2();
	afx_msg void OnBnClickedChk3();
	afx_msg void OnBnClickedChk4();
	afx_msg void OnBnClickedBtnBuy();

	int m_amount = 0;
	CString m_code;
	//�ص�����
	typedef void(*CallBack)(CString code, int amount);
	CallBack m_callback;
	void SetCallBack(CallBack callback);

	HANDLE hThread;
	DWORD threadID;
	static void ThreadCapture(LPVOID lp);


	//ͨ�����ھ������ȡ����Ļ�ַ
	CString GetCodeFromAddr();//ͨ���ڴ��ַ��ȡ��Ʊ����
	DWORD GetBaseAddr(HWND hwnd);
	DWORD64 m_CodeAddr = NULL;
	HANDLE m_dzhHandle = NULL;//���ǻ۾��
	static BOOL CALLBACK MyEnumerateLoadedModulesProc64(PTSTR ModuleName,
														DWORD64 ModuleBase,
														ULONG ModuleSize,
														PVOID UserContext);
	//��ȡ���ǻ۴��ھ��
	HWND GetDZHHwnd(HWND* hwnd);
	static BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam);

};
