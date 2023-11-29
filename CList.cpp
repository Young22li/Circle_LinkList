#include "CList.h"

/***************************************************************/
/* Programmer: Ziyang Li                                       */        
/* Date: February 19, 2023                                     */        
/* Purpose: Implementation of circular linked list class       */
/* Inpout: none                                                */
/* Output: print function prints all items in the list         */
/***************************************************************/

template <class T>
CList<T> :: CList()
{
   first = NULL;
   length = 0;
}

template <class T>     
CList<T> :: ~CList()
{ 
    destroy();
}

template <class T>        
CList<T> :: CList ( const CList<T> & other)
{
   copy(other);
}

template <class T>        
const CList<T> & CList<T> :: operator= (const CList<T> & other)
{
   if ( this != &other )
   {
      destroy();
      copy(other); 
   }
  return *this;
}

template <class T>        
bool CList<T> :: isEmpty()
{
   return first == NULL;
}
      
template <class T>        
void CList<T> :: insertItem(T item)
{
   node<T> *p = new node<T>;
   p->info = item;
  
   //Case 1: if the list is empty
   if ( first == NULL )
   {
      first = p;
      p->next = first;
   }
     
   //Case 2: if the item less than the smallest number in the list
   //In other words, insert the item at the beginning of the list
   else if (first->next->info >= item)
    {
        p->next = first->next;
        first->next = p;
    }
     
    //Case 3: if the item greater than the bigest number in the list
    //In other words, insert the item at the end of the list
    else if (first->info <= item)
    {
        p->next = first->next;
        first->next = p;
        first = p;
    }
    //Case 4: insert the item between two node
    else
    {
        node<T> *s = first->next;
        node<T> *r = NULL;

       while ( s->info <= item )
         {
           r = s;
           s = s->next;
         }

        p->next = s;
        r->next = p;
    }
   length++;
}
      
template <class T>      
void CList<T> :: deleteItem(T item)
{
  //If item less than the samllest number or greater than the bigest number
  //The item must not in the list
   if ( first == NULL || item < first->next->info || item > first->info)
      cout<<"\nLIST EMPTY OR ITEM NOT IN THE LIST\n";
    else
    {
      //The pointer P is used to traverse the linked list
      //point to the samllest number
       node<T> *p = first->next;
      
      //Case 1: if the list only have one node
      if( first == p)
      {
        first = NULL;
        delete p;
        length--;
      }

      //Case 2: if the item = the smallest number
       else if ( item == first->next->info)
       {
          first->next = p->next;
          delete p;
          length--;
       }
       else
       {
         // walk into the list and find the number
         
          node<T> *s = NULL;//record the previous node
          while ( p != first && p->info < item )
           {
               s = p;
               p = p->next;
            }

         //Case 3: if the item = the bigest number
          if( item == first->info)
          {
            s->next = p->next;
            first = s;
            delete p;
          }
          //Case 4: item Not in the list
          else if ( p == first || p->info > item ) 
             cout<<"\nITEM NOT IN THE LIST\n";
          //Case 5: item between two Node
          else
          {
             s->next = p->next;
             delete p;
          }
         length--;
       }
    }
}

template <class T>
void CList<T> :: destroy()
{
  if(first != NULL)//If the list is empty, we don't have to destory
  {
    node<T> *p = first->next;
    first->next = NULL;//Set the last node's next is NULL
    first = p;//Move first to the beginning 
    
   //Destory like the singly linked list
    while ( first != NULL)
      {
         p = first;
         first = first->next;
         delete p;       
      }
    length = 0;
    }
  
}

template <class T>
void CList<T> :: copy ( const CList<T> & other )
{
   length = other.length;
  //If "other" list is NULL, we copy the NULL list
   if ( other.first == NULL )
      first = NULL;
   else
   {
      first = new node<T>;
      first->info = other.first->next->info;//copy the smallest number

      node<T> *p = other.first->next->next;//Move to the second number
      node<T> *q = first;

      while(p != other.first->next)
        {
           q->next = new node<T>;
           q = q->next;
           q->info = p->info;
           p = p->next;
        } 

      q->next = first;//the lastest node's next point to the first node
      first = q;//first point to the end
   }
}

template <class T>        
int CList<T> :: getLength()
{
  return length;
}

template <class T>        
bool CList<T> :: searchItem(T item)
{
  //if the list is empty,we don't have to search item.
   if(first != NULL)
   {
    node<T> *p;
    bool found;

    found = false;
    p = first->next;
      do{
         if ( item == p->info )
            found= true;
             p = p->next;    
         }while ( p != first->next && !found && p->info <= item );
         return found;
   }
   else 
      return false;
}

template <class T>        
void CList<T> :: printList()
{
   if ( first == NULL )
      cout<<"\nLIST IS EMPTY\n";
   else
   {
     node<T> *p;

     p = first->next;

     cout<<"\nLIST : ";

     do {
       cout<< p -> info <<" ";
       p = p-> next;
     }while(p != first->next);

     cout<<"\n";
  }  
}

template <class T>        
int CList<T> :: smallestnum()
{
    return first->next->info;
}

template <class T>        
int CList<T> :: biggestnum()
{
    return first->info;
}


