
#ifndef _EXPIRABLE_H_
#define _EXPIRABLE_H_

// Expiration.h

#include "Thing.h"
#include "JvTime.h"

#include "ecs36b_Common.h"
using namespace std;

class Expirable : public Thing
{
 private:
 protected:
 public:

  JvTime      * expiration;
  
  Expirable(void);

  virtual bool operator==(const Thing& another);
  virtual Json::Value dump2JSON();
};

#endif /* _EXPIRABLE_H_ */
