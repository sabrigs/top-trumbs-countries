# Top Trumps: Countries

This project was developed as part of a college lesson about C.

The original challenge proposal came from these repositories:

* [Cadastro de Cartas](https://github.com/Cursos-TI/cadastro-cartas-sabrigs)
* [Desafio Lógica Super Trunfo](https://github.com/Cursos-TI/desafio-l-gica-super-trunfo-sabrigs)

The idea behind this was to simulate a simplified version of the classic card game *Top Trumps* (or Super Trunfo, in portuguese), where two cards battle by comparing attributes such as population, area, GDP and population density.

## Scope

One important decision was intentionally keeping the game limited to only two cards.

An earlier idea was to create a complete deck system using arrays and dynamic memory allocation (`malloc`), allowing the player to register multiple cards and choose which one to play with.

However, since the challenge only required comparing two cards, adding deck management and dynamic memory allocation would increase complexity without contributing directly to the learning goals of the assignment.

Because of that, the final version uses:

* only two card variables;
* stack allocation instead of heap allocation;
* fixed game flow;
* direct comparison between cards.

This helped keep the focus on core introductory concepts instead of prematurely introducing advanced memory management.

# Game logic

The game follows this flow:

```mermaid id="vjlwm9"
flowchart TD

A[Start Game] --> B[Show Intro]
B --> C[Choose Card Creation Mode]

C -->|Manual| D[Create User Card]
C -->|Random| E[Generate Random User Card]

D --> F[Generate Computer Card]
E --> F

F --> G[Choose Battle Attribute]

G --> H[Compare Cards]
H --> I[Display Winner]
I --> J[End]
```

# Some ideas* future improviments

| Category             | Improvements                                                                                                                                                                 | Topics to Study                                                |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| Input Validation     | • Validate invalid numeric input<br>• Prevent negative values<br>• Protect against division by zero<br>• Validate string size before storing<br>• Study safer alternatives to `scanf` | Buffer handling<br>Defensive programming<br>Input sanitization |
| Code Reusability     | • Create a generic comparison function<br>• Reduce duplicated `winner_*()` logic<br>• Explore enums for attribute selection                                                           | Abstraction<br>Generic functions<br>Enums in C                 |
| Game Flow            | • Add "play again" loop<br>• Create main menu loop<br>• Add score system<br>• Add multiple battle rounds                                                                              | Loops<br>State management<br>Game flow architecture            |
| Data Organization    | • Generate different cities and states<br>• Create external card database<br>• Load cards from files                                                                                  | File handling<br>CSV/TXT parsing<br>Dynamic data               |
| Project Architecture | • Split code into `.h` and `.c` files<br>• Create modules for game/card/utils<br>• Organize project folders                                                                           | Modularization<br>Header files<br>Compilation process          |
| Game Balance         | • Improve super power formula<br>• Normalize attribute scales<br>• Add weighted scoring system                                                                                        | Balancing systems<br>Normalization<br>Game design logic        |
| User Experience      | • Improve terminal layout<br>• Add colors to interface<br>• Add animations/loading effects<br>• Improve text formatting                                                               | Terminal UX<br>ANSI escape codes<br>CLI design                 |


*The ideas were generated with ChatGPT to help me to improve my code skills.
