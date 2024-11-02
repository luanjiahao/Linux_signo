.PHONY:all
all:mysignal mytest

mysignal:mysignal.cc
	g++ -o $@ $^ -std=c++11 -g
mytest:mytest.cc
	g++ -o $@ $^ -std=c++11 -g

.PHONY:clean
clean:
	rm -f mysignal mytest