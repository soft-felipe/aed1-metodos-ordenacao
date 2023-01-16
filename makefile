all: projeto

#Constroi e compila o projeto
projeto: novoGerador.c metodos.h insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c
	gcc -o projeto novoGerador.c insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c

#Apaga o arquivo executavel
clean:
	del projeto.exe

#Executa o projeto
run: projeto
	./projeto