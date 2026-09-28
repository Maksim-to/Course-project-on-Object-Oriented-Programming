
// TechShop.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CTechShopApp:
// Сведения о реализации этого класса: TechShop.cpp
//

class CTechShopApp : public CWinApp
{
public:
	CTechShopApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CTechShopApp theApp;
