
// test_HW4.cpp

#include "JvTime.h"
#include "Labeled_GPS.h"
#include "Agent.h"
#include "Record.h"
#include "Consumable.h"

int
main
(int argc, char *argv[])
{
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306,
				  "Teaching and Learning Complex" };
  Labeled_GPS gps_Target_Davis  { 38.55430358599457, -121.69974953598044,
				  "Target-Like Store" };
  
  Person Felix { "987654321", "Felix", gps_TLC_UCDavis };
  Agent Target_Like { "987654322", "Target_Like", gps_Target_Davis };

  Consumable beer;
  beer.holder = &Target_Like;
  beer.sequence_num = 1;
  beer.description = "a box of beer";
  
  JvTime beer_jv { "2023-12-31T16:00:00+0000" };
  beer.expiration = &beer_jv;

  Record r1;
  r1.label = "Possession";
  r1.addWho(&Target_Like);
  r1.addWhat(&beer);
  JvTime r1_jv { "2023-11-01T16:00:00+0000" };
  r1.when = r1_jv;
  r1.where = &gps_Target_Davis;
  
  Record r2;
  r2.label = "Detachment";
  r2.addWho(&Target_Like);
  r2.addWhat(&beer);
  JvTime r2_jv { "2023-11-06T16:00:00+0000" };
  r2.when = r2_jv;
  r2.where = &gps_Target_Davis;

  Record r3;
  r3.label = "Possession";
  r3.addWho(&Felix);
  r3.addWhat(&beer);
  JvTime r3_jv { "2023-11-06T16:00:00+0000" };
  r3.when = r3_jv;
  r3.where = &gps_TLC_UCDavis;
  
  Json::Value x;
  x = r1.dump2JSON();
  std::cout << x.toStyledString() << std::endl;
  x = r2.dump2JSON();
  std::cout << x.toStyledString() << std::endl;
  x = r3.dump2JSON();
  std::cout << x.toStyledString() << std::endl;
  
  return 0;
}
