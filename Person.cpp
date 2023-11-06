
#include "Person.h"

Person::Person(std::string arg_SSN, std::string arg_name)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
}

Person::Person(std::string arg_SSN, std::string arg_name, GPS_DD arg_location)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
  this->location = arg_location;
}

Person::Person()
{
  this->SSN = "";
  this->name = "";
}

// function prototype
bool
Person::operator==
(Person& aPerson)
{
  return ((this->name == aPerson.name) &&
	  (this->SSN == aPerson.name));
}

Json::Value
Person::dump2JSON
()
{
  Json::Value result;
  if (this->name != "")
    {
      result["name"] = this->name;
    }

  if (this->SSN != "")
    {
      result["SSN"] = this->SSN;
    }

  result["location"] = (this->location).dump2JSON();
  
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}
