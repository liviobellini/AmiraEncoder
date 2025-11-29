# AmiraEncoder

Rotary encoder library with acceleration support.<br>
AmiraEncoder allows developers to use the rotary encoder with acceleration support to speed up the increment of the variable.<br>

---

## ✨ Features

- ✔️ Reliable direction detection (CW / CCW) 
- ✔️ Automatic acceleration based on rotation speed 
- ✔️ Configurable normal step, accelerated step and encoder sensitivity
- ✔️ Integrated variable increment/decrement logic
- ✔️ Bounce-resistant thanks to state-table logic (developed by Brian Low)
- ✔️ Selectable full step and half step table
- ✔️ Supports internal or external pullup resistors
- ✔️ Clean and beginner-friendly API

---

## 📦 Installation

### **🟢 Method 1 — Arduino IDE Include Library **
Download the .zip from GitHub -> *Sketch -> Include Library -> Add .ZIP Library*.

### **⚪ Method 2 — Arduino IDE Include Library **
Open Library Manager on left column of Arduino IDE -> search "AmiraEncoder" -> select and install.

### **🔵 Method 3 — Manual Installation **
Copy the **AmiraEncoder** folder into: ~/Documents/Arduino/libraries.

## 📕 User guide
Three examples to learn how to use the library. Enjoy!😎<br>
❗❗Remember that if you want to use half step rotary encoder table then you have to declare "#define HALF_STEP" before including "#include <AmiraEncoder.h>".

## ⚙️ Requirements

Arduino compatible board.<br>

## 👤 Author

Developed by Livio Bellini.<br>
Inspiration: Amira F. - "You shine like a neutron star".⭐

## ⭐ Support the project

Leave a star ⭐ on GitHub if you find AmiraEncoder useful!

## 📸 Images

![Screenshot encoder](docs/img/AcceleratedRotary.jpg)
![Screenshot encoder](docs/img/DirectionRotary.jpg)
![Screenshot encoder](docs/img/NormalRotary.jpg)
