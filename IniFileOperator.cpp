// IniFile.cpp: implementation of the CIniReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "Readini.h"
#include "IniFileOperator.h"
#include <afxcoll.h>

#define BUFFER_BYTE	512
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



// Used to retrieve a value give the section and key
CString CIniReader::getKeyValue(CString strKey,CString strSection)
{
	CString strResult;

	// Get the info from the .ini file	
	m_lRetValue = GetPrivateProfileString((LPCTSTR)strSection,(LPCTSTR)strKey,
		_T(""),strResult.GetBuffer(BUFFER_BYTE), BUFFER_BYTE, (LPCTSTR)m_strFileName);	
	return strResult;
}

// Used to add or set a key value pair to a section
BOOL CIniReader::setKeyValue(CString strValue, CString strKey, CString strSection)
{
	m_lRetValue = WritePrivateProfileString (strSection, strKey, 
                             strValue, m_strFileName);
	if(!m_lRetValue)
		DWORD dwError = GetLastError();
	if(m_lRetValue)
		return TRUE;
	
	return FALSE;

}

BOOL CIniReader::setKeyValue(UINT iKeyValue, CString strKey, CString strSection)
{
	TCHAR strKeyValue[20];
	_stprintf_s(strKeyValue, 20, _T("%d"), iKeyValue);
	BOOL bRet = setKeyValue(strKeyValue, strKey, strSection);
	if(bRet)
		return TRUE;
	return FALSE;
}

BOOL CIniReader::setKeyValue(double fKeyValue, CString strKey, CString strSection)
{
	TCHAR strKeyValue[20];
	_stprintf_s(strKeyValue, 20, _T("%f"), fKeyValue);
	long bRet = setKeyValue(strKeyValue, strKey, strSection);
	if(bRet)
		return TRUE;
	return FALSE;
}

// Used to find out if a given section exists
BOOL CIniReader::sectionExists(CString strSection)
{	
	CString csAux;
	// Get the info from the .ini file	
	m_lRetValue = GetPrivateProfileString((LPCTSTR)strSection,NULL,
		_T(""),csAux.GetBuffer(BUFFER_BYTE), BUFFER_BYTE, (LPCTSTR)m_strFileName);
	// Return if we could retrieve any info from that section
	return (m_lRetValue > 0);
}

// Used to retrieve all of the  section names in the ini file
CStringList* CIniReader::getSectionNames()  //returns collection of section names
{
	/*char ac_Result[2000];*/
	CString strReturnBuffer;
	m_sectionList->RemoveAll();
	
	TCHAR tcaResult[BUFFER_BYTE];
	m_lRetValue = GetPrivateProfileSectionNames(tcaResult,BUFFER_BYTE,(LPCTSTR)m_strFileName);


	CString strSectionName;
	for(int i=0; i<m_lRetValue; i++)
	{
		if(tcaResult[i] != '\0') {
			strSectionName = strSectionName + tcaResult[i];
		} else {
			if(strSectionName != "") {
				m_sectionList->InsertAfter(m_sectionList->GetTailPosition(),strSectionName);
			}
			strSectionName = "";
		}
	}

	return m_sectionList;
}

// Used to retrieve all key/value pairs of a given section.  
CStringList* CIniReader::getSectionData(CString strSection)  
{
/*	char ac_Result[2000];  //change size depending on needs*/
	TCHAR tcaResult[BUFFER_BYTE];
	m_sectionDataList->RemoveAll();
	m_lRetValue = GetPrivateProfileSection((LPCTSTR)strSection, tcaResult, BUFFER_BYTE, (LPCTSTR)m_strFileName);

	CString strSectionData;
	for(int i=0; i<m_lRetValue; i++)
	{
		if(tcaResult[i] != '\0') {
			strSectionData = strSectionData + tcaResult[i];
		} else {
			if(strSectionData != "") {
				m_sectionDataList->InsertAfter(m_sectionDataList->GetTailPosition(),strSectionData);
			}
			strSectionData = "";
		}
	}

	return m_sectionDataList;
}

void CIniReader::setINIFileName(CString strINIFile)
{
	m_strFileName = strINIFile;
}

UINT CIniReader::getKeyValueInt(CString strKey, CString strSection)
{
	return GetPrivateProfileInt(strSection, strKey, 0, m_strFileName);
}

double CIniReader::getKeyValueDouble(CString strKey, CString strSection)
{
	CString str = getKeyValue(strKey, strSection);

	double fKeyVal = _tstof(str);

	return fKeyVal;
}

