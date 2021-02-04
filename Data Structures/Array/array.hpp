#ifndef ARRAY_HPP
#define ARRAYHPP

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class ArrayException {

  public:
inline          ArrayException      (string pExceptionMessage);

inline  string  WhatIsTheException  ();

  private :
    string    whatis;
};

class Array {

  public:

inline          Array               (int pSize);
inline          ~Array              ();

        // Get, Set
inline  int     Get                 (int pIndex);
        void    Set                 (int pIndex, int pValue);

        // Insertion
        void    Insert              (int pValue);
        void    InsertAtIndex       (int pIndex, int pValue);
        void    InsertAtBeginning   (int pValue);
        void    InsertAtEnd         (int pValue);

        // Deletion
        void    DeleteFromBeginning ();
        void    DeleteFromEnd       ();
        void    DeleteAtIndex       (int pIndex);

        // Mathematical informations
        int     Average             ();
        int     Sum                 ();

        void    Display             (int pStartIdx = 0 , int pEndIdx = 0);
        void    ShiftRight          (int pShiftFactor, int pStartIdx = 0, int pEndIdx = 0);
        void    ShiftLeft           (int pShiftFactor, int pStartIdx = 0, int pEndIdx = 0);

inline  bool    IsIndexOutOfBound   (int pIndex);

        // Meta-information about the array
inline    int   ArraySize          ();
inline    int   NumberOfElements   ();
inline    bool  IsArrayFull        ();

  private:
    int *       vArray;
    int         vSize;
    int         vNumElementsPresent;
    int         vMin;
    int         vMax;
    int         vSum;
};

#include "array.hxx"

#endif // ARRAY_HPP