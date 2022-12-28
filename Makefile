CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lSDL2

all : blocker

blocker : main.o key_states.o entity.o block.o player.o hud.o enemy.o game_utils.o
	$(CXX) main.o key_states.o entity.o block.o player.o hud.o enemy.o game_utils.o $(CXXFLAGS) $(LDFLAGS) -o blocker

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

key_states.o : key_states.cpp
	$(CXX) $(CXXFLAGS) -c key_states.cpp

entity.o : entity.cpp
	$(CXX) $(CXXFLAGS) -c entity.cpp

block.o : block.cpp
	$(CXX) $(CXXFLAGS) -c block.cpp

player.o : player.cpp
	$(CXX) $(CXXFLAGS) -c player.cpp

hud.o : hud.cpp
	$(CXX) $(CXXFLAGS) -c hud.cpp

enemy.o : enemy.cpp
	$(CXX) $(CXXFLAGS) -c enemy.cpp

game_utils.o : game_utils.cpp
	$(CXX) $(CXXFLAGS) -c game_utils.cpp

clean :
	rm blocker || true
	rm *.o || true