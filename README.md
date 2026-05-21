# Bluetooth-Controlled-Arduino-Car
This project is a Bluetooth-controlled robotic car built using Arduino Uno, HC-05 Bluetooth module, and L298N motor driver. The car is controlled using a smartphone app via Bluetooth commands.

📌 Features
Control via smartphone Bluetooth
Forward / Backward / Left / Right movement
Stop control
PWM speed control
Dual motor driver (L298N)
🧠 Components Used
Arduino Uno
HC-05 Bluetooth Module
L298N Motor Driver
4 DC Motors (2 left + 2 right)
Battery (7.4V–12V recommended)
Jumper wires
Chassis
🔌 Circuit Diagram

⚙️ Pin Connections
HC-05 → Arduino
VCC → 5V
GND → GND
TXD → Pin 10
RXD → Pin 11 (via voltage divider)
L298N → Arduino
IN1 → 4
IN2 → 3
IN3 → 6
IN4 → 7
ENA → 5 (PWM)
ENB → 9 (PWM)
🔋 Power Setup
Battery + → L298N +12V
Battery - → L298N GND
Arduino GND must be connected to L298N GND (common ground required)
📱 Bluetooth Commands
Command	Action
F	Forward
B	Backward
L	Left
R	Right
S	Stop
🧾 How It Works

The Arduino receives Bluetooth commands from the HC-05 module and controls the L298N motor driver to rotate motors accordingly.

🚀 Future Improvements
Add speed control via app
Add obstacle avoidance sensor
Upgrade to ESP32 for WiFi control
