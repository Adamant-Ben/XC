/************************************************************
Copyright (C), 1988-1999,z111
File name:INI.h		
Author:	下载	Version:V1.0	Date:16-3-11
Link：http://www.codeproject.com/Articles/2901/How-to-read-and-write-an-INI-File?msg=583578#xx583578xx
Reference Link:http://www.codeproject.com/Articles/10809/A-Small-Class-to-Read-INI-File
-------------------------
Description:
-------------------------
	用于读取和写入Ini文件的类。
-------------------------
Function List:	//主要函数列表，每条记录应包括函数名及功能简介
-------------------------
	1. setINIFileName()
		指定Ini文件的名字。
	2.setKeyValue(CString...)/setKeyValue(int...)/setKeyValue(double...)
		设置键值，如果文件名或段名或键名不存在，都会自动创建
	3.getKeyValue()/getKeyValueInt()/getKeyValueDouble
		获取指定段名-键名的键值
	4.sectionExists（）
		判断指定键名是否存在。
	5.getSectionNames()
		获取文件中所有的段名
	6.getSectionData()
		获取段名中所有键名-键值对。中间是用'='号隔开的。
	7.getKeyValueInt()
		以整数形式获取键值的大小，尽管写入是以CString，但是得到的整形。
	7.CIniReader()
		构造函数，分配内部变量空间
	8.CIniReader(CString)
		构造，指定了文件名。
-------------------------
History:		//修改历史记录列表
-------------------------
1.Data:16-3-11
2.Author:	张明
3.Modification:将所有出现GetPrivateProfileString()函数的参数char *
型参数修改为CString类型，来支持Unicode。

1.Data:	16-3-11
2.Author:	张明
3.GetPrivateProfileSectionNames:char改成TCHAR。用CString后GetLength有问题。

1.Data:	16-3-11
2.Author:	张明
3.GetPrivateProfileSectionNames:添加getKeyValueInt()、getKeyValueDouble
	、setKeyValue(int...)、setKeyValue(double...)

1.Date：16-4-1
2.Author：张明
3.增加operator=重载操作符函数，否则默认赋值会动态内存指针就会被赋值，造成多次delete
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
