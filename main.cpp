#include "raylib.h"

int main() {
    // Window dimensions
    const int width{512};
    const int height{380};
    InitWindow(width, height, "Dapper Dasher");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game Logic

        EndDrawing();
    }
}
