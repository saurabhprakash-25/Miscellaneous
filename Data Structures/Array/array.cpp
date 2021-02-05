#include "array.hpp"

void Array::Set (int pIndex, int pValue)
{
    if (IsIndexOutOfBound (pIndex))
        throw ArrayException("Invalid Index");

    // Remove the difference
    vSum -= (vArray[pIndex] - pValue);
    vArray[pIndex] = pValue;
}

void Array::Insert (int pValue)
{
    InsertAtEnd (pValue);
}

void Array::InsertAtIndex (int pIndex, int pValue)
{
    if (IsArrayFull ())
        throw ArrayException("Array alrady full. Can't insert more elements\n");

    if (IsIndexOutOfBound (pIndex))
        throw ArrayException("Invalid Index");

    ShiftRight (1, pIndex, NumberOfElements () - 1);

    // As the value at pIndex would be 0 after the shift, the Set function would not
    // set the correct sum
    vSum -= vArray[pIndex + 1];

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

void Array::DeleteAtIndex (int pIndex)
{
    if (IsIndexOutOfBound (pIndex))
        throw ArrayException ("Invalid Index\n");

    vSum -= Get (pIndex);
    
    ShiftLeft (1, pIndex + 1, NumberOfElements () - 1);

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
    if (IsIndexOutOfBound (pStartIdx)   ||
        IsIndexOutOfBound (pEndIdx)     ||
        (pStartIdx > pEndIdx)           ||
        ((pEndIdx + pShiftFactor) > NumberOfElements() - 1))
            throw ArrayException("Invalid Index");

    for (int idx = pEndIdx; idx >= pStartIdx; --idx) {

        Set (idx + pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}

void Array::ShiftLeft (int pShiftFactor, int pStartIdx, int pEndIdx)
{
    if (IsIndexOutOfBound (pStartIdx)   ||
        IsIndexOutOfBound (pEndIdx)     ||
        (pStartIdx > pEndIdx)           ||
        ((pEndIdx - pShiftFactor) < 0))
            throw ArrayException("Invalid Index");

    for (int idx = pStartIdx ; idx <= pEndIdx; ++idx) {

        Set (idx - pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}