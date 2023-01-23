all: projeto

#Constroi e compila o projeto
projeto: geraRelatorio.c metodos.h utilitarios.h utilitarios.c insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c
	gcc -o projeto geraRelatorio.c utilitarios.c insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c

#Apaga o arquivo executavel
clean:
	del projeto.exe

#Executa o projeto
run: projeto
	./projeto

#Testes
test: testMain.c test.h metodos.h utilitarios.h bucket_sort.h utilitarios.c testMetodos.c testUtilitarios.c insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c
	gcc -o test testMain.c testUtilitarios.c testMetodos.c testBucket.c utilitarios.c insertion_sort.c selection_sort.c bubble_sort.c quick_sort.c merge_sort.c radix_sort.c bucket_sort.c counting_sort.c
	./test