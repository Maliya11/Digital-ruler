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


### IC's used:

- Atmega328p microcontroller for processing.
- MT3608 IC for voltage step-up to 5V.
- MPU6050 IC for angle measurement.


### Sensors

- VL53L0X Laser sensor for distance measurement.
- MPU6050 sensor for angle measurement.
- IR emitter and receiver at the encoder wheel for rotation sensing.

### User Interface
- 16x2 LCD displays menu and measurement data.
- ky-040 encoder module enables user input and navigation.

### Power

- Power is provided by 2 parallel-connected 3.7V Li-ion batteries.
- ON/OFF switch controls the power supply.


### Enclosure Design
- The "Enclosure design files" directory holds the enclosure design files, including:

  - Top and bottom parts.
  - Encoder wheel, pole, and knob for user input.
  - Mounting holes for proper component placement.


### Code
- Developed using Arduino IDE, code is in the "Arduino code" directory.
- Focus on menu display and function calls based on user input.
- Separate function implementations for laser sensor, encoder wheel, angle measurement, and battery level indication.

### Contributing
- Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to submit a pull request.
- For major changes, please open an issue first to discuss the changes you would like to make.
