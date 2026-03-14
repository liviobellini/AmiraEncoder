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
- ✔️ Selectable full step and half step mode in constructor.
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

- ✔️ Encoder::name(DT, CLK, EXTERNAL, FULL_STEP, 25); <= encoder object with external pullup resistors, full step mode and 25 as sensitivity .<br>
- ✔️ Pullup resistors: you can declare INTERNAL or EXTERNAL.<br>
- ✔️ Step mode: you can declare HALF_STEP or FULL_STEP.<br>
- ✔️ Sensitivity: I like using 25 sensitivity. If you don't use acceleration then just write 0.<br>
- ❗❗ If sensitivity is equal to 0 and longStep is equal to 0 then the acceleration is inhibited.<br>
- ✔️ Use setStep to set the normal step value and use setAccel to set the accelerated step value.<br>
- ✔️ If you don't use these functions then default values will be 1 for normStep and 0 for longStep.<br>
- ❗❗ In setAccel use always a value greater than the value used in setStep.<br>
- ✔️ Call name.setAccel(0); when you want to disable acceleration.<br>
- ✔️ Call name.setStep(1); when you want to reset the normal step to 1 (default).<br>
- ❗❗ AmiraEncoder returns a long type (int32_t), to prevent overflow error do not use AmiraEncoder to change unsigned type variables.

## 🙂 Differences between half step and full step mode

- ✔️ HALF_STEP event also generated on intermediate states (11):
- less stable, more sensitive to bounce, double theoretical resolution, suitable for high-quality encoders.
- ✔️ FULL_STEP event generated only when the encoder reaches the mechanical detent (typically 00):
- very stable, less sensitive to bounce, low precision than half step, suitable for low-cost encoders. 

Three examples to learn how to use the library. Enjoy!😎

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
