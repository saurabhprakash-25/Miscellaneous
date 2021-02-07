#ifndef ARRAY_HPP
#define ARRAYHPP

#include<iostream>
#include<string>
#include<algorithm>
#include<assert.h>
using namespace std;

class ArrayException {

  private:
    string    whatis;

    enum class eExceptionType
    {
        INVALID_INDEX = 0,
        ARRAY_FULL,
    };

  public:
                                ArrayException      (eExceptionType pExceptionType);
static  inline  eExceptionType  InvalidIndex        ();
static  inline  eExceptionType  ArrayFull           ();

        inline  string          WhatIsTheException  ();

};

class Array {

  public:

inline              Array               (int pSize);
inline              ~Array              ();

        // Get, Set opearations
inline  int         Get                 (int pIndex);
        void        Set                 (int pIndex, int pValue);

        // Insertion operations
        void        Insert              (int pValue);
        void        InsertAtIndex       (int pIndex, int pValue);
        void        InsertAtBeginning   (int pValue);
        void        InsertAtEnd         (int pValue);

        // Deletion operations
        void        DeleteFromBeginning ();
        void        DeleteFromEnd       ();
        void        DeleteAtIndex       (int pIndex);

        // Mathematical information
        double      Average             ();
        long long   Sum                 ();

        void        Display             (int pStartIndex = 0 , int pEndIndex = 0);
        void        ShiftRight          (int pShiftFactor, int pStartIndex = 0, int pEndIndex = 0);
        void        ShiftLeft           (int pShiftFactor, int pStartIndex = 0, int pEndIndex = 0);

inline  bool        IsIndexOutOfBound   (int pIndex);

        // Meta-information about the array
inline    int       ArraySize          ();
inline    int       NumberOfElements   ();
inline    bool      IsArrayFull        ();

  private:
    int *       vArray;
    int         vSize;
    int         vNumElementsPresent;
    long long   vSum;
};

#include "array.hxx"

#endif // ARRAY_HPP