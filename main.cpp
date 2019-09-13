#include<iostream>
#include<LookupTable.h>
#include<string>
#include<fstream>
using namespace std;

//Curtis Chiesa csc390 assignment
		   
Item createItem(string key)
{
  int con = 0;
  int vowel = 0;

  for(int i=0;i<key.length();i++)
    {
      if(key.at(i) == 'a' || key.at(i) == 'e' || key.at(i) == 'i' || key.at(i) == 'o' || key.at(i) == 'u')
	vowel++;
      else
	{
	  con++;
	}
    }

  Item item;
  item.consonants = con;
  item.vowels = vowel;
  item.count = 1;
  return item;

}

 
/*
int main(void)
{
  
  List l;
  Item first = createItem("first");
  Item weather = createItem("weather");
  Item sailing = createItem("sailing");
  Item color = createItem("color");
  //  cout<< first.consonants << first.vowels<<endl;
  l.insertAfter("first", first);
  l.first();
  l.last();
  l.insertAfter("first", first);
  l.insertAfter("first", first);
  l.remove();
  l.insertAfter("first", first);
  cout<< l.examineKey() << endl;
  // l.first();
  l.insertAfter("weather",weather);
  //l.first();
  // cout<< l.examineKey() << endl;
  l.insertAfter("sailing",sailing);
  l.display();
  l.last();
  l.insertAfter("sailing",sailing);
  ////  l.display();
  //l.first();
  //  l.remove();
  cout<< l.examineKey() << l.currentPos <<endl;
  l.insertAfter("color",color);
  l.first();
  l.insertAfter("color",color);
  cout<< l.examineKey()<< endl;
  //l.display();
  l.remove();
  l.remove();
  l.next();
  //l.insertAfter("color",color);
  //l.insertAfter("color",color);
  l.insertAfter("first", first);
  //  cout<<" Last MAIN test" << l.examineKey() << endl;
  // l.first();
  //l.display();
  //l.last();
  l.first();
  l.first();
  // cout<< "  MAIN test 2 " << l.examineKey() << endl;
  
  //cout<< l.examineKey() << endl;

  l.insertAfter("weather",weather);
  //l.first();
 
  //Item item = l.examineItem();
  //cout << item.count <<endl;
  //item.count++;
  //Item item2 = l.examineItem();
  //out << item2.count << endl;
  // l.display();
  l.makecurrent(1);
  l.remove();
  l.display();
  l.next();
  //cout<< l.examineKey() << endl;
  //l.next();
  //cout<<l.examineKey()<<endl;
  //l.prev();
  //cout<<l.examineKey()<<endl;
  
  return 1;
}
*/
 /*
int main(void)
{
   LookupTable table;
   
   table.insert("when", createItem("when"));
   //table.display();
   table.insert("can", createItem("can"));
   // table.display();
   table.insert("sailing", createItem("sailing"));
   // table.display();
   table.insert("weather", createItem("weather"));
   // table.display();
   table.insert("weather", createItem("weather"));
   //table.display();

   Item i = table.retrieve("when");
   cout << "count for when is: " << i.count << endl; // should be 1
   
   i = table.retrieve("weather");
   cout << "count for weather is: " << i.count << endl; // should be 2

   table.remove("weather");

   i = table.retrieve("weather");
   cout << "count for weather is: " << i.count << endl; // should  be 1

   table.display();
   return -1;

}
*/


int  main(void)
{
   LookupTable table;
   
   // READ IN THE LIST OF KEYS HERE…

   ifstream file("words.txt");
   string str;

   while(getline(file,str))
     {
       table.insert(str, createItem(str));
     }

   table.display();
   
   Item i = table.retrieve("when");
   cout << "count for when is: " << i.count << endl; // should be 1

   i = table.retrieve("weather");
   cout << "count for weather is: " << i.count << endl; // should be 5

   table.remove("when");
   table.remove("weather");
  
   
   i = table.retrieve("weather");
   cout << "count for weather is: " << i.count << endl; // should be 4

   table.display();
   return 0;
}


