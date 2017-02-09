CC=g++


all: trig.cpp fractions.cpp
	$(CC) trig.cpp -o trig
	$(CC) fractions.cpp -o fractions