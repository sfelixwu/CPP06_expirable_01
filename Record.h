
#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

class Record
{
private:
protected:
public:
  std::string label;
  std::vector<Person *> who;
  std::vector<Thing *> what;
  GPS_DD * where; 
  JvTime when;
  
  Record();

  void addWho(Person *_p);
  void setWho(std::vector<Person *> _vp);
  void addWhat(Thing *_t);
  void setWhat(std::vector<Thing *> _vt);
  
  void setWhere(GPS_DD *);
  void setWhen(JvTime);
  
  virtual Json::Value dump2JSON();
};

#endif  /* _RECORD_H_ */
