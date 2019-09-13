//header file
#include<string>

using namespace std;

struct Item
{
   int consonants; // number of consonants in key
   int vowels;     // number of vowels in key
   int count;      // number of identical keys stored at this location
};

struct Node
{
  //define
  Node *next;
  Node *prev;
  Item item;
  string key;
};

