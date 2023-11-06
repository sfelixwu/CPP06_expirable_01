
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

using namespace std;

class Person
{
private:
protected:
public:
  std::string SSN;
  std::string name;
  GPS_DD location;
  
  Person(std::string, std::string);
  Person(std::string, std::string, GPS_DD);
  Person();

  virtual bool operator==(Person& aPerson);
  virtual Json::Value dump2JSON();
};

#endif  /* _PERSON_H_ */
