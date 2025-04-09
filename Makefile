
make.x: main.o GraphNode.o DepGraph.o Token.o Tokenizer.o TreeNode.o MakeTree.o systemInterface.o
	g++ -std=c++17 -g main.o DepGraph.o Tokenizer.o GraphNode.o TreeNode.o MakeTree.o systemInterface.o Token.o -o make.x

main.o: main.cpp DepGraph.o
	g++ -std=c++17 -g main.cpp -o main.o -c

GraphNode.o: GraphNode.hpp GraphNode.cpp
	g++ -std=c++17 -g GraphNode.cpp -o GraphNode.o -c

DepGraph.o: DepGraph.cpp DepGraph.hpp MakeTree.o Tokenizer.o systemInterface.o
	g++ -std=c++17 -g DepGraph.cpp -o DepGraph.o -c

Token.o: Token.hpp Token.cpp
	g++ -std=c++17 -g Token.cpp -o Token.o -c

Tokenizer.o: Tokenizer.hpp Tokenizer.cpp Token.o
	g++ -std=c++17 -g Tokenizer.cpp -o Tokenizer.o -c

TreeNode.o: TreeNode.hpp TreeNode.cpp GraphNode.o
	g++ -std=c++17 -g TreeNode.cpp -o TreeNode.o -c

MakeTree.o: MakeTree.hpp MakeTree.cpp TreeNode.o
	g++ -std=c++17 -g MakeTree.cpp -o MakeTree.o -c

systemInterface.o: systemInterface.hpp systemInterface.cpp
	g++ -std=c++17 -g systemInterface.cpp -o systemInterface.o -c

clean:
	rm -f make.x *.o
