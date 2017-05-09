#if !defined(AFX_CIRCLELABELS_H__C817297B_7BFC_4A9B_9EE4_D681B67E82D9__INCLUDED_)
#define AFX_CIRCLELABELS_H__C817297B_7BFC_4A9B_9EE4_D681B67E82D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CChartFont;

/////////////////////////////////////////////////////////////////////////////
// CCircleLabels wrapper class

class CCircleLabels : public COleDispatchDriver
{
public:
	CCircleLabels() {}		// Calls COleDispatchDriver default constructor
	CCircleLabels(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCircleLabels(const CCircleLabels& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CChartFont GetFont();
	BOOL GetRotated();
	void SetRotated(BOOL bNewValue);
	CString GetDegreeSymbol();
	void SetDegreeSymbol(LPCTSTR lpszNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLELABELS_H__C817297B_7BFC_4A9B_9EE4_D681B67E82D9__INCLUDED_)