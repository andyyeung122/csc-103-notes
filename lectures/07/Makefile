COMMON   := -Wall -g
CFLAGS   := $(CFLAGS) $(COMMON)
CXXFLAGS := $(CXXFLAGS) $(COMMON)
CC       := gcc
CXX      := g++

TARGETS  := vectors capacity-test todos

.PHONY : all
all : $(TARGETS)

$(TARGETS) : % : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : clean
clean :
	rm -f $(TARGETS)

# vim:ft=make:foldmethod=marker:foldmarker={{{,}}}
