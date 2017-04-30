SRCS = Graph.cpp Adjlist.cpp TestDriver.cpp MinHeap.cpp
EXEC = test

OBJS = $(SRCS:.C=.o)


$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS)


%.o : %.C
	g++ -std=c++11 -g -Wall -c $<

clean:
	rm -f *.o *~ $(EXEC)



# DO NOT DELETE THIS LINE -- make depend needs it 
