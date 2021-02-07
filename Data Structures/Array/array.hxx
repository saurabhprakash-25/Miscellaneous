#ifndef ARRAY_HXX
#define ARRAY_HXX

inline ArrayException::eExceptionType ArrayException::InvalidIndex ()
{
    return eExceptionType::INVALID_INDEX;
}

inline ArrayException::eExceptionType ArrayException::ArrayFull ()
{
    return eExceptionType::ARRAY_FULL;
}

inline string ArrayException::WhatIsTheException ()
{
    return whatis;
}

inline Array::Array (int pSize)
{
    vArray              = new int[pSize]();
    vSize               = pSize;
    vNumElementsPresent = 0;
    vSum                = 0;
}

inline Array::~Array ()
{
    delete[] vArray;
    vArray = nullptr;
}

inline int Array::Get (int pIndex)
{
    if (IsIndexOutOfBound (pIndex))
        throw ArrayException (ArrayException::InvalidIndex ());

    return vArray[pIndex];
}

inline double Array::Average ()
{
    return (vSum / NumberOfElements ());
}

inline long long Array::Sum ()
{
    return vSum;
}

inline bool Array::IsArrayFull ()
{
    return NumberOfElements () == ArraySize ();
}

inline bool Array::IsIndexOutOfBound (int pIndex)
{
    return (pIndex < 0 || pIndex >= ArraySize ());
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