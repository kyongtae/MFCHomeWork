// CChildDig.cpp: 구현 파일
//

#include "pch.h"
#include "MFCHomeWork.h"
#include "afxdialogex.h"
#include "CChildDig.h"


// CChildDig 대화 상자

IMPLEMENT_DYNAMIC(CChildDig, CDialogEx)

CChildDig::CChildDig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHILDDIALOG, pParent)
{

}

CChildDig::~CChildDig()
{
}

void CChildDig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ChildLIST, m_ChildText);
}


BEGIN_MESSAGE_MAP(CChildDig, CDialogEx)
END_MESSAGE_MAP()


// CChildDig 메시지 처리기
BOOL CChildDig::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_ChildText.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_ChildText.InsertColumn(0, _T("시도"), LVCFMT_CENTER, 30);
	m_ChildText.InsertColumn(1, _T("시군구"), LVCFMT_CENTER, 50);
	m_ChildText.InsertColumn(2, _T("터널안"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(3, _T("교량위"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(4, _T("고가도로위"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(5, _T("지하차도(도로)내"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(6, _T("기타단일로"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(7, _T("교차로내"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(8, _T("교차로횡단보도내"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(9, _T("교차로부근"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(10, _T("철길건널목"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(11, _T("기타"), LVCFMT_CENTER, 60);
	m_ChildText.InsertColumn(12, _T("불명"), LVCFMT_CENTER, 60);



	for (int j = 0; j < ChildCopylist.size() / 13; j++)
	{
		//CString 변환
		int cnt = m_ChildText.GetItemCount();
		CString str;
		str.Format(_T(" % d"), cnt);
		m_ChildText.InsertItem(cnt, str);

		for (int i = 0; i < 13; i++)
		{
			m_ChildText.SetItem(cnt, i, LVIF_TEXT, this->GetCityData(i + (13 * j)), NULL, NULL, NULL, NULL);
		}
		cnt++;
	}


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}



void CChildDig::SetAccidentData(CString CityData)
{
	// TODO: 여기에 구현 코드 추가.
	
}

void CChildDig:: SetCityData(CString _data)
{
	ChildCopylist.push_back(_data);
}


CString CChildDig::GetCityData(int idx)
{
	return ChildCopylist.at(idx);
}

void CChildDig::SetVectorCityData(vector <CString> &plist)
{
	plist = ChildCopylist;
}