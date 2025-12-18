# 🏓 Pong Game (C++ – Console Version)

A classic **Pong game implemented in C++**, running entirely in the **Windows console**.  
The game uses ASCII characters for rendering and real-time keyboard input to simulate the original Pong gameplay.

This project focuses on low-level game logic, console rendering, and real-time input handling without any external graphics libraries.

---

## 🎮 Features

- Classic Pong gameplay
- Two-player mode
- Real-time paddle movement
- Ball collision with paddles and borders
- ASCII-based rendering
- Smooth gameplay using timed refresh
- Console optimized (cursor hidden, fullscreen window)

---

## 🕹 Controls

| Key | Action |
|----|-------|
| **W / S** | Move left paddle up / down |
| **I / K** | Move right paddle up / down |
| **1** | Quit game |

---

## 🧠 How the Game Works

- The game board is represented as a 2D character array
- Paddles and the ball are drawn using ASCII characters (`#`, `@`, `|`, `-`)
- The ball moves automatically and bounces on collision with paddles or borders
- Keyboard input is handled using `conio.h`
- The game runs inside a continuous loop with a fixed delay for smooth movement

---

## 🛠 Requirements
- C++ compiler (MinGW / MSVC recommended)
- Uses Windows-specific libraries:
  - `<conio.h>`
  - `<windows.h>`


---

