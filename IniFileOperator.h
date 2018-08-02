/************************************************************
Copyright (C), 1988-1999,z111
File name:INI.h		
Author:	����	Version:V1.0	Date:16-3-11
Link��http://www.codeproject.com/Articles/2901/How-to-read-and-write-an-INI-File?msg=583578#xx583578xx
Reference Link:http://www.codeproject.com/Articles/10809/A-Small-Class-to-Read-INI-File
-------------------------
Description:
-------------------------
	���ڶ�ȡ��д��Ini�ļ����ࡣ
-------------------------
Function List:	//��Ҫ�����б�ÿ����¼Ӧ���������������ܼ��
-------------------------
	1. setINIFileName()
		ָ��Ini�ļ������֡�
	2.setKeyValue(CString...)/setKeyValue(int...)/setKeyValue(double...)
		���ü�ֵ������ļ������������������ڣ������Զ�����
	3.getKeyValue()/getKeyValueInt()/getKeyValueDouble
		��ȡָ������-�����ļ�ֵ
	4.sectionExists����
		�ж�ָ�������Ƿ���ڡ�
	5.getSectionNames()
		��ȡ�ļ������еĶ���
	6.getSectionData()
		��ȡ���������м���-��ֵ�ԡ��м�����'='�Ÿ����ġ�
	7.getKeyValueInt()
		��������ʽ��ȡ��ֵ�Ĵ�С������д������CString�����ǵõ������Ρ�
	7.CIniReader()
		���캯���������ڲ������ռ�
	8.CIniReader(CString)
		���죬ָ�����ļ�����
-------------------------
History:		//�޸���ʷ��¼�б�
-------------------------
1.Data:16-3-11
2.Author:	����
3.Modification:�����г���GetPrivateProfileString()�����Ĳ���char *
�Ͳ����޸�ΪCString���ͣ���֧��Unicode��

1.Data:	16-3-11
2.Author:	����
3.GetPrivateProfileSectionNames:char�ĳ�TCHAR����CString��GetLength�����⡣

1.Data:	16-3-11
2.Author:	����
3.GetPrivateProfileSectionNames:���getKeyValueInt()��getKeyValueDouble
	��setKeyValue(int...)��setKeyValue(double...)

1.Date��16-4-1
2.Author������
3.����operator=���ز���������������Ĭ�ϸ�ֵ�ᶯ̬�ڴ�ָ��ͻᱻ��ֵ����ɶ��delete
************************************************************/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INIFILE_H__99976B4B_DBA1_4D1E_AA14_CBEB63042FD1__INCLUDED_)
#define AFX_INIFILE_H__99976B4B_DBA1_4D1E_AA14_CBEB63042FD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxcoll.h>

class CIniReader  
{
public:
	// method to set INI file name, if not already specified 
	void setINIFileName(CString strINIFile);
	
	// methods to return the lists of section data and section names
	CStringList* getSectionData(CString strSection);
	CStringList* getSectionNames();
	
	// check if the section exists in the file
	BOOL sectionExists(CString strSection);

	// updates the key value, if key already exists, else creates a key-value pair
	BOOL setKeyValue(CString strValue, CString strKey, CString strSection);
	BOOL setKeyValue(UINT iKeyValue, CString strKey, CString strSection);
	BOOL setKeyValue(double fKeyValue, CString strKey, CString strSection);

	// give the key value for the specified key of a section
	CString getKeyValue(CString strKey,CString strSection);
	UINT getKeyValueInt(CString strKey, CString strSection);
	double getKeyValueDouble(CString strKey, CString strSection);
	
	// default constructor
	CIniReader()
	{
		m_sectionList = new CStringList;
		m_sectionDataList = new CStringList;
	}
	
	CIniReader(CString strFile)
	{
		m_strFileName = strFile;
		m_sectionList = new CStringList();
		m_sectionDataList = new CStringList();
	}
	
	~CIniReader()
	{
		delete m_sectionList;
		delete m_sectionDataList;
	}

	CIniReader& operator=(CIniReader &iniReader)
	{
		m_strFileName = iniReader.m_strFileName;
		return *this;
	}
	
private:
	// lists to keep sections and section data
	CStringList *m_sectionDataList;
	CStringList *m_sectionList;
	
	CString m_strSection;
	long m_lRetValue;
	
	// ini file name 
	CString m_strFileName;
};

#endif // !defined(AFX_INIFILE_H__99976B4B_DBA1_4D1E_AA14_CBEB63042FD1__INCLUDED_)
