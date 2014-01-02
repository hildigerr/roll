CC = gcc
CFLAGS = -Wall

roll: diceroller.c
	${CC} ${CFLAGS} -o ${@} diceroller.c

man:
	gzip -c roll.6 > roll.6.gz

all: roll man

install: all
	@ mv roll ${DESTDIR}/usr/games/ ; mv roll.6.gz ${DESTDIR}/usr/share/man/man6/
