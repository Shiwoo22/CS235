###############################################################
# Program:
#     Week 08, Binary Tree
#     Brother JonesL, CS235
# Author:
#     Jeffry Simpson, David Perez
# Summary:
#    Create a class for Binary Tree
#
# Time:
#    Pair programming - 1.5 hours
#	  Jeffry Simpson   - 10.5 hours
#     David Perez     - 4.5 hours
#
# Difficulties:
#    David  - Getting the AddLeft and AddRight done for the tests
#
#    Jeffry - Wrapping my head around how to get the huffman code to work
#             Finally when I pseudo coded it, it took me a long time to get the
#             Vector of Huffman working.   Once I did that, the rest worked well.
#
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week08.o huffman.o
	g++ -o a.out week08.o huffman.o -g
	tar -cf week08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week08.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
week08.o: bnode.h huffman.h week08.cpp
	g++ -std=c++11 -c week08.cpp -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -std=c++11 -c huffman.cpp -g




