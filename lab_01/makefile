CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -Wextra -DDEBUG
LMFLAG = -lm 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)

$(info $(SRCS))
$(info $(OBJS))

app.exe: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LMFLAG)

/%.o: /%.c
	$(CC) $(CFLAGS) -c -o $@ $< -lm

clean: 
	rm -rf *.o 

.PHONY: clean
