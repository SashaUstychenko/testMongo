#include <ncurses.h>
#include <cmath>
#include <unistd.h>  // для sleep

const double PI = 3.14159265;
const int DELAY = 100000; // затримка між кадрами

struct Point {
    double x, y;
};

// Функція для малювання заповненого квадрата
void drawFilledSquare(Point* points) {
    clear();  // очищаємо екран

    // Знаходимо мінімальні та максимальні координати, щоб малювати всередині
    double minX = points[0].x, maxX = points[0].x;
    double minY = points[0].y, maxY = points[0].y;
    for (int i = 1; i < 4; i++) {
        if (points[i].x < minX) minX = points[i].x;
        if (points[i].x > maxX) maxX = points[i].x;
        if (points[i].y < minY) minY = points[i].y;
        if (points[i].y > maxY) maxY = points[i].y;
    }

    // Малюємо кожну точку всередині квадрата
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            mvprintw(y, x, "*");
        }
    }

    refresh();  // оновлюємо екран
}

// Функція для обертання квадрату навколо його центру
void rotateSquare(Point* points, double angle) {
    // Знайдемо центр квадрату
    double centerX = 0, centerY = 0;
    for (int i = 0; i < 4; i++) {
        centerX += points[i].x;
        centerY += points[i].y;
    }
    centerX /= 4;
    centerY /= 4;

    for (int i = 0; i < 4; i++) {
        // Зміщуємо точку так, щоб центр був у (0, 0)
        double x = points[i].x - centerX;
        double y = points[i].y - centerY;

        // Обертання навколо (0, 0)
        double rotatedX = x * cos(angle) - y * sin(angle);
        double rotatedY = x * sin(angle) + y * cos(angle);

        // Повертаємо точку на місце
        points[i].x = rotatedX + centerX;
        points[i].y = rotatedY + centerY;
    }
}

int main() {
    initscr();  // ініціалізуємо ncurses
    noecho();   // вимикаємо відображення введених символів
    curs_set(FALSE); // ховаємо курсор

    // Початкові координати квадрату (вершини)
    Point square[4] = {
        {10, 5},
        {20, 5},
        {20, 15},
        {10, 15}
    };

    double angle = 0.0;

    while (true) {
        // Малюємо заповнений квадрат
        drawFilledSquare(square);

        // Обертаємо квадрат навколо його центру
        rotateSquare(square, PI / 180);  // обертаємо на 1 градус

        usleep(DELAY);  // затримка між кадрами
        angle += PI / 180;  // збільшуємо кут обертання
    }

    endwin();  // завершуємо роботу ncurses
    return 0;
}

