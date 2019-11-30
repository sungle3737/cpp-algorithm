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
	// char 'o' �̸� �������ְ�, 'x'�̸� ������, q�̸� �� �ִ°�
	char board[size][size];
	init_board(board);

	// �ʱⰪ ���� �κ�
	check(board, 5, 5);
	// check(board, 2, 3); ������ ���� ���� ����


	// ��� �κп��� recursive �����غ���
	print_board(board);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			char temp_board[size][size];
			coping(board, temp_board);
			recursive(temp_board, i, j);
		}
}

void recursive(char board[][size], int x, int y) {
	// �� �� ������ return
	if (board[x][y] != 'o')
		return;
	
	// �� �Ǵ� �� �����
	check(board, x, y);
	print_board(board);

	// �Ǵ� �� ã��
	for (int i = x; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] == 'o') {
				// board ���� �ؾ��ϴϱ� ���� �� �Լ��� ������
				char temp_board[size][size];
				coping(board, temp_board);
				recursive(temp_board, i, j);
			}
	// �Լ� �ѹ� �����ٴ� �� �����·� ���ư� �ǹ��ϹǷ� queen ���� ���̱�
	temp_max -= 1;
}


void check(char board[][size], int x, int y) {
	if (board[x][y] == 'o')
		board[x][y] = 'q';
	else
		return;
	// �� �Ѱ� ���Ҵٴ� �ǹ��̹Ƿ� +1
	temp_max += 1;

	// ������ ���� ����
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] == 'o')
				if (i == x || j == y || (abs(i - x) == abs(j - y)))
					board[i][j] = 'x';
}

// �� �ִ� ���� �þ ���� �Ȱ��� ���� ���
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

// ���� �� 'o'
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
