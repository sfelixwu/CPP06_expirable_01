# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC 	= g++ -std=c++14
CFLAGS 	= -g -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -lcurl -ljsonrpccpp-client

INC_COMMON = ecs36b_Common.h ecs36b_Exception.h
CORE_OBJ = GPS.o Labeled_GPS.o Person.o Agent.o Thing.o Expirable.o Consumable.o Record.o JvTime.o

# rules.
all: 	test_HW4

#
#

Record.o:	Record.cpp Record.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Record.cpp

GPS.o:		GPS.cpp GPS.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) GPS.cpp

Labeled_GPS.o:	Labeled_GPS.cpp Labeled_GPS.h GPS.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Labeled_GPS.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp Person.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Person.cpp

Agent.o:	Agent.cpp Agent.h Person.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Agent.cpp

Thing.o:	Thing.cpp Thing.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Thing.cpp

Expirable.o:	Expirable.cpp Expirable.h Thing.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Expirable.cpp

Consumable.o:	Consumable.cpp Consumable.h Expirable.h Thing.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) Consumable.cpp

test_HW4.o:	test_HW4.cpp GPS.h Thing.h Person.h Expirable.h Consumable.h $(INC_COMMON)
	$(CC) -c $(CFLAGS) test_HW4.cpp

test_HW4:	test_HW4.o $(CORE_OBJ)
	g++ -std=c++14 test_HW4.o $(CORE_OBJ) -o test_HW4 $(LDFLAGS)

clean:
	rm -f *.o *~ core test_HW4


