#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//Rat in maze - nXn , nXm
//number of islands - nXn , nXm
//Boogle - board:nXn, nXm , Dictoinary : [];
//N queen - nXn
//String Permutation
//Knight Tour problem nXn
//

class Backtrack {
public:
	static void Boogle();
	static void PermutationofString(const char* str);
	static void numberOfislands();
	static void Nqueen(const int n);
};
