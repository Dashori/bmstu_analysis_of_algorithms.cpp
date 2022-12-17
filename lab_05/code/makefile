.PHONY: run clean

a.out : main.cpp card.cpp genCards.cpp
	g++ -std=c++14 -pthread -o $@ $^

clean:
	rm -rf a.out

