FLAGS= -Wall -Wextra -Werror -pedantic -g
OBJS=linked-list.o
BINS=tests

tests: tests.c  $(OBJS)
	cc -Wall -Wextra -pedantic -g -o tests tests.c $(OBJS)

linked-list.o:
	cc $(FLAGS) -c linked-list.c

clean:
	rm $(OBJS) $(BINS)
