CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
LDFLAGS = -lncurses

SRC = src/main.cpp src/cpu.cpp src/mem.cpp src/ui.cpp

leafmon:
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o leafmon

install:
	install -Dm755 leafmon $(DESTDIR)/usr/bin/leafmon

clean:
	rm -f leafmon
