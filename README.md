# 💡 Pick_2_Light Slave System

The **Pick_2_Light Slave** project is an embedded system designed to facilitate efficient inventory management in warehouse environments. It uses a **PIC microcontroller** and **CAN communication** to receive and process inventory data, display it on a **seven-segment display (SSD)**, and update stock information seamlessly.

---

## 🛠 Project Features

- **CAN Communication:** Receives inventory and stock data using **Controller Area Network (CAN)** protocol.
- **Configuration Mode:** Allows switching between **Node ID** and **Stock Update** modes.
- **Operational Mode:** Displays incoming inventory data and enables stock adjustments.
- **Node ID Mode:** Configures and displays the **Node ID** using a **Matrix Keypad**.
- **Stock Update Mode:** Manages and updates stock values, with EEPROM storage.
- **EEPROM Integration:** Stores configuration and stock data for persistent usage.
- **User Interface:** Simple **Matrix Keypad** and **SSD** display for interaction.
- **External Interrupts:** Handles input changes efficiently.

---

## 🧰 Technology Stack

- **Microcontroller:** PIC Microcontroller
- **Communication Protocol:** CAN (Controller Area Network)
- **Input Interface:** Matrix Keypad
- **Display:** Seven-Segment Display (SSD)
- **Memory Storage:** EEPROM
- **Interrupt Handling:** External Interrupts for responsive input processing

---

## 🔄 Project Workflow

1. **Initialization:** Configures peripherals (CAN, EEPROM, SSD, Matrix Keypad, Interrupts).
2. **Configuration Mode:**
   - **Node ID Mode:** Sets and displays the **Node ID**.
   - **Stock Update Mode:** Updates stock information via keypad input.
3. **Operational Mode:**
   - Receives CAN messages.
   - Compares incoming **Node ID** with stored ID.
   - Allows stock increment/decrement and transmits updated stock via CAN.
4. **Data Handling:**
   - **EEPROM Read/Write:** Manages non-volatile storage of **Node ID** and stock values.
   - **CAN Transmit/Receive:** Sends and receives inventory data.
   - **Keypad Interaction:** Manages input for ID and stock management.

---

## 📂 File Structure

- `main.h` - Contains global definitions, state declarations, and function prototypes.
- `can.c` - Manages CAN communication (init, transmit, receive).
- `config_mode.c` - Implements configuration mode with **Node ID** and **Stock Update** options.
- `digital_keypad.c` - Initializes and reads input from the **Matrix Keypad**.
- `eeprom.c` - Handles EEPROM read and write operations.
- `external_interrupt.c` - Configures and manages external interrupts.
- `node_id.c` - Manages the **Node ID Mode** for setting and saving IDs.
- `operational_mode.c` - Implements the **Operational Mode**, including stock updates and CAN communication.
- `update_stock.c` - Allows manual stock updates using the **Matrix Keypad**.

---

## 🚀 Future Enhancements

- **Wireless Communication:** Integrate **Bluetooth/WiFi** for remote inventory management.
- **LCD Display:** Replace **SSD** with a more informative **LCD** or **OLED** display.
- **Error Handling:** Add diagnostics for **CAN** communication and peripheral failures.
- **Battery Backup:** Ensure data persistence during power failures.
- **Advanced Stock Management:** Include features like batch and expiry date tracking.

---

## 📧 Contact

For any questions, feel free to reach out:

- **Vivek**
- Email: [gopivivek57@gmail.com](mailto:gopivivek57@gmail.com)
- LinkedIn: [Vivek](https://www.linkedin.com/in/vivek57/)
