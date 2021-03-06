#include "BackTrack.h"

void bogle(char (*board)[4] , bool visited[][4], string str,int row, int col, string *dict);
void permut(const char* str, char* res, int *count, int level, int len);
void getIsland(int(*map)[5], int(*visited)[5], int row, int col);
int rowpath[] = { 0,0 ,1,1,-1,1,-1,-1};
int colpath[] = { 1,-1,-1,1,1,0,0,-1 };

//int rowIsland[] = {0,0,-1,1};
//int colIsland[] = { -1,1,0,1 };

void getIsland(int(*map)[5], int(*visited)[5], int row, int col) {
	visited[row][col] = 1;

	for (int i = 0; i < 8; i++) {
		int newRow = row + rowpath[i];
		int newCol = col + colpath[i];

		if ((newRow >= 0 && newRow < 5) && (newCol >= 0 && newCol < 5) && (!visited[newRow][newCol]) && map[newRow][newCol]) {
			getIsland(map, visited, newRow, newCol);
		}
	}
}

void bogle(char(*board)[4], bool visited[][4], string str, int row, int col, string *dict) {

	for (int i = 0; i < 8; i++) {
		if (str.compare(dict[i]) == 0) {
			cout << "Matched " << str << endl;
			break;
		}
	}

	if (15 == str.size()) {
		return;
	}

	for (int i = 0; i < 7; i++) {
		int newRow = row + rowpath[i];
		int newCol = col + colpath[i];

		if ((newRow >= 0 && newRow <= 3) && (newCol >= 0 && newCol <= 3) && !visited[newRow][newCol]) {
			visited[newRow][newCol] = true;
			bogle(board, visited, str + board[newRow][newCol], newRow, newCol, dict);
			visited[newRow][newCol] = false;
		}
	}
}

void permut(const char* str, char* res, int *count, int level, int len) {
	if (level == len) {
		for (int i = 0; i < len; i++) {
			cout << res[i];
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (count[i] == 0)
				continue;

			res[level] = str[i];
			count[i]--;
			permut(str, res, count, level + 1, len);
			count[i]++;
		}
	}
}

void Backtrack::Boogle() {

	//Board board(4, 4);
	string Dictionary[] = { "SUPER", "KEY", "TORN" , "HPUR" , "SIPE", "HIPS", "LET", "DLUN" };

	char board[4][4] = { {'D', 'G', 'H', 'I'},
				  {'K', 'L', 'P', 'S'},
				  {'Y', 'E', 'U', 'T'},
				  {'E', 'O', 'R', 'N'} };

	bool visited[4][4] = { 0 };
	string str;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			visited[i][j] = true;
			bogle(board, visited, str + board[i][j] , i , j , Dictionary);
			visited[i][j] = false;
		}
	}
}



void Backtrack::PermutationofString(const char* str) {
	int len = strlen(str);
	int *count = (int*)malloc(sizeof(int) * len);
	char *res = (char*)malloc(sizeof(char) * len + 1);
	memset(res, 0, sizeof(char) * len + 1);
	memset(count, 0, sizeof(int) * len);

	for (int i = 0; i < len; i++)
		count[i] = 1;

	permut(str, res, count, 0, len);
}

void Backtrack::numberOfislands() {
	int map[5][5] = { { 1, 1, 0, 0, 0 },
					  { 0, 1, 0, 0, 1 },
					  { 1, 0, 0, 1, 1 },
					  { 0, 0, 0, 0, 0 },
	                  { 1, 0, 1, 0, 1 }
	                };
	int visited[5][5] = { 0 };
	int count = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//visited[i][j] = 1;
			if (map[i][j] && !visited[i][j]) {
				getIsland(map, visited, i, j);
				count++;
			}
		}
	}

	cout << "Number of islands are " << count << endl;
}

bool isqueenSafe(int (*board)[8], int row, int col, int n) {

	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; j >= 0 && i >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < n; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool nqueenutil(int n, int (*board)[8], int col) {
	if (col >= n) {
		return true;
	}

	for (int i = 0; i < n; i++) {

		if (isqueenSafe(board, i, col, n)) {

			board[i][col] = 1;

			if (nqueenutil(n, board, col + 1))
				return true;

			board[i][col] = 0;
		}
		
	}
	return false;
}

void Backtrack::Nqueen(int n) {
	
	int board[8][8] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } };
	//memset(board, 0, sizeof(n*n));

	if (nqueenutil(n, board, 0) == false)
		cout << "solution does not exist" << endl;

}
