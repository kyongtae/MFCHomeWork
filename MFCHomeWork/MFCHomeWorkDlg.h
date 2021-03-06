
// MFCHomeWorkDlg.h: 헤더 파일
//

#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "ListController.h"
#include "CChildDig.h"

// CMFCHomeWorkDlg 대화 상자
class CMFCHomeWorkDlg : public CDialogEx
{
// 생성입니다.
	
public:
	CMFCHomeWorkDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCHOMEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	CListCtrl m_SumList;
	CString m_SearchingMessage;
	ListController* plist = new ListController;
	
	
	 
	void SetEditBox();
	afx_msg void OnBnClickedListupbutton();
	afx_msg void OnBnClickedSearchingbutton();
	afx_msg void OnEnChangeSearchingedit();
	
};
