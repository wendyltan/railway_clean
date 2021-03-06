#if !defined(AFX_ROTATETOOL_H__6D956E42_568B_42BA_A020_C283701B44C8__INCLUDED_)
#define AFX_ROTATETOOL_H__6D956E42_568B_42BA_A020_C283701B44C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CRotateTool wrapper class

class CRotateTool : public COleDispatchDriver
{
public:
	CRotateTool() {}		// Calls COleDispatchDriver default constructor
	CRotateTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRotateTool(const CRotateTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL GetActive();
	void SetActive(BOOL bNewValue);
	long GetButton();
	void SetButton(long nNewValue);
	CString Description();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATETOOL_H__6D956E42_568B_42BA_A020_C283701B44C8__INCLUDED_)
