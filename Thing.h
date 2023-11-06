
#ifndef _THING_H_
#define _THING_H_

// Thing.h
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"
using namespace std;

class Thing
{
 private:
 protected:
 public:
  
  std::string description;
  unsigned int sequence_num;
  Person      * holder;
  JvTime      purchased;
  JvTime      sold;
  GPS_DD      * location;
  
  Thing(void);
  Thing(Person * arg_holder);
  virtual bool operator==(const Thing& another);
  virtual Json::Value dump2JSON();
};

#endif /* _THING_H_ */
