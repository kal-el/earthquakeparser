all:
	bison normeantisismiche.yy
	flex norme.flex
	g++ lex.yy.cc Main.cpp normeantisismiche.tab.cc -o normeantisismiche
	
clean:
	rm -rf .tab.c normeantisismiche.tab.h location.hh position.hh stack.hh
	rm -rf lex.yy.cc
	rm -rf normeantisismiche
