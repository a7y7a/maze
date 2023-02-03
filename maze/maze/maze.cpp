#include <iostream>
using namespace std;
#include<vector>
#include<stack>

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<int>> v(a, vector<int>(b, 0));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> v[i][j];
            }
        }
        int x = 0, y = 0;
        stack<int> sx, sy, swx, swy, swd, sway, swalk;
        sx.push(x);
        sy.push(y);
        int direct = 0, way = 0, first = 1, walk = -1;
        while (x != a - 1 || y != b - 1) {
            if (first) {
                way = 0;
                if (x - 1 >= 0 && v[x - 1][y] == 0) {
                    way++;
                    direct = 3;
                }
                if (y - 1 >= 0 && v[x][y - 1] == 0) {
                    way++;
                    direct = 2;
                }
                if (x + 1 < a && v[x + 1][y] == 0) {
                    way++;
                    direct = 1;
                }
                if (y + 1 < b && v[x][y + 1] == 0) {
                    way++;
                    direct = 0;
                }
            }
            else {
                first = 1;
            }
            if (way > 1) {
                swx.push(x);
                swy.push(y);
                swd.push(direct);
                sway.push(way);
                swalk.push(walk);
            }
            switch (direct) {
            case 0: {
                if (y + 1 < b && v[x][y + 1] == 0 && walk != 2) {
                    y++;
                    sx.push(x);
                    sy.push(y);
                    walk = 0;
                    break;
                }
            }
            case 1: {
                if (x + 1 < a && v[x + 1][y] == 0 && walk != 3) {
                    x++;
                    sx.push(x);
                    sy.push(y);
                    walk = 1;
                    break;
                }
            }
            case 2: {
                if (y - 1 >= 0 && v[x][y - 1] == 0 && walk != 0) {
                    y--;
                    sx.push(x);
                    sy.push(y);
                    walk = 2;
                    break;
                }
            }
            case 3: {
                if (x - 1 >= 0 && v[x - 1][y] == 0 && walk != 1) {
                    x--;
                    sx.push(x);
                    sy.push(y);
                    walk = 3;
                    break;
                }
            }
            default: {
                x = swx.top();
                y = swy.top();
                direct = swd.top() + 1;
                way = sway.top() - 1;
                walk = swalk.top();
                swx.pop();
                swy.pop();
                swd.pop();
                sway.pop();
                swalk.pop();
                while (sx.top() != x || sy.top() != y) {
                    sx.pop();
                    sy.pop();
                }
                first = 0;
                break;
            }
            }
        }
        stack<int> si, sj;
        while (!sx.empty()) {
            si.push(sx.top());
            sj.push(sy.top());
            sx.pop();
            sy.pop();
        }
        while (!si.empty()) {
            cout << '(' << si.top() << ',' << sj.top() << ')' << endl;
            si.pop();
            sj.pop();
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")