#include "stdafx.h"
#include "AppVersion.h"

#pragma comment(lib, "Version.lib")



void GetAppVersion(LPTSTR lpVersion, int nSize) {
    memset(lpVersion, 0, nSize);

    TCHAR szFullPath[MAX_PATH];
    DWORD dwVerInfoSize = 0;
    DWORD dwVerHnd;
    VS_FIXEDFILEINFO * pFileInfo;

    GetModuleFileName(NULL, szFullPath, sizeof(szFullPath));
    dwVerInfoSize = GetFileVersionInfoSize(szFullPath, &dwVerHnd);
    if (dwVerInfoSize) {
        // If we were able to get the information, process it:
        HANDLE  hMem;
        LPVOID  lpvMem;
        unsigned int uInfoSize = 0;

        hMem = GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
        lpvMem = GlobalLock(hMem);
        GetFileVersionInfo(szFullPath, dwVerHnd, dwVerInfoSize, lpvMem);

        ::VerQueryValue(lpvMem, (LPTSTR)("\\"), (void**)&pFileInfo, &uInfoSize);

        int ret = GetLastError();
        WORD m_nProdVersion[4];

        // Product version from the FILEVERSION of the version info resource 
        m_nProdVersion[0] = HIWORD(pFileInfo->dwProductVersionMS);
        m_nProdVersion[1] = LOWORD(pFileInfo->dwProductVersionMS);
        m_nProdVersion[2] = HIWORD(pFileInfo->dwProductVersionLS);
        m_nProdVersion[3] = LOWORD(pFileInfo->dwProductVersionLS);

        GlobalUnlock(hMem);
        GlobalFree(hMem);

        WIN32_FIND_DATA sFileStruct;
        HANDLE hf;
        hf = FindFirstFile(szFullPath, &sFileStruct);
        sFileStruct.ftCreationTime;//����ʱ��     
        sFileStruct.ftLastAccessTime;//����ʱ��   
        FILETIME ft = sFileStruct.ftLastWriteTime;//�޸�ʱ��     
        CTime time(ft);//�Ȱ�FILETIME���͵�����ת��ΪCTime����

        _stprintf(lpVersion, _T("v%d.%d.%d b%02d%02d%02d"), m_nProdVersion[0], m_nProdVersion[1], m_nProdVersion[2], time.GetYear(), time.GetMonth(), time.GetDay());
    }
}