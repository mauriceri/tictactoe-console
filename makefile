main: main.c tictactoe.o
	gcc -o main main.c tictactoe.o

tictactoe.o: tictactoe.c
	gcc -c tictactoe.c

clean:
	rm main *.o
