/*! \file ReadInts.h
 *  \brief Define functions splitting numbers from a string: ReadInts �� ReadDoubleArray
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef UTILFUNC_READINTS_H_
#define UTILFUNC_READINTS_H_

//! Check if a character is element of integer number.
/*!
    \param c a character to check.
    \param signchar true if integer numbers can have plus or minus sign.
    \return the character is element of integer number or not.
*/
inline bool IsIntChar(wchar_t c, bool signchar = false)
{
    return iswdigit(c) || signchar && ('+' == c || '-' == c);
}

//! splitting integer numbers from a string.
/*!
    \ingroup _GROUP_UTILFUNC
    \param[in] str a string which contains numbers separated by punctuation or spaces.
    \param[out] arr the buffer which will be filled with numbers.
    \param[in] size maximum count of numbers in the buffer 'arr'.
    \param[in] signchar true if integer numbers can have plus or minus sign.
    \return count of numbers filled in the buffer.
    \see IsIntChar, ReadDoubleArray
*/
template <class IntType> inline
long ReadInts(const wchar_t* str, IntType* arr, long size, bool signchar = false)
{
    if (NULL == str)
    {
        return 0;
    }

    int i, j, count;
    wchar_t buf[13];

    for (i = 0, count = 0; str[i] != 0 && count < size; )
    {
        while (str[i] != 0 && !IsIntChar(str[i], signchar))
        {
            i++;
        }
        for (j = i; IsIntChar(str[j], signchar); j++)
        {
        }
        if (j > i)
        {
            lstrcpynW(buf, str + i, min(_countof(buf), 1 + j - i));
            arr[count++] = static_cast<IntType>(_wtoi(buf));
        }
        i = j;
    }

    return count;
}

//! Check if a character is element of floating point number.
inline bool IsDblChar(wchar_t c)
{
    return iswdigit(c) || '+' == c || '-' == c
        || '.' == c || 'E' == c || 'e' == c;
}

//! splitting floating point numbers from a string.
/*!
    \ingroup _GROUP_UTILFUNC
    \param[in] str a string which contains numbers separated by punctuation or spaces.
    \param[out] arr the buffer which will be filled with numbers.
    \param[in] size maximum count of numbers in the buffer 'arr'.
    \return count of numbers filled in the buffer.
    \see IsDblChar, ReadInts
*/
inline long ReadDoubleArray(const wchar_t* str, double* arr, long size)
{
    if (NULL == str)
    {
        return 0;
    }

    int i, j, count;
    wchar_t buf[32];
    wchar_t* endptr;

    for (i = 0, count = 0; str[i] != 0 && count < size; )
    {
        while (str[i] != 0 && !IsDblChar(str[i]))
        {
            i++;
        }
        for (j = i; IsDblChar(str[j]); j++)
        {
        }
        if (j > i)
        {
            lstrcpynW(buf, str + i, min(32, 1 + j - i));
            arr[count++] = wcstod(buf, &endptr);
        }
        i = j;
    }

    return count;
}

#endif // UTILFUNC_READINTS_H_
