// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/
//! \file ConvStr.h
//! \brief Define functions to convert between UNICODE string and ANSI string.

#ifndef UTILFUNC_CONVSTR_H_
#define UTILFUNC_CONVSTR_H_

_STD_BEGIN

//! Convert from UNICODE string to ANSI string, std::w2a.
/*!
    \ingroup _GROUP_UTILFUNC
    \param s The source UNICODE string to be converted.
    \param codepage Code page of the target ANSI string. For example CP_UTF8 is UTF-8 code.
    \return The target ANSI string.
*/
inline std::string w2a(const wchar_t* s, UINT codepage = CP_ACP)
{
    std::string str;
    int wlen = (NULL == s) ? 0 : (int)wcslen(s);

    if (wlen > 0)
    {
        long len = WideCharToMultiByte(codepage, 0, s, wlen, NULL, 0, NULL, NULL);
        str.resize(len);
        WideCharToMultiByte(codepage, 0, s, wlen, 
            const_cast<char*>(str.data()), len, NULL, NULL);
    }

    return str;
}

//! Convert from UNICODE string to ANSI string, std::w2a.
/*!
    \ingroup _GROUP_UTILFUNC
    \param s The source UNICODE string to be converted.
    \param codepage Code page of the target ANSI string. For example CP_UTF8 is UTF-8 code.
    \return The target ANSI string.
*/
inline std::string w2a(const std::wstring& s, UINT codepage = CP_ACP)
{
    return w2a(s.c_str(), codepage);
}

//! Convert from ANSI string to UNICODE string, std::a2w.
/*!
    \ingroup _GROUP_UTILFUNC
    \param s The source ANSI string to be converted.
    \param codepage Code page of the source ANSI string. For example CP_UTF8 is UTF-8 code.
    \return UNICODE string
*/
inline std::wstring a2w(LPCSTR s, UINT codepage = CP_ACP)
{
    std::wstring wstr;
    int len = (NULL == s) ? 0 : (int)strlen(s);

    if (len > 0)
    {
        int wlen = MultiByteToWideChar(codepage, 0, s, len, NULL, 0);
        wstr.resize(wlen);
        MultiByteToWideChar(codepage, 0, s, len, 
            const_cast<wchar_t*>(wstr.data()), wlen);
    }

    return wstr;
}

//! Convert from ANSI string to UNICODE string, std::a2w.
/*!
    \ingroup _GROUP_UTILFUNC
    \param s The source ANSI string to be converted.
    \param codepage Code page of the source ANSI string. For example CP_UTF8 is UTF-8 code.
    \return UNICODE string
*/
inline std::wstring a2w(const std::string& s, UINT codepage = CP_ACP)
{
    return a2w(s.c_str(), codepage);
}

#ifdef _UNICODE
inline std::wstring w2t(const wchar_t* s) { return s; }
inline std::wstring w2t(const std::wstring& s) { return s; }
inline std::wstring t2w(LPCTSTR s) { return s; }
#else
inline std::string w2t(const wchar_t* s) { return w2a(s); }
inline std::string w2t(const std::wstring& s) { return w2a(s); }
inline std::wstring t2w(LPCTSTR s) { return a2w(s); }
#endif

_STD_END
#endif // UTILFUNC_CONVSTR_H_
