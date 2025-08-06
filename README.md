# Advanced Computer Graphics Projects

This repository contains four programming assignments for **CPSC 566 – Advanced Computer Graphics**. Projects are written in **C++** using **OpenGL** and explore foundational computer graphics techniques such as hierarchical modeling, animation, and particle systems.

---

## 📁 Project Overview

### `CPSC-566---Assignment-0-main`

**Topic:** Intro to OpenGL rendering and basic scene setup

- Sets up a basic OpenGL environment
- Demonstrates camera movement and lighting setup
- Renders 3D primitives using fixed-function pipeline

✅ **Status:** Complete and working

---

### `CPSC-566---Assignment-1-main`

**Topic:** Hierarchical modeling with matrix stacks

- Implements a hierarchical character or robot using custom shapes
- Supports articulated motion via scene graph traversal
- Uses a matrix stack class for transformation management

✅ **Status:** Complete and working

---

### `CPSC-566---Assignment-2-main`

**Topic:** Skeletal animation and mesh skinning

- Loads `.skel`, `.obj`, and `.attach` files
- Renders a joint hierarchy and animates a skinned mesh
- Uses linear blend skinning for deformation

⚠️ **Known Issues:**

- Skeleton may **not render** properly with some `.skel` files
- **Skin deformation appears incorrect** in some poses
- `assignment_2_solution` is a binary file and **not viewable** in source

---

### `CPSC-566---Assignment-3-michaelclausen`

**Topic:** Particle systems and cloth simulation

- Implements:
  - `SimpleSystem` (basic particles)
  - `PendulumSystem` (mass-spring simulation)
  - `ClothSystem` (spring mesh cloth model)
- Includes multiple time integration strategies:
  - Euler
  - Midpoint
  - RK4

⚠️ **Known Issues:**

- **Cloth simulation unstable** at high time steps or spring stiffness
- Occasional **oscillations or tearing** in the cloth
- `assignment_3_solution` is a compiled binary only

---

## 🛠️ Build Instructions

Each project includes a `Makefile`. To compile and run:

```bash
cd CPSC-566---Assignment-X-main
make
./assignment_X
