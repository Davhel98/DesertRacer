# DesertRacer - UE5.6 2D Racing Game

A simple 2D racing game built in **Unreal Engine 5.6** as a study project.  
The player controls a car, aiming to complete a track while avoiding obstacles.  
The game leverages the Paper2D plugin and features core gameplay systems written in C++.

## 🎮 Gameplay Overview

- **Genre:** 2D Racing / Arcade
- **Objective:** Reach the end of the track without crashing into obstacles.
- **Controls:** Keyboard (configurable via Enhanced Input System).

## 🚗 Features

- **Paper2D Integration:**  
  - Custom 2D car and obstacle sprites created from 2D assets.
  - Sprite layer ordering for a visually clear and appealing game scene.
- **Enhanced Input System:**  
  - User input handled through the Enhanced Input System.
  - Input Actions bound programmatically in C++ for greater flexibility.
- **Level Management:**  
  - Automatic level reload when the player finishes the course or crashes.
- **Collision & Obstacles:**  
  - Simple collision detection triggers failure/reload.
- **Expandable Structure:**  
  - Project is designed to be a foundation for learning or prototyping 2D mechanics in Unreal Engine.

## 🛠️ Skills Acquired

During development, I focused on learning and applying the following Unreal Engine concepts:

- **Creating 2D sprites** from existing assets using **Paper2D**.
- **Sorting and managing sprite layers** to achieve proper visual stacking in a 2D level.
- **Setting up user input** with **Enhanced Input System** and binding **InputActions** via C++ code.
- **Level reloading logic** implemented for both course completion and collision events.

