#ifndef ARRAY_HXX
#define ARRAY_HXX

inline ArrayException::ArrayException (string pExceptionMessage)
{
    whatis = pExceptionMessage;
}

inline string ArrayException::WhatIsTheException ()
{
    return whatis;
}

inline Array::Array (int pSize)
{
    vArray              = new int (pSize);
    vSize               = pSize;
    vNumElementsPresent = 0;
    vSum                = 0;
    vMin                = INT_MAX;
    vMax                = INT_MIN;
}

inline Array::~Array ()
{
    delete[] vArray;
    vArray = nullptr;
}

inline int Array::Get (int pIndex)
{
    if (IsIndexOutOfBound (pIndex))
        throw ArrayException("Index out of Range");

    return vArray[pIndex];
}

inline int Array::Average ()
{
    return (vSum / NumberOfElements ());
}

inline int Array::Sum ()
{
    return vSum;
}

inline bool Array::IsArrayFull ()
{
    return NumberOfElements () == ArraySize ();
}

inline bool Array::IsIndexOutOfBound (int pIndex)
{
    return (pIndex < 0 || (pIndex > NumberOfElements () - 1));
}

inline int Array::ArraySize ()
{
    return vSize;
}

inline int Array::NumberOfElements ()
{
    return vNumElementsPresent;
}
#endif // ARRAY_HXX