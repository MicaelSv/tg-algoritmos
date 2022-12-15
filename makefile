all:
	bellmanford.exe
	dijkstra.exe
	prim.exe
	kruskal.exe

bellmanford.exe: bellmanford.cpp
	g++ -o bellmanford.exe bellmanford.cpp

dijkstra.exe:	dijkstra.cpp
	g++ -o dijkstra.exe dijkstra.cpp

prim.exe:	prim.cpp
	g++ -o prim.exe prim.cpp

kruskal.exe: kruskal.cpp
	g++ -o kruskal.exe kruskal.cpp