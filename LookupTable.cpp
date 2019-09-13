#include<LookupTable.h>
#include<string>
#include<iostream>
using namespace std;

LookupTable::LookupTable()
{
  //constructor
  //declare tableArray
  tableArray = new List[10];
  
  
}

LookupTable::~LookupTable()
{
  //  cout << "LOOKUP descructor" << endl;
  
  delete[] tableArray;
  tableArray = NULL;

  delete tableArray;
  tableArray = NULL;
      
}


//convert Item to int
int LookupTable::hash(string key)
{
  //sum up acsii values and mod by length
  int sum = 0;
  for(int i=0;i<key.length();i++)
    {
      sum = sum + int(key.at(i));
    }
  return sum % 10;
}


Item LookupTable::retrieve(string key)
{
  int pos = hash(key);
  //tableArray[pos];
  //find key in list
  if( !tableArray[pos].empty() )//if list not empty
    {
      //move current to first
      tableArray[pos].first();
      
      string tmp = tableArray[pos].examineKey();
      Item item = tableArray[pos].examineItem();
      while (tmp != key)
	{
	  //move current to next
	  
	  tableArray[pos].next();
	  tmp = tableArray[pos].examineKey();
	  item = tableArray[pos].examineItem();
	}
      if(tmp == key)
	return item;

    }
  else
    {
      cout<< "list empty"<<endl;
    }
}

bool LookupTable::insert(string key,Item value)
{
  int h = hash(key);
  tableArray[h].insertAfter(key,value);
}

bool LookupTable::remove(string key)
{
  //removes one instance on the key
  int h = hash(key);
  //cout<<h<<endl;
  
  tableArray[h].first();
  string str = tableArray[h].examineKey();
  while( str != key )
    {
      tableArray[h].next();
      str = tableArray[h].examineKey();
    }
  
  tableArray[h].remove(); //remove current

}

int LookupTable::numberUnused()
{
  //return num of unused positions in lookup table
  int cnt = 0;

  for(int i=0;i<10;i++)
    {
      if( tableArray[i].empty() )
	{
	  cnt++;
	}
    }

  return cnt;
}

int LookupTable::numberUsed()
{
  return 10 - numberUnused();
}

int LookupTable::minimumCollisions()
{
  //returns smallest num of collisions in any used LookupTable
  int min = 10000000;
  for(int i=0;i<10;i++)
    {
      if(tableArray[i].count < min)
	{
	  min = tableArray[i].count;
	}
    }
  return min; 
}	  

int LookupTable::maximumCollisions()
{
  int max = -1;
   for(int i=0;i<10;i++)
    {
      if(tableArray[i].count > max)
	{
	  max = tableArray[i].count;
	}
    }
  return max; 
}

void LookupTable::display()
{
  //display stats
  cout<< "MIN COLLISIONS: " << minimumCollisions() << endl;
  cout<< "MAX COLLSIONS: " << maximumCollisions() << endl;
  cout<< "NUM OF UNUSED POSITIONS: " << numberUnused() << endl;
  cout<< "NUM OF USED POSITIONS: " << numberUsed() << endl;
}
  

  
