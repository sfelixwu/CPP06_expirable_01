
#include "Consumable.h"

Consumable::Consumable
(void)
{
  this->holder = (Person *) NULL;
  this->remaining = 1.0;
}

bool
Consumable::operator==
(const Thing& another)
{
  std::cout << "Consumable::operator == was called\n";
  return true;
}

Json::Value
Consumable::dump2JSON
()
{
  // std::cout << "Consumable::dump2JSON() called\n";
  Json::Value result = this->Expirable::dump2JSON();
  return result;
}
