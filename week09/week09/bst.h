/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Helfrich, CS 235
 * Author:
 *    
 * Summary:
 *    
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include <stack>
#include "bnode.h"

// Iterators prototypes
template <class T>
class BSTIterator;
template <class T>
class BSTConstIterator;

template <class T>
class BST
{
private:
   BinaryNode<T> * pRoot;
   int numElements;
   
   void insertRecursive(BST<T> & pRoot,const T & t) throw (const char *);
   

   
public:
   BST() : pRoot(NULL), numElements(0){}
   BST(const BST<T> & rhs) throw (const char *);
   
   ~BST(){}

   //Operator =
   BST <T> & operator = (const BST <T> & rhs) throw(const char *);
   
   //inLine functions
   int size()     { return pRoot->size(); }
   bool empty()   { return (numElements== 0); }
   
   //Function
   void insert(const T & t) throw (const char *);
   
      //Iterator functions
   void remove(BSTIterator<T> & it);
   BSTIterator<T> find(const T & t);
   BSTIterator<T> begin()  { return BSTIterator<T>(pRoot); }
   //BSTIterator<T> rbegin() { return BSTIterator<T>(pTail); }
   BSTIterator<T> end()    { return BSTIterator<T>(NULL); }
   BSTIterator<T> rend()   { return BSTIterator<T>(NULL); }

};

/************************************************
 * Copy Constructor
 * Used to copy one list to the other
 ***********************************************/
template <class T>
BST <T> :: BST(const BST <T> & rhs) throw (const char *)
{
   numElements = rhs.numElements;
   
   //Verify we got something to copy
   if (NULL != rhs.pRoot)
   {
      // clear();
      
      try
      {
         // allocate a new head
         pRoot = new BinaryNode<T>(rhs.pRoot->data);
         
         pRoot->pLeft =  copyBTree(rhs.pRoot->pLeft);
         
         if(pRoot->pLeft != NULL)
            pRoot->pLeft->pParent = pRoot;
            
         pRoot->pRight = copyBTree(rhs.pRoot->pRight);
         if(pRoot->pRight != NULL)
            pRoot->pRight->pParent = pRoot;
 
      }
      catch (bad_alloc)
      {
         throw "ERROR: unable to allocate a new node for this tree.";
      }
   }
   else
      pRoot = rhs.pRoot;  //Set Copy Node to Null to match RHS
   
   
}

/**********************************************
 * BST :: assignment operator
 * Copy one list onto another
 *********************************************/
template <class T>
BST <T> & BST <T> :: operator = (const BST <T> & rhs) throw (const char *)
{

      
      // return the new buffer
      return *this;
}

/************************************************
 * Insert function
 * Used to insert a new node into the tree
 ***********************************************/
template <class T>
 void BST <T> :: insert(const T & item) throw (const char *)
{
   try
   {
      BinaryNode<T> * locptr = pRoot;
      BinaryNode<T> * parent = 0;
      
      while (locptr != NULL  ) {
         parent = locptr;
         if (item < locptr->data)
            locptr = locptr->pLeft;
            else
               locptr = locptr->pRight;
               }
      
      locptr = new BinaryNode<T>(item);
      if(parent == NULL)
         pRoot = locptr;
         else if (item < parent->data)
         {
            parent->pLeft = locptr;
            locptr->pParent = parent;
         }
         else
         {
            parent->pRight = locptr;
            locptr->pParent = parent;
         }
         
   }
   catch (bad_alloc)
   {
      throw "ERROR: unable to allocate a new node for this tree.";
   }
}




/************************************************
 * Erase funciton
 * Used to erase a node from the tree
 ***********************************************/
template <class T>
void BST<T> ::remove(BSTIterator<T> & it)
{
   
}


/************************************************
 * ListIterator
 * Class iterator used for list
 ***********************************************/
template <class T>
class BSTIterator
{
private:
   stack<BinaryNode<T>> nodes;

public:
   BSTIterator<T> & operator -- ();
   
   
};

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 *     advance by one. Note that this implementation uses
 *     a stack of nodes to remember where we are. This stack
 *     is called "nodes".
 * Author:      Br. Helfrich
 * Performance: O(log n) though O(1) in the common case
 *************************************************/
template <class T>
BSTIterator <T> & BSTIterator <T> :: operator -- ()
{
   // do nothing if we have nothing
   if (nodes.top() == NULL)
      return *this;

   // if there is a left node, take it
   if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

      // there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(nodes.top()->pLeft == NULL);
   BinaryNode <T> * pSave = nodes.top();
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

#endif // BST_H

