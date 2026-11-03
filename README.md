
# 🎨 OpenGL Computer Graphics Projects

A collection of **Computer Graphics projects developed using C++ and OpenGL (GLFW)**. This repository demonstrates fundamental computer graphics concepts through 2D drawing, 3D object rendering, animation, and interactive simulations.

## 🚀 Projects Included

### 1. 🔷 3D Rotating Cube

A 3D cube rendered using OpenGL with smooth rotation and a black background.

**Features:**
- 3D cube rendering using `GL_QUADS`.
- Multiple colours for different cube faces.
- Visible edges and outlines.
- Depth testing for proper 3D rendering.
- Smooth and continuous rotation.
- Perspective projection.

**Source File:** `cube.cpp`

### 2. 🏠 2D House Design

A colourful 2D house designed using basic OpenGL drawing primitives.

**Features:**
- House structure using rectangles and triangles.
- Circular sun and trees.
- Colourful roof, windows and door.
- Sky and ground background.
- Custom drawing functions for reusable shapes.
- 2D orthographic projection.

**Source File:** `house.cpp`

### 3. 🚦 Interactive Traffic Light Simulation

An animated traffic light simulation demonstrating real-time graphics and keyboard interaction.

**Features:**
- Automatic RED, GREEN and YELLOW light transitions.
- Customizable signal duration.
- Real-time countdown displayed in the window title.
- Pause and resume functionality.
- Keyboard-based interaction.
- Animated graphical environment.
- Signal status displayed in the terminal.

**Keyboard Controls:**

| Key | Function |
|---|---|
| `SPACE` | Pause / Resume simulation |
| `ESC` | Exit simulation |

**Default Signal Duration:**

| Signal | Duration |
|---|---:|
| 🔴 Red | 5 seconds |
| 🟢 Green | 5 seconds |
| 🟡 Yellow | 2 seconds |

**Source File:** `traffic_light.cpp`

---

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Graphics Library:** OpenGL
- **Window Management:** GLFW
- **Compiler:** GCC / MinGW-w64
- **Code Editor:** Visual Studio Code
- **Platform:** Windows

---

## 📁 Project Structure

```text
OpenGL-Computer-Graphics-Projects/
│
├── cube.cpp
├── house.cpp
├── traffic_light.cpp
└── README.md
```

---

## ⚙️ Installation and Setup

### Prerequisites

Make sure you have installed:

1. C++ Compiler (GCC / MinGW-w64)
2. GLFW Library
3. OpenGL Development Libraries
4. Visual Studio Code (recommended)

### Step 1: Clone the Repository

```bash
git clone https://github.com/Harshsaini0214/Computer-Graphics-Project
```

### Step 2: Open the Project

```bash
cd OpenGL-Computer-Graphics-Projects
```

### Step 3: Compile the Programs

**3D Cube**

```bash
g++ cube.cpp -o cube.exe -lglfw3 -lopengl32 -lgdi32
```

**2D House**

```bash
g++ house.cpp -o house.exe -lglfw3 -lopengl32 -lgdi32
```

**Traffic Light Simulation**

```bash
g++ traffic_light.cpp -o traffic_light.exe -lglfw3 -lopengl32 -lgdi32
```

> **Note:** These commands assume GLFW is correctly installed and configured. You may need to specify additional include and library paths depending on your compiler setup.

### Step 4: Run the Programs

```bash
./cube
```

```bash
./house
```

```bash
./traffic_light
```

---

## 📚 Computer Graphics Concepts Demonstrated

- 2D Graphics Rendering
- 3D Graphics Rendering
- Geometric Primitives
- RGB Colour Representation
- 2D Orthographic Projection
- 3D Perspective Projection
- Object Rotation
- Depth Buffering
- Animation
- Keyboard Event Handling
- Real-Time Graphics Simulation

---

## 🎯 Learning Objectives

The main objective of this project is to understand how computer graphics concepts are implemented using C++ and OpenGL.

Through these implementations, I explored:

- Drawing and rendering 2D and 3D objects.
- Understanding OpenGL graphics primitives.
- Working with coordinate systems and projections.
- Implementing object rotation and animation.
- Handling user input and interactive simulations.
- Creating graphical applications using GLFW.

---

## 👨‍💻 Author

**Harsh Saini**

* Bachelor of Computer Applications(Artificial Intelligence & Machine Learning) 

Interested in C++, Computer Graphics, Software Development and Artificial Intelligence.

**GitHub:** [Harshsaini0214](https://github.com/Harshsaini0214)

---

⭐ If you find this project useful, consider giving this repository a star!

**Developed with C++ and OpenGL.**
