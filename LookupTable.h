#include<list.h>

class LookupTable
{
   private:
      List *tableArray;   // maximum of 10 slots

   public: 
      LookupTable(); // constructor
      ~LookupTable(); // destructor

      Item retrieve(string key); 
      bool insert(string key, Item value);
      bool remove(string key); // removes one instance of the key
      int numberUnused(); // returns number unused positions in lookupTable
      int numberUsed(); // returns number used positions in lookupTable
      int minimumCollisions(); // returns smallest number of collisions in any used lookupTable
  int maximumCollisions(); // returns largest number of collisions in any used lookupTable position
      void display(); // displays the contents of the table at each position, plus table statistics (numberUnused, numberUsed, minimumCollisiosn, maximumCollisions)
  int hash(string key);
};
