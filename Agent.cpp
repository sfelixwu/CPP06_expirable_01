
#include "Agent.h"

Agent::Agent(std::string arg_SSN, std::string arg_name)
  : Person { arg_SSN, arg_name }
{
}

Agent::Agent(std::string arg_SSN, std::string arg_name, GPS_DD arg_home)
  : Person { arg_SSN, arg_name, arg_home }
{
}

Agent::Agent()
{
}

// function prototype
bool
Agent::operator==
(Agent& another)
{
  return true;
}

Json::Value
Agent::dump2JSON
()
{
  Json::Value result = this->Person::dump2JSON();
  
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  
  return result;
}
