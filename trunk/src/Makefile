all:
	bison normeantisismiche.yy
	g++ -L Main.cpp normeantisismiche.tab.cc -o earthquake
	
clean:
	rm -rf normeantisismiche.tab.cc normeantisismiche.tab.hh location.hh position.hh stack.hh
	rm -rf earthquake
