#pragma once
#include "afxdialogex.h"
#include <vector>
using namespace std;

// CChildDig 대화 상자

class CChildDig : public CDialogEx
{
	DECLARE_DYNAMIC(CChildDig)
	vector <CString> ChildCopylist;

public:
	CChildDig(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CChildDig();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHILDDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL CChildDig::OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ChildText;
	void SetAccidentData(CString CityData);

	void SetCityData(CString _data);
	CString GetCityData(int idx);

	void SetVectorCityData(vector <CString> &plist);
};
