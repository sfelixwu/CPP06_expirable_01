#include "Thing.h"

void
myPrintLog
(std::string content, std::string fname)
{
  if (fname.size() == 0) return;
  
  FILE *log_f = fopen(fname.c_str(), "a");
  if (log_f == NULL) return;
  
  JvTime *jv_ptr = getNowJvTime();
  std::string *str_ptr = jv_ptr->getTimeString();
  fprintf(log_f, "[%s] %s\n", str_ptr->c_str(), content.c_str());
  delete str_ptr;
  delete jv_ptr;
  fflush(log_f);
  fclose(log_f);
  return;
}

Thing::Thing
(void)
{
  this->sequence_num = 0;
  this->holder = NULL;
}

Thing::Thing
(Person * arg_holder)
{
  this->sequence_num = 0;
  this->holder = arg_holder;
}

bool
Thing::operator==
(const Thing& another)
{
  std::cout << "Thing::operator == was called\n";
  return true;
}

Json::Value
Thing::dump2JSON
()
{
  // std::cout << "Thing::dump2JSON() called\n";
  
  Json::Value result;
  if (this->sequence_num != 0)
    {
      result["sequence number"] = this->sequence_num;
    }

  if (this->holder != NULL)
    {
      result["holder"] = (this->holder)->dump2JSON();
    }

  result["description"] = this->description;
  
#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}
