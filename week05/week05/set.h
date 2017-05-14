/***********************************************************************
 * Header:
 *    set.h
 * Summary:
 *    This will contain the code for our week05 set assignment
 * Author
 *    Jeffry Simpson, David Perez
 ************************************************************************/

#ifndef set_h
#define set_h

#include <iostream>
#include <cassert>

using namespace std;


// forward declaration for SetIterator
template <class T>
class SetIterator;



/************************************************
 * Set
 * A class that holds our Set
 ***********************************************/

template <class T>
class Set
{
private:
   // Member variables
   T * data;
   int iNumItems;
   int iCapacity;
   

public:
   // Constructors
   Set() : data(NULL), iNumItems(0), iCapacity(0) {}
   Set(int capacity) throw (const char *);
   Set(const Set & rhs) throw (const char *);
   
   // destructor
   ~Set()        { if (iCapacity) delete [] data; }
 
   //inline functions
   int size()     const    { return iNumItems;          }
   int capacity() const    { return iCapacity;          }
   bool empty()   const    { return iNumItems == 0;     }
   void clear()            { iNumItems = 0;             }
   
   //Function definitions
   void insert(const T & t) throw (const char *);
   SetIterator <T> begin() { return SetIterator<T>(data); }
   SetIterator <T> end() { return SetIterator<T>(data + iNumItems);}
   
   // Operator =
   Set & operator = (const Set<T> &rhs) throw (const char *);
   
   //Operator []
   T& operator[] (int index) throw(const char *)
   {
      if ( index < 0 || index > iNumItems)
         throw " ERROR: Invalid index\n";
      
      return data[index];
   }
   
   //Operator [] const
   const T operator[] (int index) const throw (const char *)
   {
      if ( index < 0 || index > iNumItems)
         throw " ERROR: Invalid index\n";
      
      return data[index];
   }
   
   
};



/************************************************
 * Set ITERATOR
 * An iterator through Set
 ***********************************************/

template <class T>
class SetIterator
{
public:
   // Constructor
   SetIterator() : p(NULL) {}
   SetIterator(T * p) : p(p) {}
   SetIterator(const SetIterator & rhs) { *this = rhs; }
   
   // not equals operator
   bool operator != (const SetIterator & rhs) const
   {  return rhs.p != this->p;}
   
   // dereference operator
   T & operator * ()
   { return *p; }
   
   // assignment operator
   SetIterator & operator = (const SetIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }
   
   // prefix increment
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }
   
   // postfix increment
   SetIterator <T> operator++(int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }
   
private:
   T * p;
};


/*******************************************
 * Set :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Set <T> :: Set(const Set <T> & rhs) throw (const char *)
{
   assert(rhs.iCapacity >= 0);
   
   // do nothing if there is no capacity to do anything
   if (rhs.iCapacity == 0)
   {
      iCapacity = iNumItems = 0;
      data = NULL;
      return;
   }
   
   // attempt to allocate
   try
   {
      data = new T[rhs.iCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.iNumItems >= 0 && rhs.iNumItems <= rhs.iCapacity);
   iCapacity = rhs.iCapacity;
   iNumItems = rhs.iNumItems;
   
   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < iNumItems; i++)
      data[i] = rhs.data[i];
      
      // the rest needs to be filled with the default value for T
      for (int i = iNumItems; i < iCapacity; i++)
         data[i] = T();
         }


/**********************************************
 * Set : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Set to "capacity"
 **********************************************/
template <class T>
Set <T> :: Set(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->iCapacity = this->iNumItems = 0;
      this->data = NULL;
      return;
   }
   
   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   
   // copy over the stuff
   this->iCapacity = capacity;
   this->iNumItems = 0;
   
   // initialize the Set by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
      }


/***************************************************
 * Set :: INSERT
 * Insert an item on the end of the Set
 **************************************************/
template <class T>
void Set <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (iCapacity == 0 || iCapacity == iNumItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[iNumItems++] = t;
}


/*******************************************
 * Set :: Operator =
 
 *******************************************/
template <class T>
Set<T> & Set <T> :: operator = (const Set <T> &rhs)
throw (const char *)
{
   
   assert(rhs.iNumItems >= 0 && rhs.iNumItems <= rhs.iCapacity);
   
   // do nothing right hand size is empty
   if (rhs.iCapacity == 0)
   {
      iCapacity = iNumItems = 0;
      data = NULL;
      return *this;
   }
   
   //Delete existing data, if any
   if(iCapacity)
      delete [] data;
   
   //Prep the class for new data
   try
   {
      data = new T[rhs.iCapacity];
      iNumItems = rhs.iNumItems;
      iCapacity = rhs.iCapacity;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy the items over one at a time
   for (int i = 0; i < iNumItems; i++)
      data[i] = rhs.data[i];
      
      // the rest needs to be filled with the default value for T
      for (int i = iNumItems; i < iCapacity; i++)
         data[i] = T();
         
         return *this;
}




#endif /* set_h */
