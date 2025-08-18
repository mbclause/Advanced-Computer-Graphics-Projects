# Advanced Computer Graphics Projects

This repository contains four programming assignments for **CPSC 566 – Advanced Computer Graphics** at CSUF. Each project explores a core graphics concept using **C++** and **OpenGL**, including hierarchical modeling, skeletal animation, and physical simulations.

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

**Topic:** Hierarchical modeling using a matrix stack  
**Contributors:** Michael Clausen, Jacob Re, Sonal Mogra  
**Base Code:** Provided by instructor

- Implements a hierarchical articulated model (e.g., robot or creature).
- Uses custom matrix stack logic to apply transformations.
- Adds user controls to manipulate limb positions.

✅ **Status:** Fully working  
🔧 Implemented core functionality for drawing and controlling the hierarchical model.

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
