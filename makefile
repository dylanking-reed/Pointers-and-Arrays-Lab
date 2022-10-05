FLAGS= -Wall -Wextra -Werror -pedantic -g
OBJS=linked-list.o removing-odds.o finding-a-character.o copying-a-string.o
BINS=tests

tests: tests.c  $(OBJS)
	cc -Wall -Wextra -pedantic -g -o tests tests.c $(OBJS)

linked-list.o:
	cc $(FLAGS) -c linked-list.c

removing-odds.o:
	cc $(FLAGS) -c removing-odds.c

finding-a-character.o:
	cc $(FLAGS) -c finding-a-character.c


copying-a-string.o:
	cc $(FLAGS) -c copying-a-string.c

clean:
	rm $(OBJS) $(BINS)
