# GPS logger for ESP32-S3 with LCD-display

GPS logger for Speedsurfing, based on ESP32 & Ublox  hardware.  This is a open source project for a gps-speedlogger with a ESP32 µ-controller. This logger is approved for uploading to [http://gps-speedsurfing.com](http://gps-speedsurfing.com)

![ESP GPS banner 1024x500](https://user-images.githubusercontent.com/58887243/228194449-03b4aee7-f6ac-44cf-936f-beec46ba28fb.jpg)

## Forked from https://github.com/RP6conrad/T_display

#### Runs on T-Display-S3 type hardware, optimized for Waveshare ESP32-S3 Touch LCD 1.47"

<img width="1035" height="793" alt="image" src="https://github.com/user-attachments/assets/087804da-d31b-4817-a25a-12455d68bf5c" />


- small form factor
- 16 MB onboard flash for 20h + logging .gpy @ 5Hz
- SD-card optional, convenient card slot placement
- 320 x 172 touch display, allows for UI enhancements

#### Build environment
- Arduino IDE 2.3.0
- Espressif 2.0.3
- ArduinoJson by Benoit 6.17.2
- TFT_eSPI by Bodmer 2.5.0
- builtin LittleFS
- in C:\Users\user\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.6\libraries\SD\library.properties change `SD(esp32)` to `SD`

#### Setup
- GPS powered from pins 1,2,3, power off in sleep mode
- GPS serial Rx on pin 4, Tx on pin 5
- switch on pin 10
  
#### Software by RP6conrad
- built for ublox M8, M9 or M10 type GPS reveivers with auto-detection and -cofiguration
- GPS configured for sending ubx navpvt (+navdop + navsat) messages
- variable log rate 1,2,4,5,10 up to 20 Hz on M9
- multiple log file types configurable: gpy, sbp, ubx, gpx plus navsat txt messages
- approved for GPSSpeedsurfing.com
- configurable statistics screens
- configurable wifi connectivity (accesspoint / station mode)
