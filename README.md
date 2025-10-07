# 🎮 Classic Console Games in C++

This repository contains two classic console games implemented in **C++**:

1. **Tic-Tac-Toe** – A simple 2-player grid game.
2. **Snake Game** – A console-based snake game where you control a snake to collect fruits and grow longer.

Both games are designed to run in a terminal and are beginner-friendly for learning C++ basics, game loops, and logic handling.

---

## 🕹️ Games Included

### 1. Tic-Tac-Toe

**Description:**  
- Two players take turns marking X or O in a 3x3 grid.  
- The first player to align three marks horizontally, vertically, or diagonally wins.  
- If all slots are filled without a winner, the game is a draw.  

**Features:**
- Handles both uppercase and lowercase inputs for markers (`x`, `X`, `o`, `O`).  
- Allows optional player names. Default names are `Player 1` and `Player 2`.  
- Validates input and prevents overwriting already chosen slots.  

**How to Run:**
1. Open terminal in the project folder.
2. Compile the code:
```bash
g++ main.cpp -o tictactoe
````

3. Run the game:

```bash
./tictactoe
```

**Gameplay Example:**

```
Enter Player 1 name (or press Enter to keep default): Alice
Enter Player 2 name (or press Enter to keep default): Bob
Alice, choose your marker (X or O): x

 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Alice, enter your slot (1-9):
```

---

### 2. Snake Game

**Description:**

* Control a snake to eat fruits (`F`) and grow longer.
* Avoid colliding with yourself.
* The game ends when the snake hits its tail.

**Controls:**

* `W` → Move Up
* `A` → Move Left
* `S` → Move Down
* `D` → Move Right
* `X` → Exit game

**Features:**

* Console-based game using Linux-compatible keyboard input.
* Dynamic speed control: adjust the `usleep()` delay to control the snake speed.
* Snake grows longer with each fruit collected.
* Simple scoring system.

**How to Run:**

1. Open terminal in the project folder.
2. Compile the code:

```bash
g++ snake.cpp -o snake
```

3. Run the game:

```bash
./snake
```

**Gameplay Example:**

```
######################
#                    #
#        O           #
#                    #
#          F         #
#                    #
######################
Score: 0
```

---

## ⚙️ Requirements

* **Linux** (Ubuntu recommended)
* **g++ compiler**
* **VS Code or any code editor**

**Install g++ on Ubuntu (if not installed):**

```bash
sudo apt update
sudo apt install build-essential
```

---

## 📝 Notes

* These games are **console-based** and do not include graphical UI.
* They are designed to teach **basic C++ concepts**, including arrays, loops, functions, and game logic.
* Snake game uses `termios` and `ioctl` for non-blocking input on Linux.

---

## 🚀 Future Improvements

* Add **AI opponent** for Tic-Tac-Toe.
* Add **colored output and smoother animations** for Snake Game.
* Make both games **mobile-compatible** using frameworks like **Qt** or **Flutter + FFI**.

---

## 📂 Project Structure

```
ClassicConsoleGames/
├── tictactoe.cpp        # Tic-Tac-Toe game
├── snake.cpp       # Snake game
└── README.md       # Project documentation
```

---

## Author

**ROHAN KUMAR CHAUDHARY** – Passionate about C++ and game development.

---

Enjoy coding and playing these classic games! 🕹️

```

---

If you want, I can also **enhance it** to include **screenshots or ASCII board examples** for both games so it looks **more professional on GitHub**.  

