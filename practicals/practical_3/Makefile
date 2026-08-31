# Dian le Roux (25147065)
# Marko de Swardt (24658562)
# Jay Macaskill (25198387)

# COS 214 (Software Modelling) Practical 3
# Last Modified: 30 August 2026

# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = eventflow

SOURCES = main.cpp EventComponent.cpp EventUnit.cpp EventGroup.cpp Subject.cpp Observer.cpp ControlDesk.cpp GameFest.cpp MainHall.cpp MainStage.cpp TicketGate.cpp RetroCorner.cpp ArcadeRow.cpp TournamentWing.cpp Queue.cpp eSportsArena.cpp VendorHall.cpp MerchStall.cpp DemoStation.cpp CosplayCorner.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run