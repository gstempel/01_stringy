strtest: myStrings.c
	gcc myStrings.c -o strtest

run: strtest
	./strtest