# 🔘 Button Debouncing

## 🤔 What is Button Bouncing?

When a **pushbutton**, **toggle switch**, or **micro switch** is pressed, two metal parts inside the switch are supposed to connect to complete a circuit. However, this connection is not instantaneous. The metal contacts may connect and disconnect several times rapidly before settling, causing **multiple false signals**.

The same thing happens when releasing the button.

🎾 Think of it like a bouncing ball — when dropped, it hits the ground and bounces several times before coming to rest.  
🧯 In electronics, this behavior leads to **false triggers**, where a single press is detected as multiple presses.

---

## 🛠️ Debouncing Techniques

To handle this problem, there are several debouncing techniques:

1. ⏳ **RC Filter Debouncing**  
   Use a resistor-capacitor network to smooth out the bounces.

2. 🔌 **Switch Debouncing IC**  
   Use a dedicated integrated circuit designed to handle debouncing.

3. 💻 **Software Debouncing**  
   Implement in code using:
   - Counters
   - Shift Registers
   - Delays

---

## 💡 Our Solution: Software Counter Debouncing

In this project, we implement a **software-based debouncing** technique using a simple **counter** method.  
It ensures that only stable, intentional button presses are recognized by your program.

📊 This approach is ideal for embedded systems where you want lightweight and reliable debouncing.

> 🖼️ *(Insert a demo gif here if available to show the bouncing effect and the corrected behavior.)*

---

## 📚 Further Reading & Resources

- 📖 [Nuvation: Switch Debouncing in Electronic Product Designs](https://www.nuvation.com/resources/article/switch-debouncing-electronic-product-designs)  
- 🎥 [YouTube Tutorial on Debouncing](https://www.youtube.com/watch?v=IvU8m_30iK0)

---

🧪 Okay, in the following gif, you can see what this simple task initally does and here we wil use the software counter solution to solve this problem.
This mainly to handle the problem of button bouncing
![](https://github.com/MahmoudMostafaTayee/Button_Debouncing/blob/main/Button%20to%20switch%20between%20leds.gif)

---

