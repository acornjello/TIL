#include<iostream>
#include<algorithm>
using namespace std;


// divide conquer
// �������� ����ִ°��� ������ �˾Ƴ��� ���� �߿�
// Ʈ�� �����, �簢���� ũ�Ⱑ ������
// �����ؾ��Ѵ� ���� : ����ũ��, left, right, ����
// log n���� ���̷���? 


// structur�� ���� ũ�⳪Ÿ���� point 2��
/*
color enum
paper* left, right => null�� �ʱ�ȭ
�ڽĿ��� right�� ������ �ñ��Ҷ� : �θ��� right �� right

��ǥ���־����� �켱 ����ִ��� �˾ƾ��� => �θ��� ��� �ִ���. �θ��� �ڽ��� �ִ����� Ȯ��

@ paper / �ڸ��� ģ�� / ��� ��� �湮
*/

int area_min = 40000*40000, area_max = 0;
enum Color { white, black };

struct Paper {
	int x1, y1, x2, y2;
	Paper* left;
	Paper* right;
	Color color;

	Paper(int x1, int y1, int x2, int y2, Color color) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;

		this->left = NULL;
		this->right = NULL;
		this->color = color;
	}
};

void cut(Paper* p, int x, int y, Color color) {
	// ���� ���̿� ���Եǳ�
	if (!(x > p->x1 && x < p->x2 && y > p->y1 && y < p->y2)) return;
	
	// �ڽ��� ������ �ڸ���
	// ������ ����
	if (p->left == NULL && p->right == NULL) {
		if (color == white) {
			p->left = new Paper(p->x1, y, p->x2, p->y2, black);
			p->right = new Paper(p->x1, p->y1, p->x2, y, black);
		}
		if (color == black) {
			p->left = new Paper(p->x1, p->y1, x, p->y2, white);
			p->right = new Paper(x, p->y1, p->x2, p->y2, white);
		}
	}
	if(p->left != NULL) cut(p->left, x, y, p->left->color);
	if (p->right != NULL) cut(p->right, x, y, p->right->color);
}

void findMinMax(Paper* p) {
	if (p == NULL) return;

	findMinMax(p->left);
	findMinMax(p->right);
	if (p->left == NULL && p->right == NULL) {
		area_min = min(area_min, (p->x2 - p->x1)*(p->y2 - p->y1));
		area_max = max(area_max, (p->x2 - p->x1)*(p->y2 - p->y1));
	}

}

int main() {

	Paper* parent = NULL;
	int x, y;
	int N;

	cin >> x >> y;
	cin >> N;

	parent = new Paper(0, 0, x, y, white);

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cut(parent, x, y, white);
	}
	findMinMax(parent);
	cout << area_max << " " << area_min << endl;

	return 0;
}