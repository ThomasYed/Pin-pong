#include <stdio.h>

void draw(int ball_x, int ball_y, int right_rocket, int left_rocket, int score1, int score2);

int main() {
    int P1_score = 0, P2_score = 0;
    char key_input;
    int ball_Y = 13, ball_X = 40;
    int ball_dx = 1, ball_dy = 1;
    int left_rac_Y = 13, right_rac_Y = 13;

    draw(ball_X, ball_Y, right_rac_Y, left_rac_Y, P1_score, P2_score);

    while (1) {
        if (P1_score == 21) {
            printf("Игрок 1 ВЫИГРАЛ!");
            return 0;
        }
        if (P2_score == 21) {
            printf("Игрок 2 ВЫИГРАЛ!");
            return 0;
        }
        while (1) {
            scanf("%c", &key_input);
            if (key_input == 'a' || key_input == 'z' || key_input == 'k' || key_input == 'm' ||
                key_input == ' ' || key_input == 'q') {
                if (key_input == 'q') {
                    printf("Игра завершена досрочно! Счёт %d : %d", P1_score, P2_score);
                    return 0;
                }
                break;
            }
        }

        if (key_input == 'a' && left_rac_Y < 24) {
            left_rac_Y += 1;
        } else if (key_input == 'z' && left_rac_Y > 2) {
            left_rac_Y -= 1;
        } else if (key_input == 'k' && right_rac_Y < 24) {
            right_rac_Y += 1;
        } else if (key_input == 'm' && right_rac_Y > 2) {
            right_rac_Y -= 1;
        }

        if (ball_X == 1) {
            P2_score += 1;
            ball_Y = 15;
            ball_X = 40;
            ball_dx = 1;
            ball_dy = -1;
        }
        if (ball_X == 80) {
            P1_score += 1;
            ball_Y = 15;
            ball_X = 40;
            ball_dx = -1;
            ball_dy = -1;
        }
        if (ball_Y == 1 || ball_Y == 25) {
            if (ball_dx == 1 && ball_dy == 1) {
                ball_dx = 1;
                ball_dy = -1;
            } else if (ball_dx == 1 && ball_dy == -1) {
                ball_dx = 1;
                ball_dy = 1;
            } else if (ball_dx == -1 && ball_dy == -1) {
                ball_dx = -1;
                ball_dy = 1;
            } else if (ball_dx == -1 && ball_dy == 1) {
                ball_dx = -1;
                ball_dy = -1;
            }
        }
        if (ball_X == 4 && (ball_Y == left_rac_Y || ball_Y == left_rac_Y - 1 || ball_Y == left_rac_Y + 1)) {
            if (ball_dx == -1 && ball_dy == 1) {
                ball_dx = 1;
                ball_dy = 1;
            }
            if (ball_dx == -1 && ball_dy == -1) {
                ball_dx = 1;
                ball_dy = -1;
            }
        } else if (ball_X == 77 &&
                   (ball_Y == right_rac_Y || ball_Y == right_rac_Y - 1 || ball_Y == right_rac_Y + 1)) {
            if (ball_dx == 1 && ball_dy == 1) {
                ball_dx = -1;
                ball_dy = 1;
            }
            if (ball_dx == 1 && ball_dy == -1) {
                ball_dx = -1;
                ball_dy = -1;
            }
        }
        ball_X += ball_dx;
        ball_Y += ball_dy;

        draw(ball_X, ball_Y, right_rac_Y, left_rac_Y, P1_score, P2_score);
    }
}

void draw(int ball_x, int ball_y, int right_rocket, int left_rocket, int score1, int score2) {
    ball_y = 26 - ball_y;
    left_rocket = 26 - left_rocket;
    right_rocket = 26 - right_rocket;

    for (int i = 0; i <= 38; i++) printf(" ");
    printf("SCORE\n");
    for (int i = 0; i <= 38; i++) printf(" ");
    printf("%d : %d\n\n", score1, score2);
    for (int y = 0; y <= 26; y++) {
        for (int x = 0; x <= 81; x++) {
            if ((x == 0 || x == 81)) {
                printf("#");
            } else if (y == 0 || y == 26) {
                printf("|");
            } else if (x == ball_x && y == ball_y) {
                printf("O");
            } else if (x == 3) {
                if (y == left_rocket - 1 || y == left_rocket || y == left_rocket + 1) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else if (x == 78) {
                if (y == right_rocket - 1 || y == right_rocket || y == right_rocket + 1) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else
                printf(" ");
        }
        printf("\n");
    }
    return;
}
