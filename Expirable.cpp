
#include "Expirable.h"

Expirable::Expirable
(void)
{
}

bool
Expirable::operator==
(const Thing& another)
{
  std::cout << "Expirable::operator == was called\n";
  return true;
}

Json::Value
Expirable::dump2JSON
()
{
  // std::cout << "Expirable::dump2JSON() called\n";
  Json::Value result = this->Thing::dump2JSON();
  result["expiration"] = (this->expiration)->dump2JSON();
  return result;
}
