
// TechShopDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "TechShop.h"
#include "TechShopDlg.h"
#include "afxdialogex.h"
#include "DLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CTechShopDlg



CTechShopDlg::CTechShopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TECHSHOP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTechShopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTechShopDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTechShopDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTechShopDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTechShopDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTechShopDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTechShopDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTechShopDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CTechShopDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// Обработчики сообщений CTechShopDlg

BOOL CTechShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CTechShopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CTechShopDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CTechShopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTechShopDlg::OnBnClickedButton1()
{
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	idc->SetWindowTextW(CString(ShowAll().c_str()));
}


void CTechShopDlg::OnBnClickedButton2()
{
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	idc->SetWindowTextW(CString(CheckMemory().c_str()));
}


void CTechShopDlg::OnBnClickedButton3()
{
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	idc->SetWindowTextW(L"В базе данных имеется " + CString(GetCount().c_str()) + L" разных видов товаров.");
}


void CTechShopDlg::OnBnClickedButton4()
{
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	Sort();
	idc->SetWindowTextW(CString(ShowAll().c_str()));
}


void CTechShopDlg::OnBnClickedButton5()
{
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	Reverse();
	idc->SetWindowTextW(CString(ShowAll().c_str()));
}


void CTechShopDlg::OnBnClickedButton6()
{
	CWnd* id1 = GetDlgItem(IDC_EDIT2);
	CWnd* id2 = GetDlgItem(IDC_EDIT3);
	CString a, b;
	id1->GetWindowTextW(a);
	id2->GetWindowTextW(b);
	string A = CStringA(a), B = CStringA(b);
	if (A != "" && B != "") {
		Swap(stoi(A.c_str()), stoi(B.c_str()));
		CWnd* idc = GetDlgItem(IDC_EDIT1);
		idc->SetWindowTextW(CString(ShowAll().c_str()));
	}
}


void CTechShopDlg::OnBnClickedButton8()
{
	CWnd* id1 = GetDlgItem(IDC_EDIT4);
	CWnd* id2 = GetDlgItem(IDC_EDIT5);
	CWnd* id3 = GetDlgItem(IDC_EDIT6);
	CWnd* id4 = GetDlgItem(IDC_EDIT7);
	CWnd* idc = GetDlgItem(IDC_EDIT1);
	CString A, B, C, D;
	id1->GetWindowTextW(A);
	id2->GetWindowTextW(B);
	id3->GetWindowTextW(C);
	id3->GetWindowTextW(D);
	string a = CStringA(A), b = CStringA(B), c = CStringA(C), d = CStringA(D);
	if (D != "") {
		Add(a, stod(b.c_str()), stoi(c.c_str()), d);
	}
	else {
		Add(a, stod(b.c_str()), stoi(c.c_str()));
	}
	idc->SetWindowTextW(L"В базу данных добавлен " + A);
}
