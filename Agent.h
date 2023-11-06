
#ifndef _AGENT_H_
#define _AGENT_H_

// Agent.h

#include "Person.h"

using namespace std;

class Agent : public Person
{
private:
protected:
public:
  Agent(std::string, std::string);
  Agent(std::string, std::string, GPS_DD);
  Agent();

  virtual bool operator==(Agent& another);
  virtual Json::Value dump2JSON();
};

#endif  /* _AGENT_H_ */
