#Windows Makefile

PATHTEMP = ./.temp
PATHSRC = ./src

all: main.o Avaliador.o BuscasLocais.o HeuristicasConstrutivas.o Instancia.o Menu.o Solucao.o
	@g++ $(PATHTEMP)/main.o $(PATHTEMP)/Avaliador.o $(PATHTEMP)/BuscasLocais.o $(PATHTEMP)/HeuristicasConstrutivas.o  $(PATHTEMP)/Instancia.o $(PATHTEMP)/Menu.o $(PATHTEMP)/Solucao.o -o ./bin/tsp.exe

main.o: $(PATHSRC)/main.cpp
	@g++ -c $(PATHSRC)/main.cpp -o $(PATHTEMP)/main.o

Avaliador.o: $(PATHSRC)/Avaliador.cpp
	@g++ -c $(PATHSRC)/Avaliador.cpp -o $(PATHTEMP)/Avaliador.o

BuscasLocais.o: $(PATHSRC)/BuscasLocais.cpp
	@g++ -c $(PATHSRC)/BuscasLocais.cpp -o $(PATHTEMP)/BuscasLocais.o

HeuristicasConstrutivas.o: $(PATHSRC)/HeuristicasConstrutivas.cpp
	@g++ -c $(PATHSRC)/HeuristicasConstrutivas.cpp -o $(PATHTEMP)/HeuristicasConstrutivas.o

Instancia.o: $(PATHSRC)/Instancia.cpp
	@g++ -c $(PATHSRC)/Instancia.cpp -o $(PATHTEMP)/Instancia.o	

Menu.o: $(PATHSRC)/Menu.cpp
	@g++ -c $(PATHSRC)/Menu.cpp -o $(PATHTEMP)/Menu.o	

Solucao.o: $(PATHSRC)/Solucao.cpp
	@g++ -c $(PATHSRC)/Solucao.cpp -o $(PATHTEMP)/Solucao.o	

run:
	@./tsp.exe

go:
	@cls
	@make all
	@make run

clean:
	@del *.exe /q
	@cd .temp && del *.o /q && \
	@cd bin && del *.exe /q && \
	@cls