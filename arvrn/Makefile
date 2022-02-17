##############################################################################################
# Originaly written by:	 Welverton Rodrigues da Silva					     #
# Last modified by:	 Elisa Dell'Arriva <e135551@dac.unicamp.br> at 5/22/20		     #
##############################################################################################


###############################################################################################
######################### Compilação com suporte a múltiplos arquivos #########################
###############################################################################################

.PHONY: build clean

LAB = lab

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
GFLAGS  = -std=c99 -Wall -Werror

build: $(OBJECTS)
	gcc $(GFLAGS) *.o -o $(LAB) -lm

%.o: %.c
	gcc $(GFLAGS) -g -c $< -o $@

clean:
	rm -f *.o


###############################################################################################
####################### Suporte para testar o programa usando os testes #######################
###############################################################################################

.PHONY: testar_abertos

testar_abertos:
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "\033[1;31mDiretório 'testes' não encontrado!\033[0m" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*.in ; do \
		echo "\033[1;34mTestando \033[4;34m$$entrada\033[0m" ; \
		saida=$$(echo "$$entrada" | sed -re 's/\.in$$/.out/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\.in$$/.res/' ) ; \
		./$(LAB) < "$$entrada" > "$$saida" ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "\033[1;32mResultado correto!\033[0m" ; \
		else \
			echo "\033[1;31mFalhou!\033[0m" ; \
			echo ""; \
		fi ; \
		echo ; \
	done


###############################################################################################
####################### Suporte para checar vazamento de memória ##############################
###############################################################################################

.PHONY: checar_vazamento

checar_vazamento:
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "\033[1;31mDiretório 'testes' não encontrado!\033[0m" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*.in ; do \
		echo "\033[1;34mTestando \033[4;34m$$entrada\033[0m" ; \
		saida=$$(echo "$$entrada" | sed -re 's/\.in$$/.out/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\.in$$/.res/' ) ; \
		if valgrind -q --leak-check=full ./$(LAB) < "$$entrada" > "$$saida" ;  then \
			echo "\033[1;32mResultado correto!\033[0m" ; \
		else \
			echo "\033[1;31mFalhou!\033[0m" ; \
			exit 1; \
		fi ; \
		echo ; \
	done
