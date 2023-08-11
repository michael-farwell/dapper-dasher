#include "raylib.h"
#include <iostream>

int main() {
    // Window dimensions
    const int windowWidth{512};
    const int windowHeight{380};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    // Acceleration due to gravity (pixels/s)/s
    const int gravity{1'000};
    // Jump velocity pixels/s
    const int jumpVel{-600};

    Texture2D scarfy = LoadTexture("../textures/scarfy.png");
    Rectangle scarfyRect;
    scarfyRect.width = scarfy.width / 6;
    scarfyRect.height = scarfy.height;
    scarfyRect.x = 0;
    scarfyRect.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRect.width / 2;
    scarfyPos.y = windowHeight - scarfyRect.height;

    // Animation frame
    int frame{0};
    // Amount of time before we update animation frame
    const float updateTime{1.0 / 12.0};
    float runningTime{0};

    bool isInAir{false};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        const float dT{GetFrameTime()};

        // Game Logic
        if (scarfyPos.y >= windowHeight - scarfyRect.height) {
            velocity = 0;
            isInAir = false;
        } else {
            // Apply gravity
            velocity += gravity * dT;
            isInAir = true;
        }

        // Jump-check
        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVel;
        }

        // Update position
        scarfyPos.y += velocity * dT;

        // Update running time
        runningTime += dT;

        if (runningTime >= updateTime) {
            // Update animation frame
            scarfyRect.x = frame * scarfyRect.width;
            frame++;
            if (frame > 5) {
                frame = 0;
            }
            runningTime = 0;
        }
        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}
