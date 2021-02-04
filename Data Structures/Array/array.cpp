#include "array.hpp"

void Array::Set (int pIndex, int pValue)
{
    if (pIndex < 0 || pIndex > ArraySize ())
        throw ArrayException("Index out of Range");

    vArray[pIndex] = pValue;
    vSum           = vSum + pValue;
}

void Array::Insert (int pValue)
{
    InsertAtEnd (pValue);
}

void Array::InsertAtIndex (int pIndex, int pValue)
{
    if (IsArrayFull ())
        throw ArrayException("Array alrady full. Can't insert more elements\n");

    ShiftRight (1, pIndex, NumberOfElements () - 1);

    Set (pIndex, pValue);

    vNumElementsPresent++;
}

void Array::InsertAtBeginning (int pValue)
{
    InsertAtIndex (0, pValue);
}

void Array::InsertAtEnd (int pValue)
{
    if (IsArrayFull ())
        throw ArrayException ("Array alrady full. Can't insert more elements\n");

    Set (NumberOfElements () - 1, pValue);

    vNumElementsPresent++;
}

void Array::DeleteFromBeginning ()
{
    DeleteAtIndex (0);
}

void Array::DeleteFromEnd ()
{
    vSum -= vArray[NumberOfElements () - 1];
    
    vArray[NumberOfElements () - 1] = 0;
    
    --vNumElementsPresent;
}

void Array::DeleteAtIndex (int pIdx)
{
    vSum -= Get (pIdx);
    
    ShiftLeft (1, pIdx + 1, NumberOfElements () - 1);

    --vNumElementsPresent;
}

void Array::Display (int pStartIdx, int pEndIdx)
{
    pEndIdx = !pEndIdx ? (NumberOfElements () - 1) : pEndIdx;

    for (int idx = pStartIdx; idx <= pEndIdx; ++idx) {
        cout << vArray[idx] << " ";
    }
}

void Array::ShiftRight(int pShiftFactor, int pStartIdx, int pEndIdx)
{       
    for (int idx = min (pEndIdx, (NumberOfElements () - 1 - pShiftFactor)); idx >= pStartIdx; --idx) {

        Set (idx + pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}

void Array::ShiftLeft (int pShiftFactor, int pStartIdx, int pEndIdx)
{
    for (int idx = max (pShiftFactor, pStartIdx) ; idx <= pEndIdx; ++idx) {

        Set (idx - pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}