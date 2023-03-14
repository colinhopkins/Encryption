CC = gcc
CFLAGS = -Wall -std=c18 -ggdb
KEY="mykeycolinhopkins"
KEY2="mykeycolinhopkins"

test : encode decode test.txt
	./encode ${KEY} <test.txt >test_encode.txt
	cat test_encode.txt
	./decode ${KEY2} <test_encode.txt >test_decode.txt
	diff -i test.txt test_decode.txt
	
	
clean :
	-rm encode decode
	-rm test_encode.txt test_decode.txt
