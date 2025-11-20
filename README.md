# Advanced Computer Graphics Projects

This repository contains four programming assignments for **CPSC 566 – Advanced Computer Graphics** at CSUF. Each project explores a core graphics concept using **C++** and **OpenGL**, including curve modeling and swept-surface generation, hierarchical modeling, skeletal animation, and physical simulations.

> 💡 Many of the projects were built on a base code framework provided by the professor. Student contributors implemented and debugged required components as outlined in each assignment.

---

## 📁 Project Overview

### `assignment_0`

**Topic:** Intro to OpenGL and basic rendering setup  
**Contributor:** Michael Clausen  
**Base Code:** Provided by instructor

- Sets up a working OpenGL environment.
- Draws simple primitives using GLUT.
- Configures basic camera controls.

✅ **Status:** Fully working  
🧑‍🏫 Instructor provided most of the base code; no major changes required.

---

### `assignment_1`
Topic: Curve modeling (Bézier & B-spline) + swept surfaces (surface of revolution & generalized cylinder)
Contributors: Michael Clausen, Jacob Re, Sonal Mogra
Base Code: Provided by instructor; curve/surface evaluation and parsing implemented by students

What it does

* Cubic Bézier (bez2, bez3) and uniform cubic B-spline (bsp2, bsp3) evaluation via basis-matrix formulation (curve.cpp, curve.h).

* Builds per-sample Frenet frames (T, N, B) along the curve; includes a circle primitive (circ).

* Surface of Revolution (rev): sweeps a 2D profile about the y-axis.

* Generalized Cylinder (gcyl): sweeps a 2D/3D path with a 2D profile (partial implementation).

* SWP file parser (parse.cpp/.h) to define curves/surfaces; OBJ export for generated surfaces.

* OpenGL viewer with toggles for curves, surfaces, and control points.

Controls

* Space – reset camera

* c/C – cycle curve display (off/lines/frames)

* s/S – cycle surface display (off/wireframe/shaded)

* p/P – toggle control points

Known limitations (from project notes)

* Surfaces may show chunky cylinders / visible segmentation; normals may vary between profile control points.

* Some cylinders show a hole at a profile control point (first/last CP edge case).

* Surface of revolution may produce extra/stray surface patches outside the intended profile in some cases.

* Error handling for malformed inputs is minimal.

Key files

* curve.cpp/.h – Bézier/B-spline evaluation, circle, frame construction, drawing

* surf.cpp/.h – surface of revolution & generalized cylinder, OBJ output

* parse.cpp/.h – SWP parser (curves/surfaces)

* main.cpp – viewer, input handling, display lists
---

### `assignment_2`

**Topic:** Skeletal animation and mesh skinning  
**Contributors:** Michael Clausen, Jacob Re  
**Base Code:** Provided by instructor

- Loads a `.skel` file and renders a skeleton as a joint hierarchy.
- Loads an `.obj` mesh and an `.attach` file for skinning.
- Implements **linear blend skinning** to deform the mesh using joint transforms.

⚠️ **Known Issues:**
- Skeleton loads and renders correctly.
- Skinning mostly works, but **some artifacts or inaccuracies may occur** depending on the model.
- Error handling is minimal — malformed data files may crash the program.

### 🧵 Assignment 3 – Cloth Simulation with Particle Systems
*Folder: `assignment_3`*

Developed by **Michael Clausen** in collaboration with **Jacob Re**, this assignment extends the particle system to simulate cloth physics. The project implements:

- Structural spring generation between particles
- Force evaluation using basic spring dynamics
- Partial rendering of the cloth mesh

⚠️ **Known Limitations:**
- The implementation only includes **structural springs**; **shear** and **flex springs** are not fully implemented.
- Functions such as `computeShearForces` and `computeFlexForces` remain unimplemented.
- Some particles and springs render correctly, but the overall cloth behavior is incomplete.

Despite these challenges, the project demonstrates a solid understanding of particle system mechanics and spring-based force modeling.

---

✅ **Usage:**
```bash
make
./assignment_2 data/ModelX
