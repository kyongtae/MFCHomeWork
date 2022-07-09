
// MFCHomeWorkDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCHomeWork.h"
#include "MFCHomeWorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHomeWorkDlg 대화 상자



CMFCHomeWorkDlg::CMFCHomeWorkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCHOMEWORK_DIALOG, pParent)
	, m_SearchingMessage(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCHomeWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MotherLIST, m_List);
	DDX_Control(pDX, IDC_SUMLIST, m_SumList);

	DDX_Text(pDX, IDC_SEARCHINGEDIT, m_SearchingMessage);
	
}

BEGIN_MESSAGE_MAP(CMFCHomeWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LISTUPBUTTON, &CMFCHomeWorkDlg::OnBnClickedListupbutton)
	ON_BN_CLICKED(IDC_SEARCHINGBUTTON, &CMFCHomeWorkDlg::OnBnClickedSearchingbutton)
	ON_EN_CHANGE(IDC_SEARCHINGEDIT, &CMFCHomeWorkDlg::OnEnChangeSearchingedit)
END_MESSAGE_MAP()


// CMFCHomeWorkDlg 메시지 처리기

BOOL CMFCHomeWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_List.InsertColumn(0, _T("시도"), LVCFMT_CENTER, 50);
	m_List.InsertColumn(1, _T("시군구"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(2, _T("터널안"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(3, _T("교량위"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(4, _T("고가도로위"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(5, _T("지하차도(도로)내"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(6, _T("기타단일로"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(7, _T("교차로내"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(8, _T("교차로횡단보도내"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(9, _T("교차로부근"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(10, _T("철길건널목"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(11, _T("기타"), LVCFMT_CENTER, 60);
	m_List.InsertColumn(12, _T("불명"), LVCFMT_CENTER, 60);

	m_List.InsertItem(0, NULL);
	m_List.SetItem(0, 1, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 2, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 3, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 4, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 5, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 6, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 7, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 8, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 9, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 10, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 11, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);
	m_List.SetItem(0, 12, LVIF_TEXT, NULL, NULL, NULL, NULL, NULL);



	m_SumList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_SumList.InsertColumn(0, _T("시도/시군구"), LVCFMT_CENTER, 80);
	m_SumList.InsertColumn(1, _T("터널안"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(2, _T("교량위"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(3, _T("고가도로위"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(4, _T("지하차도(도로)내"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(5, _T("기타단일로"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(6, _T("교차로내"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(7, _T("교차로횡단보도내"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(8, _T("교차로부근"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(9, _T("철길건널목"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(10, _T("기타"), LVCFMT_CENTER, 60);
	m_SumList.InsertColumn(11, _T("불명"), LVCFMT_CENTER, 60);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCHomeWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCHomeWorkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCHomeWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCHomeWorkDlg::OnBnClickedListupbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//자료 가져오기=================================
	UpdateData(true);
	
	plist->DelCityData();
	m_List.DeleteAllItems();

	ifstream data("ANSIData.csv");
	string line;
	while (std::getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		CString city;

		while (std::getline(lineStream, cell, ','))
		{
			if (cell == "-")
			{
				cell = "0";
			}
			CString city(cell.c_str());
			plist->AddCityData(city);
		}
	}
	
	//디스플레이

	for (int j = 0; j < plist->SizeofVector()/13; j++)
	{
		//CString 변환
		int cnt = m_List.GetItemCount();
		CString str;
		str.Format(_T(" % d"), cnt);
		m_List.InsertItem(cnt, str);

		for (int i = 0; i < 13; i++)
		{
			m_List.SetItem(cnt, i, LVIF_TEXT, plist->GetCityData(i + (13 * j)), NULL, NULL, NULL, NULL);
		}
		cnt++;
	}
	UpdateData(false);
}


void CMFCHomeWorkDlg::OnBnClickedSearchingbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CChildDig* child =new CChildDig;
	
		//시 검색 전달
		UpdateData(true);
		for (int i = 0; i < plist->SizeofVector(); i++)
		{
			if (plist->GetCityData(i) == m_SearchingMessage && (i % 13 == 0))
			{
				for (int j = 0; j < 13; j++)
				{
					child->SetCityData(plist->GetCityData(i));
					i++;
				}
			}	

			//군구 검색 전달
			if (plist->GetCityData(i) == m_SearchingMessage && (i % 13 == 1))
			{
				for (int j = 0; j < 13; j++)
				{
					child->SetCityData(plist->GetCityData(i - 1));
					i++;
				}
			}
		}
	
		
		child->DoModal();
		//CString 변환
		int cnt = m_SumList.GetItemCount();
		CString str;
		str.Format(_T(" % d"), cnt);
		m_SumList.InsertItem(cnt, str);

		for (int i = 0; i < 12; i++)
		{
			if (i==0) 
			{
				m_SumList.SetItem(cnt, i, LVIF_TEXT, m_SearchingMessage, NULL, NULL, NULL, NULL);
			}
			else
			{
				m_SumList.SetItem(cnt, i, LVIF_TEXT, child->SumColum(i + 1), NULL, NULL, NULL, NULL);

			}
		}


		
		UpdateData(false);
		
}


void CMFCHomeWorkDlg::OnEnChangeSearchingedit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCHomeWorkDlg::SetEditBox()
{
	// TODO: 여기에 구현 코드 추가.
	

}
