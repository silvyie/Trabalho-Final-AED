CC = gcc
CFLAGS = -Wall -g
LIBS = -lm

# arquivos-fonte
SRCS = main.c lista.c tartaruga.c vilao.c arsenal.c pilha.c fila.c arvore_vilao.c missao.c

# arquivos objeto
OBJS = main.o lista.o tartaruga.o vilao.o arsenal.o pilha.o fila.o arvore_vilao.o missao.o

# nome do executável
EXEC = programa

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBS)

main.o: main.c tartaruga.h vilao.h arsenal.h lista.h pilha.h fila.h arvore_vilao.h missao.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

tartaruga.o: tartaruga.c tartaruga.h
	$(CC) $(CFLAGS) -c tartaruga.c

vilao.o: vilao.c vilao.h
	$(CC) $(CFLAGS) -c vilao.c

arsenal.o: arsenal.c arsenal.h
	$(CC) $(CFLAGS) -c arsenal.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

arvore_vilao.o: arvore_vilao.c arvore_vilao.h vilao.h
	$(CC) $(CFLAGS) -c arvore_vilao.c

missao.o: missao.c missao.h
	$(CC) $(CFLAGS) -c missao.c

clean:
	rm -rf *.o *~ $(EXEC)
