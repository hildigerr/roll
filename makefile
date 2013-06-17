CC = gcc
CFLAGS = -Wall

roll: diceroller.o
	${CC} -g -o ${@} diceroller.o

man:
	gzip -c roll.6 > roll.6.gz

all: roll man

clean:
	rm diceroller.o

install: roll man
	@ mv roll /usr/games/ ; mv roll.6.gz /usr/share/man/man6/

uninstall:
	@ rm /usr/games/roll ; rm /usr/share/man/man6/roll.6.gz