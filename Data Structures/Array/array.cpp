#include "array.hpp"

ArrayException::ArrayException (eExceptionType pExceptionType)
{
    switch (pExceptionType) {

        case eExceptionType::INVALID_INDEX :
            whatis = "Invalid Index\n";
            break;
        case eExceptionType::ARRAY_FULL :
            whatis = "Array alrady full. Can't insert more elements\n";
            break;
        default :
            // Should never reach here.
            assert (false);
    }
}

/**
 * @brief Sets pIndex with value pValue and updates the sum
 *
 * @param pIndex
 * @param pValue
 */
void Array::Set (int pIndex, int pValue)
{
    if (IsIndexOutOfBound (pIndex))
        throw ArrayException (ArrayException::InvalidIndex ());

    // Remove the difference
    vSum -= (vArray[pIndex] - pValue);
    vArray[pIndex] = pValue;
}

/**
 * @brief Wrapper for InsertAtEnd
 *
 * @param pValue
 */
void Array::Insert (int pValue)
{
    InsertAtEnd (pValue);
}

/**
 * @brief Inserts an element at a particular index. Throws an exception
 * if the array is already full or if the index is invalid
 *
 * @param pIndex
 * @param pValue
 */
void Array::InsertAtIndex (int pIndex, int pValue)
{
    if (IsArrayFull ())
        throw ArrayException (ArrayException::ArrayFull ());

    if (IsIndexOutOfBound (pIndex))
        throw ArrayException (ArrayException::InvalidIndex ());

    ShiftRight (1, pIndex, NumberOfElements () - 1);

    // As the value at pIndex would be 0 after the shift, the Set function would not
    // be able to set the correct sum
    vSum -= vArray[pIndex + 1];

    Set (pIndex, pValue);

    vNumElementsPresent++;
}

/**
 * @brief Inserts the element at the beginning of the array
 * by shifting all the elements if possible. Throws an exception
 * if the array if already full
 *
 * @param pValue
 */
void Array::InsertAtBeginning (int pValue)
{
    InsertAtIndex (0, pValue);
}

/**
 * @brief Inserts the element at the end of the array. Throws exception
 * if the array is already full
 *
 * @param pValue
 */
void Array::InsertAtEnd (int pValue)
{
    if (IsArrayFull ())
        throw ArrayException (ArrayException::ArrayFull ());

    Set (NumberOfElements () , pValue);

    vNumElementsPresent++;
}

/**
 * @brief Deletes an element from the beginning and shifts the
 * remaining elements to the left
 *
 */
void Array::DeleteFromBeginning ()
{
    DeleteAtIndex (0);
}

/**
 * @brief Deletes and element from the end
 *
 */
void Array::DeleteFromEnd ()
{
    int sum = vSum - vArray[NumberOfElements () - 1];

    vArray[NumberOfElements () - 1] = 0;

    --vNumElementsPresent;

    vSum = sum;
}

/**
 * @brief Deletes element at a particular index. The index is expected
 * to be valid
 *
 * @param pIndex
 */
void Array::DeleteAtIndex (int pIndex)
{
    int sum = vSum - Get (pIndex);

    if (IsIndexOutOfBound (pIndex))
        throw ArrayException (ArrayException::InvalidIndex ());

    ShiftLeft (1, pIndex + 1, NumberOfElements () - 1);

    --vNumElementsPresent;

    vSum = sum;
}

/**
 * @brief Prints all the elements in the array in [pStartIndex,pEndIndex]
 * Throws an exception if index is invalid
 *
 * @param pStartIdx
 * @param pEndIdx
 */
void Array::Display (int pStartIndex, int pEndIndex)
{
    if (IsIndexOutOfBound (pStartIndex) || IsIndexOutOfBound (pEndIndex) || (pStartIndex > pEndIndex))
        throw ArrayException (ArrayException::InvalidIndex ());

    pEndIndex = !pEndIndex ? (NumberOfElements () - 1) : pEndIndex;

    for (int idx = pStartIndex; idx <= pEndIndex; ++idx) {
        cout << vArray[idx] << " ";
    }
    cout << "\n";
}

/**
 * @brief Shifts the elements in [pStartIndex, pEndIdx] to the right
 * by the shift factor. 0 is filled previous position of elements that
 * are shifted. Throws an exception if it's not possible.
 *
 * @param pShiftFactor
 * @param pStartIdx
 * @param pEndIdx
 */
void Array::ShiftRight(int pShiftFactor, int pStartIndex, int pEndIndex)
{
    if (IsIndexOutOfBound (pStartIndex)   ||
        IsIndexOutOfBound (pEndIndex)     ||
        (pStartIndex > pEndIndex)           ||
        ((pEndIndex + pShiftFactor) > ArraySize () - 1))
            throw ArrayException (ArrayException::InvalidIndex ());

      pEndIndex = !pEndIndex ? (NumberOfElements () - 1) : pEndIndex;

    for (int idx = pEndIndex; idx >= pStartIndex; --idx) {

        Set (idx + pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}

/**
 * @brief Shifts all the elements in [pStartIndex, pEndIndex] to the left
 * by the shift factor. 0 is filled previous position of elements that .
 * Throws an exception if it's not possible.
 *
 * @param pShiftFactor
 * @param pStartIdx
 * @param pEndIdx
 */
void Array::ShiftLeft (int pShiftFactor, int pStartIndex, int pEndIndex)
{
    if (IsIndexOutOfBound (pStartIndex)   ||
        IsIndexOutOfBound (pEndIndex)     ||
        (pStartIndex > pEndIndex)           ||
        ((pEndIndex - pShiftFactor) < 0))
            throw ArrayException (ArrayException::InvalidIndex ());

    pEndIndex = !pEndIndex ? (NumberOfElements () - 1) : pEndIndex;

    for (int idx = pStartIndex ; idx <= pEndIndex; ++idx) {

        Set (idx - pShiftFactor, Get (idx));
        Set (idx, 0);
    }
}