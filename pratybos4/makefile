
mainProgram: pratybos.o functions.o
	gcc pratybos.o functions.o -o mainProgram
	del *.o
pratybos.o: pratybos.c
	gcc -c pratybos.c
functions.o: functions.c
	gcc -c functions.c
	
asserts: asserts.o functions.o
	gcc asserts.o functions.o -o asserts
	del *.o
asserts.o: asserts.c
	gcc -c asserts.c