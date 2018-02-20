CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
//LDFLAGS = -lboost_date_time

OBJS = die.o creature.o voldemort.o trio.o potter.o space.o gryffindor.o secrets.o dada.o prefects.o requirement.o potions.o dumbledore.o hogwarts.o final.o 

SRCS = die.cpp creature.cpp voldemort.cpp trio.cpp potter.cpp space.cpp gryffindor.cpp secrets.cpp dada.cpp prefects.cpp requirement.cpp potions.cpp dumbledore.cpp hogwarts.cpp final.cpp

HEADERS = die.hpp creature.hpp voldemort.hpp trio.hpp potter.hpp space.hpp gryffindor.hpp secrets.hpp dada.hpp prefects.hpp requirement.hpp potions.hpp dumbledore.hpp hogwarts.hpp

final: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm -f *.o a.out final

