# Chess-Visual-Studio-2022-SFML

**A desktop, local two-player chess application built in C++ using SFML and developed for Visual Studio 2022.**

[View the repository](https://github.com/AngeloDuenas/Chess-Visual-Studio-2022-SFML) · [Project video](https://youtu.be/8RNtNxrFRK8)

## Overview

This project explores interactive application development through a graphical chess game. It combines an SFML-rendered chessboard with an array-based game state, mouse-driven input, piece-specific movement rules, turn management, and timed matches.

The interface displays an **8 × 8 board**, the active player's turn, the currently selected piece, check notifications, and independent countdown clocks. A console accompanies the graphical window for initial game configuration, move information, and pawn-promotion selections.

> **Rules distinction:** This is a custom chess implementation rather than a fully tournament-compliant chess engine. Check is reported, but moves are **not** constrained to resolve check. A player wins by capturing the opposing king, by the opponent running out of time, or by the opponent closing the game window. See [Current limitations](#current-limitations).

## Features

- **Local two-player gameplay:** White moves first; players alternate using the same computer.
- **Graphical board and pieces:** SFML draws the board, piece textures, selection display, and game-status sidebar.
- **Mouse-based movement:** Select a piece with a left click, then click its intended destination.
- **Move validation:** Piece-specific movement checks for pawns, knights, bishops, rooks, queens, and kings, including path checks for sliding pieces.
- **Special moves:** Code paths for castling, en passant, and pawn promotion, with the implementation limitations noted below.
- **Configurable chess clocks:** Choose a **5-, 10-, or 15-minute** clock per player; the default is **15 minutes**.
- **Check indicators:** Separate attack-board arrays are used to identify and display threatened kings.
- **Game feedback:** Console move logs, turn information, victory messages, and a graphical victory overlay.

## Engineering highlights

This project demonstrates several core C++ application-development concepts:

- **Event-driven programming:** Translate SFML mouse events into piece selection and board-coordinate updates.
- **State representation:** Represent pieces with compact string identifiers and manage the board in an `8 × 8` array.
- **Separation of responsibilities:** Organize rendering, movement rules, attack tracking, timers, and win detection into dedicated headers.
- **Graphics integration:** Coordinate sprites, fonts, GUI panels, and frame-by-frame drawing in a single application loop.
- **Rule-based logic:** Implement turn checks, piece movement, special-move branches, and victory conditions.

## Technologies

| Technology | Role |
| --- | --- |
| **C++17** | Game state, input handling, rule checks, and game-loop logic |
| **SFML 2.x** | Window creation, graphics rendering, event handling, textures, fonts, and clock timing |
| **Visual Studio 2022** | Target development environment on Windows |
| **Standard C++ Library** | Arrays, strings, vectors, hash maps, and file input |

> The project uses **SFML 2-style APIs** and has not been migrated to SFML 3.

## How it works

The game maintains the board as an `8 × 8` array of two-character strings. The first character identifies the side (`W` or `B`), and the second identifies the piece (`P`, `R`, `N`, `B`, `Q`, or `K`). For example, `WK` represents the white king; `BP` represents a black pawn.

1. **Initialize:** `Source.cpp` prints the instructions, prompts for a time control, and opens the SFML window.
2. **Select:** A mouse click identifies the source square and selected piece.
3. **Validate:** Movement logic checks the requested destination against the applicable piece rules and the current turn.
4. **Update:** An accepted move updates the board array, attack maps, move log, and active player.
5. **Render:** SFML redraws the board, pieces, selected-piece sidebar, clocks, check alerts, and victory information.

### Source organization

| File | Responsibility |
| --- | --- |
| [`Source.cpp`](Source.cpp) | Application entry point, setup prompts, main loop, timer progression, rendering calls |
| [`PositionArray.h`](PositionArray.h) | Initial piece placement and board representation |
| [`Chessboard.h`](Chessboard.h) | Chessboard squares and piece-sprite rendering |
| [`Movement.h`](Movement.h) | Mouse selection, move execution, promotion prompts, console move output |
| [`Legality.h`](Legality.h) | Piece-movement validation, castling and en-passant logic |
| [`Attack.h`](Attack.h) / [`AttackArray.h`](AttackArray.h) | Attack-square computation and tracking |
| [`Check.h`](Check.h) | Check detection and on-screen notifications |
| [`Timer.h`](Timer.h) | Graphical white and black clocks |
| [`Display.h`](Display.h) | Selected-piece and active-turn display |
| [`WinCon.h`](WinCon.h) | King-capture win detection and victory overlay |
| [`Textures.h`](Textures.h) | Piece-texture loading |
| `time.txt` / `digital-7.ttf` | Clock display data and font |

## Getting started

### Prerequisites

- **Windows** with **Visual Studio 2022** and the **Desktop development with C++** workload.
- An **SFML 2.x SDK** compatible with your Visual Studio toolchain and build architecture (for example, SFML 2.6.x). Use the [official SFML 2.6 Visual Studio guide](https://www.sfml-dev.org/tutorials/2.6/getting-started/visual-studio/) for SDK configuration.
- The **12 chess-piece PNG textures** listed below.

**Important:** The provided source archive does **not** contain a Visual Studio `.sln`/`.vcxproj` project or the actual chess-piece images. It includes a placeholder `assets` entry, so additional setup is needed before the application can run. The included `digital-7.ttf` and `time.txt` files are also needed at runtime.

### 1. Download the source

```bash
git clone https://github.com/AngeloDuenas/Chess-Visual-Studio-2022-SFML.git
cd Chess-Visual-Studio-2022-SFML
```

### 2. Create a Visual Studio C++ project

1. In Visual Studio 2022, create an **Empty Project** for **C++** targeting **Windows**.
2. Add `Source.cpp` as an **existing item**. Keep the supplied `.h` files in the same source directory so the local `#include` directives can resolve.
3. In **Project Properties → C/C++ → Language**, select **ISO C++17** or newer.
4. Configure the matching **SFML 2.x** SDK in Project Properties:

   | Setting | Value |
   | --- | --- |
   | **C/C++ → General → Additional Include Directories** | `<SFML_DIR>\include` |
   | **Linker → General → Additional Library Directories** | `<SFML_DIR>\lib` |
   | **Linker → Input → Additional Dependencies (Release)** | `sfml-graphics.lib; sfml-window.lib; sfml-system.lib` |
   | **Linker → Input → Additional Dependencies (Debug)** | `sfml-graphics-d.lib; sfml-window-d.lib; sfml-system-d.lib` |

5. Match the SDK's **x64/x86 architecture** to your project configuration. If you link dynamically, make the corresponding SFML runtime DLLs available beside the executable or through your `PATH`.

### 3. Restore the runtime assets

Create an `assets/` **directory** at the working-directory root and add a PNG for each piece, using these exact filenames:

```text
assets/
├── BB.png   BK.png   BN.png   BP.png   BQ.png   BR.png
└── WB.png   WK.png   WN.png   WP.png   WQ.png   WR.png
```

`B` denotes black; `W` denotes white. Use image assets that you have permission to redistribute. If you plan to commit them, include appropriate attribution and licensing information.

Ensure these paths resolve **relative to the executable's working directory**:

```text
assets/BK.png       # and the other 11 piece images
digital-7.ttf
time.txt
```

In Visual Studio, set **Project Properties → Debugging → Working Directory** to the folder containing those files. You can use `$(ProjectDir)` if the assets are alongside the project file.

### 4. Build and run

Select your desired configuration (for example, **Debug | x64**), build the project, and start it **with the console available**, since the game asks for input using `std::cin`.

**Note:** The code was written for Windows and uses commands such as `system("cls")` and `system("pause")`. Other operating systems would require source and build adjustments. A successful, reproducible build from the uploaded archive has not been verified.

## Controls and gameplay

| Action | Control |
| --- | --- |
| Configure clock | Enter `0` to customize or `1` for the default 15-minute setting |
| Select a time | `0` = 5 minutes, `1` = 10 minutes, `2` = 15 minutes |
| Start the game | Enter any text at the console prompt |
| Select a piece | Left-click the piece |
| Move a piece | Left-click the destination square |
| Promote a pawn | Enter `0` = bishop, `1` = knight, `2` = queen, or `3` = rook in the console |
| Forfeit | Close the game window before the match is won |

The console also recognizes optional test inputs at startup: `whitecheat`, `blackcheat`, and `omnicheat`. These replace starting non-king pieces on the selected side(s) with queens and are intended as alternate starting configurations, not standard chess rules.

## Current limitations

This repository documents a learning-oriented implementation and should not be described as a complete, validated chess engine:

- **King capture, not checkmate, determines victory.** The code reports check but does not prohibit moves that leave a king threatened. Stalemate and standard draw rules are not implemented.
- **Special-move handling is incomplete.** Castling and en-passant paths exist, but their full legal conditions and edge cases have not been verified.
- **Runtime artwork is missing from the supplied archive.** The twelve piece PNGs must be restored before playing.
- **Build project files are absent.** A Visual Studio project must be created and linked against SFML.
- **Windows-specific console commands** and file-relative paths make the current source non-portable without changes.
- **Input and boundary handling need hardening**, particularly for clicks outside the board and unusual move sequences.

## Possible future improvements

- Implement checkmate, stalemate, draws, and fully compliant move validation.
- Add unit tests for move legality, castling, en passant, and promotions.
- Replace the text-based countdown lookup with clocks driven directly by elapsed time.
- Improve selection feedback, error handling, and out-of-bounds input protection.
- Add a reproducible CMake build, automated checks, and properly licensed piece assets.
- Add move history, restart controls, and save/load functionality.

## Video

A video associated with this project is available here: **[Watch on YouTube](https://youtu.be/8RNtNxrFRK8)**.

## Author

**Angelo Duenas**  
[GitHub](https://github.com/AngeloDuenas) · [LinkedIn](https://www.linkedin.com/in/angeloduenas/)

---

*This repository is presented as a C++/SFML development project. The README describes the source included with the project archive; it does not claim that all chess rules or build configurations have been independently tested.*
