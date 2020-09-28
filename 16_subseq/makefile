all : maxSeq.o	test_subseq.o

maxSeq.o : maxSeq.c
	gcc -c maxSeq.c

test_subseq : test_suq.c maxSeq.c
	gcc -o test_subseq test_subseq.c maxSeq.c
