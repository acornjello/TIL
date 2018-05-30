#include <iostream>
#include <vector>
using namespace std;

struct pos {
	int x, y;
};
struct Dragon{
	vector<pos> body;
	pos tail;
};
pos rotate(pos p, pos std) {
	pos np;
	np.x = -p.y + std.y + std.x;
	np.y = p.x - std.x + std.y;
	return np;
}

int main() {
	int T, x, y, d, g;
	int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
	bool checked[101][101];

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			checked[i][j] = false;

	cin >> T;
	
	while (T--) {
		cin >> x >> y >> d >> g;

		Dragon dragon;
		
		dragon.tail = { x + dx[d], y + dy[d] };
		dragon.body.push_back( { x, y } );
		dragon.body.push_back( dragon.tail );
		checked[y][x] = true;
		checked[dragon.tail.y][dragon.tail.x] = true;

		while (g-- > 0) {
			int dSize = dragon.body.size();
			for (int i = dSize - 1; i >= 0 ; --i) {
				pos cur = dragon.body[i];
				pos newPos = rotate(cur, dragon.tail);
				dragon.body.push_back( newPos );
				checked[newPos.y][newPos.x] = true;
			}
			dragon.tail = dragon.body[dragon.body.size()-1];
			
		}

	}
	
	int tx[4] = { 0, 1, 0, 1 }, ty[4] = { 0, 0, 1, 1 };
	int ans = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			int isAllChecked = true;
			for (int k = 0; k < 4; k++) {
				if ( !checked[i + ty[k]][j + tx[k]] )
					isAllChecked = false;
			}
			if (isAllChecked)
				ans++;
		}
	}

	cout << ans;

	return 0;
}