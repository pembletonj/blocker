CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lSDL2

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

.PHONY : all clean install

all : blocker

clean :
	rm blocker || true
	rm *.o || true

install : blocker
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 blocker $(DESTDIR)$(PREFIX)/bin/

blocker : main.o key_states.o spawner.o entity.o block.o player.o hud.o enemy.o game_utils.o
	$(CXX) main.o key_states.o spawner.o entity.o block.o player.o hud.o enemy.o game_utils.o $(CXXFLAGS) $(LDFLAGS) -o blocker

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

key_states.o : key_states.cpp
	$(CXX) $(CXXFLAGS) -c key_states.cpp

spawner.o : spawner.cpp
	$(CXX) $(CXXFLAGS) -c spawner.cpp

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