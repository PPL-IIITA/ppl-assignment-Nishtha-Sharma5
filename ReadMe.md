#PPL Assignment Nishtha-Sharma5
##Created by Nishtha Sharma (LIT2015039) Section-B

#TO CREATE LIBRARY FILE

g++ -c random.cpp
g++ -c CoupleFormatio.cpp
g++ -c collection.cpp
g++ -c random_gifts.cpp

ar rvs MyLib.a random.o CoupleFormation.o collection.o random_gifts.o 

###Commands to build and run the project :-

g++ random.cpp
./a.out
g++ Ques1.cpp CoupleFormation.cpp
./a.out

##Output of Question 1 in file "Output1.txt"

g++ random_gifts.cpp
./a.out
g++ Ques2.cpp collection.cpp
./a.out

#Ouput of Question 2 in "Output.txt"

##System Information

Operting System: Ubuntu(14.04)
Text Editor: Gedit
Documentation Software: Doxygen
UML Software: Star UML

