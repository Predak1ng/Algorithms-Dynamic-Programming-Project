#include <iostream>

using namespace std;

class node {
public:
    int value;
    string choice;
};

int main() {
    int n;
    static int logs[2001];
    static node table[2001][2001];
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        logs[i] = temp;
    }

    for(int x = 1; x <= n; x++) {
        table[x][x].value = logs[x];
        table[x][x].choice = "end";
        if (x != n) {
            if (logs[x] >= logs[x + 1]) {
                table[x][x + 1].value = logs[x];
                table[x][x + 1].choice = "left";
            }
            else {
                table[x][x + 1].value = logs[x + 1];
                table[x][x + 1].choice = "right";
            }
        }
    }
    int y;
    int half_1;
    int half_2;
    for(int k = 3; k <= n; k++) {
        y = 1;
        for(int z = k; z <= n; z++) {
            half_1 = min(table[y + 2][z].value, table[y + 1][z - 1].value);
            half_2 = min(table[y + 1][z - 1].value, table[y][z - 2].value);
            if ((logs[y] + half_1) >= (logs[z] + half_2)) {
                table[y][z].value = logs[y] + half_1;
                table[y][z].choice = "left";
            }
            else {
                table[y][z].value = logs[z] + half_2;
                table[y][z].choice = "right";
            }
            y++;
        }
    }

    cout << table[1][n].value << endl;

    int l = 1;
    int r = n;
    while(true) {
        if (table[l][r].choice == "end") {
            cout << l << endl;
            break;
        }
        else if (table[l][r].choice == "left") {
            cout << l << " ";
            l++;
        }
        else if (table[l][r].choice == "right") {
            cout << r << " ";
            r--;
        }
    }

    return 0;
}
