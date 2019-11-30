#include <iostream>
using namespace std;

#define size 10
void print_board(char board[][size]);
void init_board(char board[][size]);
void recursive(char board[][size], int x, int y);
void check(char board[][size], int x, int y);
void coping(char from[][size], char to[][size]);
char temp_board[size][size];

static int max_queen = 0;
static int temp_max = 0;

int main() {
	// char 'o' 이면 놓을수있고, 'x'이면 못놓고, q이면 퀸 있는곳
	char board[size][size];
	init_board(board);

	// 초기값 설정 부분
	check(board, 5, 5);
	// check(board, 2, 3); 여러개 놓을 수도 잇음


	// 모든 부분에서 recursive 시작해보기
	print_board(board);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			char temp_board[size][size];
			coping(board, temp_board);
			recursive(temp_board, i, j);
		}
}

void recursive(char board[][size], int x, int y) {
	// 둘 수 없으면 return
	if (board[x][y] != 'o')
		return;
	
	// 안 되는 곳 지우기
	check(board, x, y);
	print_board(board);

	// 되는 곳 찾기
	for (int i = x; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] == 'o') {
				// board 재사용 해야하니까 복사 후 함수로 보내기
				char temp_board[size][size];
				coping(board, temp_board);
				recursive(temp_board, i, j);
			}
	// 함수 한번 끝난다는 건 전상태로 돌아감 의미하므로 queen 개수 줄이기
	temp_max -= 1;
}


void check(char board[][size], int x, int y) {
	if (board[x][y] == 'o')
		board[x][y] = 'q';
	else
		return;
	// 퀸 한개 놓았다는 의미이므로 +1
	temp_max += 1;

	// 나머지 보드 변경
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] == 'o')
				if (i == x || j == y || (abs(i - x) == abs(j - y)))
					board[i][j] = 'x';
}

// 퀸 최대 개수 늘어날 때나 똑같을 때만 출력
void print_board(char board[][size]) {
	if (temp_max >= max_queen) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				cout << board[i][j] << "\t";
			cout << "\n" << endl;
		}
		cout << "now max queen is : " << temp_max << "\n\n" << endl;
		max_queen = temp_max;
	}
	return;
}

// 전부 다 'o'
void init_board(char board[][size]) {
	temp_max = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = 'o';
}

void coping(char from[][size], char to[][size]) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			to[i][j] = from[i][j];
}
