# Flipper-Project
Repository containing my work and experiments with the flipper zero.

## Use Flipper Zero to control Chromecast
To control a Chromecast I think we have two angles, pair the flipper to the chromecast by making it think it is an OG remote or capture and emulate bluetooth packets.  
I will try to capture bluetooth packets using the wifi (and BT) devboard.
### Flashing wifi devboard with lastest Marauder Firmware.
1) Install custom firmware on esp32 wifi devboard : https://youtu.be/12M_oHmxcCQ?si=LEclXl1lESQbN20P&t=708
2) Download required driver : https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
3) Plugin wifi devboard while pressing boot button
4) Go to https://fzeeflasher.com/ with google chrome
5) Flash last marauder firmware
### Start to mess with the wifi/BT devboard
**TLDR ESP32-S2 chip inside flipper wifi devboard does not support bluetooth.**

*To investigate next : https://github.com/skorokithakis/catt*
### Connect to flipper Zero WiFi Dev Board cli (from justcallmekoko)
```
    Connect your Dev Board to the Flipper Zero
    Plug your flipper zero into your PC
    On your flipper, start the USB/UART bridge app under GPIO
    Make sure the following settings are set
        USB Channel: 0
        Baudrate: 115200
    Open your Serial terminal software
        If you are using a PC, make sure you have Putty installed
    In your Serial terminal software, make sure the following is set
        Baud: 115200
        Port: Whatever serial port your device occupies when plugged in i.e. COMX
    Click whatever button starts the connection
        Putty: Open
    Verify the connection was successful by hitting the reset button on the dev board
        You should see the Marauder title screen appear
```

#### Sources used for this project
- https://github.com/justcallmekoko/ESP32Marauder/wiki/cli
- https://www.threatlocker.com/blog/mac-bluetooth-impersonation-attacks
- https://thecomputernoob.com/2023/02/17/bluetooth-badusb-attacks-flipper-zero/

## Custom Remotes
- Custom remotes profiles
- WIP Helix remote control (WIP)
- Chromecast Remote (WIP)

## Resources
- https://github.com/UberGuidoZ/Flipper
- https://github.com/djsime1/awesome-flipperzero
- https://docs.flipper.net/
- https://github.com/Flipper-XFW/Xtreme-Firmware
- https://github.com/hak5/usbrubberducky-payloads
- https://www.youtube.com/watch?v=12M_oHmxcCQ
