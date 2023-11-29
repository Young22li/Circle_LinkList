#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Ziyang Li                                      */        
/* Date: February 19, 2023                                    */        
/* Purpose: circular linked list class                         */
/***************************************************************/

#ifndef CLIST_H
#define CLIST_H

template <class T>
struct node
{
   T info;
   node<T> *next;
};

template <class T>
class CList 
{
   private:
      node<T> *first; 
      int length;
   public:
      //Constructor 
      CList();
      // Destructor
      ~CList();
      //Copy constructor
      CList ( const CList<T> & other);
      //Overload the assignment operator 
      const CList<T> & operator= (const CList<T> & other);
      //Returns current length of list
      int getLength();
      // Returns true if list is empty, false otherwise
      bool isEmpty();
      // Inserts parameter item
      void insertItem(T item);
      //If list is not empty and parameter item is in the list, removes   
      // item from the list and decrements length. If list is empty or 
      // item is not in the list, prints error message
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Print all items in the list. Print message if list is empty.
      void printList();
      // function to copy a list
      void copy (const CList<T> & other);
      // Destroy list function
      void destroy();
      //Return the samllest number
      int smallestnum();
      //Return the bigest number
      int biggestnum();
    
};
#endif