/* #include <stdio.h>

void display_star_pattern(int height) {
    printf("\nHeight : %d  \n\n", height);

    int i = 0, j = 0;
    int point_a1 = height + height / 2;
    int point_a2 = point_a1;
    int point_b1 = height + height + (height / 2) + 2;
    int point_b2 = height / 2 - 2;

    for (i = 0; i < height; i++) {
        if (i >= (height + 1) / 3) {
            point_b1 = point_b1 - 3;
            point_b2 = point_b2 + 3;
        }

        for (j = 0; j < height * 3; j++) {
            if (j == point_a1 || j == point_a2) {
                printf("*");
            } else if (i >= ((height) / 3) && ((j == point_b1 || j == point_b2) || (i == (height) / 3 && j + 1 != point_a1 && j - 1 != point_a1 && j + 1 != point_a2 && j % 2 == 0))) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        point_a1 = point_a1 - 1;
        point_a2 = point_a2 + 1;
        printf("\n");
    }
}

int main()
{
    int height;
    printf("Enter the preffered height of the star pattern: ");
    scanf("%d", &height);
    display_star_pattern(height);
    
    return 0;
} */
#include <stdio.h>
void display(int height);

int main()
{
    int height;
    printf("");
    scanf("%d", &height);
    display(height);
    return 0;
}

void display(int height) {
    int i, j;
    int point_a1 = height + height / 2;
    int point_a2 = point_a1;
    int point_b1 = height + height + (height / 2) + 2;
    int point_b2 = height / 2 - 2;

    for (i = 0; i < height; i++) {
        if (i >= (height + 1) / 3) {
            point_b1 -= 3;
            point_b2 += 3;
        }

        for (j = 0; j < height * 3; j++) {
            if (j == point_a1 || j == point_a2) {
                printf("*");
            } else if (i >= height / 3 && (j == point_b1 || j == point_b2 || (i == height / 3 && j + 1 != point_a1 && j - 1 != point_a1 && j + 1 != point_a2 && j % 2 == 0))) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        point_a1--;
        point_a2++;
        printf("\n");
    }
}
