all: bfs

# .PHONY: clean

bfs : main.o graphsearch.o queue.o permute.o graph.o bfs.o linkedlisttraversal.o linkedlistresultat.o
	gcc main.o graphsearch.o queue.o permute.o graph.o bfs.o linkedlisttraversal.o linkedlistresultat.o -o graphsearchBin -w

dfs : main.o graphsearch.o stack.o permute.o graph.o bfs.o linkedlisttraversal.o linkedlistresultat.o
	gcc main.o graphsearch.o stack.o permute.o graph.o bfs.o linkedlisttraversal.o linkedlistresultat.o -o graphsearchBin -w

main.o : main.c
	gcc -c main.c -w

graphsearch.o : graphsearch.c
	gcc -c graphsearch.c -w

queue.o : queue.c
	gcc -c queue.c -w

permute.o : permute.c
	gcc -c permute.c -w

graph.o : graph.c
	gcc -c graph.c -w

bfs.o : bfs.c
	gcc -c bfs.c -w

linkedlisttraversal.o : linkedlisttraversal.c
	gcc -c linkedlisttraversal.c -w

linkedlistresultat.o : linkedlistresultat.c
	gcc -c linkedlistresultat.c -w

stack.o : stack.c
	gcc -c stack.c -w

clean : 
	rm -rf *.o && rm graphsearch

run : 
	./graphsearchBin 1-2,1-3,1-5,3-6,3-5,6-6,5-4,2-5,4-2

	

