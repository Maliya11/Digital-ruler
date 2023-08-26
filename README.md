# Digital-ruler

This is the project I did in my 4th semester at the University of Moratuwa. The device I developed is called "Digital Ruler" because it can measure both short and long distances accurately.

### Usage

- Power on the Digital Ruler device.

- Use the ky-040 encoder module to navigate through the menu options on the LCD screen.

- Choose the desired measurement mode from the menu:
  - Distance Measurement with Laser sensor
  - Distance Measurement with Encoder wheel
  - Angle Measurement
    
- Follow the on-screen instructions to perform measurements.

- View the measurement results on the LCD screen.


### PCB Design
 - The "PCB design files" directory contains the PCB design files, which include:

   - Schematic diagram
   - PCB layout
   - Gerber files for manufacturing

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/2cb54712-230f-45eb-bce4-5603b17a93c7)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/67cdeb60-31b9-481b-8fa0-647c71ba644f)

### IC's used:

- Atmega328p microcontroller for processing.
- MT3608 IC for voltage step-up to 5V.
- MPU6050 IC for angle measurement.

![ic](https://github.com/Maliya11/Digital-ruler/assets/114799896/6e263856-b67e-4c2e-a045-4660e3ae7056)


### Sensors

- VL53L0X Laser sensor for distance measurement.
- MPU6050 sensor for angle measurement.
- IR emitter and receiver at the encoder wheel for rotation sensing.

![laser](https://github.com/Maliya11/Digital-ruler/assets/114799896/5b77d76b-4349-447f-b260-4c3bed21c1c8)

![acce](https://github.com/Maliya11/Digital-ruler/assets/114799896/0c983b32-9afb-40f9-becb-83dd84b80e31)

![ir](https://github.com/Maliya11/Digital-ruler/assets/114799896/0709593b-cd2c-4f51-a291-f9ae2f0b929a)


### User Interface
- 16x2 LCD displays menu and measurement data.
- ky-040 encoder module enables user input and navigation.

![lcd](https://github.com/Maliya11/Digital-ruler/assets/114799896/a9d8478c-dcd0-45ee-9a5b-1d166439ef18)

![WhatsApp Image 2023-08-27 at 01 24 03](https://github.com/Maliya11/Digital-ruler/assets/114799896/29f6c044-9d2f-4a93-ba74-e8165b731aec)

### Power

- Power is provided by 2 parallel-connected 3.7V Li-ion batteries.
- ON/OFF switch controls the power supply.

![power](https://github.com/Maliya11/Digital-ruler/assets/114799896/a67feff1-8b84-4d1c-89fd-ef5fc774f951)


### Enclosure Design
- The "Enclosure design files" directory holds the enclosure design files, including:

  - Top and bottom parts.
  - Encoder wheel, pole, and knob for user input.
  - Mounting holes for proper component placement.

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/6624172e-dc2b-4a03-a149-600a5aa6fa53)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/a9966051-d3e9-4798-9ce2-2f4151eaa08a)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/24d3ac61-4e68-46e0-96c9-be74ce723e1f)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/37d2af51-e712-47a1-9ca6-af0a10fed48d)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/d7e3716f-a729-4762-84d2-d89aa3aad00e)

![image](https://github.com/Maliya11/Digital-ruler/assets/114799896/33d1e2b0-ae06-4277-a409-1e0e4c85ec24)


### Code
- Developed using Arduino IDE, code is in the "Arduino code" directory.
- Focus on menu display and function calls based on user input.
- Separate function implementations for laser sensor, encoder wheel, angle measurement, and battery level indication.

### Contributing
- Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to submit a pull request.
- For major changes, please open an issue first to discuss the changes you would like to make.
