#include <list.h>

#include <iostream>
using namespace std;

//implements methods od list class

List::List(void)
{
  //constructor
  currentPos = -1;
  count = 0;
  current = NULL;
}
List::~List(void)
{
  //descructor
  // cout<< "descructor called" << endl;

  first(); //move current to 1st node
  Node *temp;
  while( current != NULL)
    {
      temp = current;
      current = current->next;
      delete temp;
      temp = NULL;
    }
  
  delete current;
  current = NULL;
    
}


void List::first()
{
  //reset pos to 1st item
  
  while(currentPos != 0)
    {
      //move back one node
      Node *temp;
      temp = current;
      //move current to first item
      while( temp != NULL && currentPos != 0)
	{	  
	  temp = temp->prev;
	  currentPos--;
	}

      current = temp;
      
    }
	    
}

void List::last()
{
  Node *temp;
  temp = current;
  //reset to last item in list count-1 is pos of last item
  while(temp != NULL && currentPos != count-1)
    {
      //move forward one nod
      temp = temp->next;
      //move current Pos forward one node
      currentPos = currentPos + 1;
    }
  current = temp;
  delete temp;
  temp = NULL;
}

void List::makecurrent(int position)
{
  
  if(position == currentPos)
    {
      return;
    }
  else if(currentPos > position)//if currentPos is bigger than position
    {
      Node *temp;
      temp = current;
      while(currentPos != position)
	{
	  temp = temp->prev;
	  currentPos = currentPos - 1;
	  
	}
      current = temp;
          
    }
  else if(currentPos < position)//currentPos is smaller than position
    {
      Node *tmp;
      tmp = current;
      while(currentPos != position)
	{
	  tmp = tmp->next;
	  //move current Pos back one node
	  currentPos = currentPos + 1;
	}
      current = tmp;
      
    }
}

void List::prev()
{
  //reset list pos to prev item
  Node *temp;
  temp = current;
  temp = temp->prev;
  current = temp;
  
  currentPos = currentPos - 1;
}

void List::next()
{
  //reset list pos to next

  Node *temp = current;
  temp = temp->next;
  current = temp;
  
  currentPos = currentPos + 1;
  
}

Item List::examineItem()
{
  //get item at current pos
  return current->item;
}

string List::examineKey()
{
  //get key at currentPos
  return current->key;
}

void List::insertBefore(string key, Item value)
{
  //insert item before currentPos

  Node *temp = new Node;
  temp->key = key;
  temp->item = value;

  if(currentPos == -1)
    {
      //list is empty
      current = temp;
      count++;
      currentPos = 0;
      delete temp;
      temp = NULL;
      return;
    }
  else if(contains(key) > -1)
    {
      delete temp;
      temp = NULL;
      return;
    }
  else if( currentPos == 0 )// if front
    {
      current->prev = temp;
      temp->next = current;
      currentPos = 1;
      count++;
      return;
    }
  else if( currentPos == count-1 && count > 1)//if current is end of list
    {
      
      current->prev->next = temp;
      temp->prev = current->prev;
      temp->next = current;
      current->prev = temp;
      currentPos++;
      count++;
      return;
      
    }
  else
    {
      //prev nodes next is new node
      current->prev->next = temp;
      
      //new nodes prev is current nodes old prev
      temp->prev = current->prev;
      
      //new nodes next is current
      temp->next = current;
      
      //current node prev is new node
      current->prev = temp;
      currentPos++;
      count++;//
      return;
    }
}

void List::insertAfter(string key, Item value)
{
  //insert item after currentPos
 
  Node *temp = new Node;
  temp->key = key;
  temp->item = value;
  temp->next = NULL;
  temp->prev = NULL;

  if(currentPos == -1)
    {
     
      //list is empty
      current = temp;      
      count = 1;
      currentPos = 0;
     
      return;
    }
  else if(contains(key) > -1)
    {
      delete temp;
      temp = NULL;
      return;
    }
  else if( currentPos == count-1)// if back of list
    {
       
      //   cout<<"test elif 1"<<endl;
      //add to back of list
      current->next = temp;
      temp->prev = current;
      count++;
      
      return;
    }
  else if( currentPos == 0 && count > 1)//if current is front of list
    {

      current->next->prev = temp; //current next prev is added node
      temp->next = current->next; //temp next is current next
      temp->prev = current; //temp prev is current
      //  cout<< "TEST pt" << current->next->prev << endl;
      current->next = temp; //current next is prev
     
      count++;
      return;
    }
  else
    {
      //next nodes prev is new node
      current->next->prev = temp;
      
      //new nodes next is current nodes old next
      temp->next = current->next;
      
      //new nodes prev is current
      temp->prev = current;
      
      //current node next is new node
      current->next = temp;
      
      count++;
      return;
    }
  
}

void List::remove()
{
  //remove current item
  cout<<count<<endl;
  if( empty() )
    {
      cout << "list empty nothing to delete" << endl;
      return;
    }
  else if(count == 1 && current->item.count == 1)
    {
      
      delete current;
      current = NULL;
      count = 0;
      return;
    }
  else if(current->item.count > 1) //more than 1 instance of item
    {
      
      current->item.count--;
      return;
    }
  else if(currentPos == count-1)//last in list
    {
    
      Node *temp;
      temp = current;
      current = current->prev;
      current->next = NULL;
      delete temp;
      temp = NULL;
      count--;
      currentPos--;
      return;
    }
  else if(currentPos == 0 && count > 1)//IF 1ST ITEM
    {
      
      Node *temp;
      temp = current;
      current = current->next;
      //current->prev = NULL;
      
      delete temp;
      temp = NULL;
      
      count--;
      return;
    }
  else     //not last/1st item in list
    {
      //move current to next node and delete current
      Node *temp;
      temp = current;
      current = current->next; //current is next
      current->prev = temp->prev; //currents prev is moved nodes prev
      temp->prev->next = current; //prev nodes next is reset to current
      delete temp;
      temp = NULL;
      count--;
    }
}

void List::replace(string key,Item value)
{
  current->item = value;
  current->key = key;
  
}
bool List::empty()//true if empty
{
  if(count == 0)
    return true;
  else
    return false;
}
//returns -1 if not in list, returns list pos if is in list

int List::contains(string key) 
{
  int tmpCurrent = currentPos;
  first();
  Node *tmp; //move current to 1st
  tmp = current;
  int cnt = 0;
  while(tmp != NULL)
    {
     
      if(tmp->key == key)
	{
	  tmp->item.count++;
	  makecurrent(tmpCurrent); //move pointer back
	  //  cout<< cnt << "inside contains " << tmp->key << endl;
	  // cout<< "TRUE" << endl;
	  return cnt;
	}
      tmp = tmp->next;
      cnt++;
    }

  makecurrent(tmpCurrent); //move pointer back
  return -1; 
      
}

void List::display()
{
  //print list
  
  int tmpCurrent = currentPos;
  first();
  Node *tmp; //move current to 1st
  tmp = current;
  int cnt = 0;
  while(tmp != NULL)
    {
      cout<< cnt << " " << tmp->key << endl;
      tmp = tmp->next;
      cnt++;
    }

  makecurrent(tmpCurrent); //move pointer back
  cout << " CURRENT POS IS: " << currentPos << endl;
  cout<< " current: " << current->key <<endl;
}
