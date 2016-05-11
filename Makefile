NAME = hexsweeper
OBJS = hexsweeper.o hexbutton.o hexgrid.o

CFLAGS = `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

all: $(OBJS)
	gcc $(LDFLAGS) -o $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS) $(NAME)
