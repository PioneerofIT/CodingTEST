
#include <iostream>
#include<string>
using namespace std;

enum { U = 0, D, F, B, L, R };
char cube[6][3][3];

void rotateSelfCW(int f) {
    char t[3][3];
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            t[c][2 - r] = cube[f][r][c];
    memcpy(cube[f], t, sizeof(t));
}

void rotateCW(char face) {
    if (face == 'U') {
        // F0 -> R0 -> B0 -> L0 (B는 뒤집힘)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[F][0][i];

        for (int i = 0; i < 3; i++) cube[F][0][i] = cube[L][0][i];
        for (int i = 0; i < 3; i++) cube[L][0][i] = cube[B][0][2 - i];
        for (int i = 0; i < 3; i++) cube[B][0][2 - i] = cube[R][0][i];
        for (int i = 0; i < 3; i++) cube[R][0][i] = tmp[i];

        rotateSelfCW(U);
    }
    else if (face == 'D') {
        // F2 -> L2 -> B2 -> R2 (B는 뒤집힘)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[F][2][i];

        for (int i = 0; i < 3; i++) cube[F][2][i] = cube[R][2][i];
        for (int i = 0; i < 3; i++) cube[R][2][i] = cube[B][2][2 - i];
        for (int i = 0; i < 3; i++) cube[B][2][2 - i] = cube[L][2][i];
        for (int i = 0; i < 3; i++) cube[L][2][i] = tmp[i];

        rotateSelfCW(D);
    }
    else if (face == 'F') {
        // U2 -> R col0 -> D0 -> L col2  (여기 reverse 위치가 핵심)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[U][2][i];

        for (int i = 0; i < 3; i++) cube[U][2][i] = cube[L][2 - i][2];
        for (int i = 0; i < 3; i++) cube[L][i][2] = cube[D][0][i];
        for (int i = 0; i < 3; i++) cube[D][0][i] = cube[R][2 - i][0];
        for (int i = 0; i < 3; i++) cube[R][i][0] = tmp[i];

        rotateSelfCW(F);
    }
    else if (face == 'B') {
        // U0 -> L col0 -> D2 -> R col2  (reverse 위치 핵심)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[U][0][i];

        for (int i = 0; i < 3; i++) cube[U][0][i] = cube[R][i][2];
        for (int i = 0; i < 3; i++) cube[R][i][2] = cube[D][2][2 - i];
        for (int i = 0; i < 3; i++) cube[D][2][i] = cube[L][i][0];
        for (int i = 0; i < 3; i++) cube[L][i][0] = tmp[2 - i];

        rotateSelfCW(B);
    }
    else if (face == 'L') {
        // U col0 -> F col0 -> D col0 -> B col2 (B쪽 reverse)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[U][i][0];

        for (int i = 0; i < 3; i++) cube[U][i][0] = cube[B][2 - i][2];
        for (int i = 0; i < 3; i++) cube[B][2 - i][2] = cube[D][i][0];
        for (int i = 0; i < 3; i++) cube[D][i][0] = cube[F][i][0];
        for (int i = 0; i < 3; i++) cube[F][i][0] = tmp[i];

        rotateSelfCW(L);
    }
    else if (face == 'R') {
        // U col2 -> B col0 -> D col2 -> F col2 (B쪽 reverse)
        char tmp[3];
        for (int i = 0; i < 3; i++) tmp[i] = cube[U][i][2];

        for (int i = 0; i < 3; i++) cube[U][i][2] = cube[F][i][2];
        for (int i = 0; i < 3; i++) cube[F][i][2] = cube[D][i][2];
        for (int i = 0; i < 3; i++) cube[D][i][2] = cube[B][2 - i][0];
        for (int i = 0; i < 3; i++) cube[B][2 - i][0] = tmp[i];

        rotateSelfCW(R);
    }
}

void rotateCCW(char face) {
    // 반시계 = 시계 3번
    for (int i = 0; i < 3; i++) rotateCW(face);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string color = "wyrogb";
        for (int f = 0; f < 6; f++)
            for (int r = 0; r < 3; r++)
                for (int c = 0; c < 3; c++)
                    cube[f][r][c] = color[f];

        int n;
        cin >> n;
        while (n--) {
            string cmd;
            cin >> cmd;
            if (cmd[1] == '+') rotateCW(cmd[0]);
            else rotateCCW(cmd[0]);
        }

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) cout << cube[U][r][c];
            cout << '\n';
        }
    }
    return 0;
}
