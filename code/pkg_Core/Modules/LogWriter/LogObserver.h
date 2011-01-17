// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/

#ifndef _X3_LOGWRITER_LOGOBSERVER_H
#define _X3_LOGWRITER_LOGOBSERVER_H

#include <ILogObserver.h>

#include <log4cplus/logger.h>
using namespace log4cplus;

class CLogObserver : public CLogObserverImpl
{
public:
    CLogObserver();
    virtual ~CLogObserver();

protected:
    virtual void OnPushGroup(long nLevel, 
        const std::wstring& wstrMsg, const std::wstring& wstrExtra, 
        const std::wstring& wstrModule, const std::wstring& wstrID);
    virtual void OnPopGroup(long nLevel);
    virtual void OnWriteLog(int nType, 
        const std::wstring& wstrMsg, const std::wstring& wstrExtra, 
        const std::wstring& wstrModule, const std::wstring& wstrID, 
        const std::wstring& wstrFile, long nLine);

private:
    Logger GetLogger();
    void InitLogFile();
    void MakerInitVars();
    void WritePropFile(const wchar_t* pszFileName);

private:
    std::wstring    m_wstrPath;         // ��־�ļ�Ŀ¼��ĩβ��б�ܺ�
    std::wstring    m_wstrAppName;      // Ӧ�ñ�ʶ����
    bool            m_bInited;          // �Ƿ��ѳ�ʼ������־�ļ�
    long            m_nGroupLevel;      // ��ǰ��־��ļ���
};

#endif // _X3_LOGWRITER_LOGOBSERVER_H