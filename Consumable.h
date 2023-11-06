
#ifndef _CONSUMABLE_H_
#define _CONSUMABLE_H_

// Consumable.h

#include "Expirable.h"
#include "Person.h"

#include "ecs36b_Common.h"
using namespace std;

class Consumable : public Expirable
{
 private:
 protected:
 public:

  Person     * holder;
  double     remaining;
  
  Consumable(void);

  virtual bool operator==(const Thing&);
  virtual Json::Value dump2JSON();
};

#endif /* _CONSUMABLE_H_ */
