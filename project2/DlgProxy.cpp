
// DlgProxy.cpp : 实现文件
//

#include "stdafx.h"
#include "project2.h"
#include "DlgProxy.h"
#include "project2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cproject2DlgAutoProxy

IMPLEMENT_DYNCREATE(Cproject2DlgAutoProxy, CCmdTarget)

Cproject2DlgAutoProxy::Cproject2DlgAutoProxy()
{
	EnableAutomation();
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(Cproject2Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(Cproject2Dlg)))
		{
			m_pDialog = reinterpret_cast<Cproject2Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

Cproject2DlgAutoProxy::~Cproject2DlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void Cproject2DlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(Cproject2DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Cproject2DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_Iproject2 的支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {138BD86D-7208-4D55-92AF-7D388F8DB8CC}
static const IID IID_Iproject2 =
{ 0x138BD86D, 0x7208, 0x4D55, { 0x92, 0xAF, 0x7D, 0x38, 0x8F, 0x8D, 0xB8, 0xCC } };

BEGIN_INTERFACE_MAP(Cproject2DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(Cproject2DlgAutoProxy, IID_Iproject2, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {4E19AEBB-D321-4A0B-B5B7-B9BE7E723ED4}
IMPLEMENT_OLECREATE2(Cproject2DlgAutoProxy, "project2.Application", 0x4e19aebb, 0xd321, 0x4a0b, 0xb5, 0xb7, 0xb9, 0xbe, 0x7e, 0x72, 0x3e, 0xd4)


// Cproject2DlgAutoProxy 消息处理程序
