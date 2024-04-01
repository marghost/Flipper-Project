# Flipper-Project
Repository containing my work and experiments with the flipper zero.

## Custom Firmware
Why use custom firmware on the Flipper Zero?  The OFW lock certain frequencies and functions of the flipper.  It also contain fewer apps and is less stable.  
### Momentum
This is the newest current firmware available as of now.  It is the evolution of Xtreme-Firmware, backed by the main devs who made XFW great.  This firmware unlock all the same functions of XFW and more (Mass Usb Storage, javascript execution capabilities).  

To see all the new features of this firmware and to get it go to the official website : https://momentum-fw.dev/

Github Repo : https://github.com/Next-Flip/Momentum-Firmware

## Official WiFi devboard
### Flashing WiFi devboard with lastest Marauder Firmware.
1) Install custom firmware on esp32 WiFi devboard : https://youtu.be/12M_oHmxcCQ?si=LEclXl1lESQbN20P&t=708
2) Download required driver : https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
3) Plugin WiFi devboard while pressing boot button
4) Go to https://fzeeflasher.com/ with google chrome
5) Flash last marauder firmware

### Connect to Flipper Zero WiFi Dev Board cli (from justcallmekoko)
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
#### WiFi Dev Board Sources
- https://github.com/justcallmekoko/ESP32Marauder/wiki/cli
- https://www.threatlocker.com/blog/mac-bluetooth-impersonation-attacks
- https://thecomputernoob.com/2023/02/17/bluetooth-badusb-attacks-flipper-zero/

## Controling Remotes
Custom remote files can be found [here](custom_files/infrared/my_remotes/).
### IR Remotes
The infrared app is pretty easy to use.  I tested it by cloning signal from various of my remotes.  Work great with old remotes.  

Newer remotes like the one that comes with the Chromecast have an hybrid system that can't be fully cloned and emulated by the flipper.  The issue is those remote use a few ir commands but to control the main unit, communication is done via bluetooth.  

### Chromecast
**TL;DR** IR scanner only work with few IR functionality of the official chromecast remote like power or volume.  This is because the chromecast remote use bluetooth for the majority of the controls.  This is a dead end for now.

### Helix Remote 
*(Provided by cable compagny)*

Presumed Bluetooth/IR.

**WIP**

## Flipper's Bluetooth capacity 
I discovered that the wifi dev board (ESP32 from flipper official reseller) is not bluetooth compatible, that limit the flipper to devices that support it's BLE protocol.  There is a way to pair it with windows 11 computer by going to Setting > Bluetooth & Devices > Bluetooth devices discovery and select advanced.  
*To try next : Bluetooth BadKB scripts*

## Application Developpement
### Compile for Flipper Zero
To compile an app you need to clone the repo of the actual firmware you are using.  In my case Momentum-Firmware.  I will use vscodium, but you can use your favorite code editor.

**1) Get the Repo**

`
git clone --recursive https://github.com/Next-Flip/Momentum-Firmware.git ./
`

**2) Open a terminal**

Right-clic on the fbt file from the repo and select "Open in terminal"

**3) Setup vscode integration**

This command will download the toolchain needed.
`
./fbt vscode_dist
`

*Restart vscodium after this download.*

**4) Select the right firmware version (DEV vs Release)**

You need to select the right version inside source control to compile for your firmware.  Go to the "Source Control" inside vscodium.  Then go to the cloned firmware and click on the little DEV icon.  Select the right firmware version for witch you want to compile your apps.

**5) [Debug] Build Firmware**

Press Ctrl+Shift+B.  Then select Debug Build Firmware.

**6) Create and Compile an APP**

Right-clic on application_user and then create a new folder for your app.

Then you can test an example app provided with the firmware or you can build your own.

To test it you need to press Ctrl+Shift+B and then select "Launch app on flipper"

The compiled app can be found on your flipper inside the "/apps/" folder.  It will have the .fap ext.

## My Applications

### Flipper LED Control
This is a small app I built as a proof of concept to control the onboard Status LED of the Flipper Zero.

**Source & More Info :** [Flipper LED Control Code](https://github.com/marghost/Flipper-Project/tree/main/DEV/Source/flipper_led_control)

**Compiled App :** [flipper_led_control.fap](https://github.com/marghost/Flipper-Project/raw/main/DEV/apps/Misc/flipper_led_control.fap)

### BLE Spam RickRoll Edition
#### Description
Flood BLE advertisements with Rick Roll Lyrics to cause spammy fake bluetooth devices.  The new "feature" i added let you Rick Roll people's Bluetooth settings.  

Slightly modified version of ble_spam.  Based on the source provided here : [ble_spam](https://github.com/Flipper-XFW/Xtreme-Apps/tree/dev/ble_spam)  

This was done as a proof of concept, this is **NOT** an officially supported app.

**Source :** [BLE Spam RickRoll Code](https://github.com/marghost/Flipper-Project/tree/main/DEV/Source/ble_spam_RickRoll)

**Compiled App :** [ble_spam_rickroll.fap](https://github.com/marghost/Flipper-Project/raw/main/DEV/apps/Bluetooth/ble_spam_rickroll.fap)

### Hello World
A proof of concept using the provided code examples to make a basic Canevas with text on it.

**Source :** [HelloWorld Code](https://github.com/marghost/Flipper-Project/tree/main/DEV/Source/HelloWorld)

**Compiled App :** [hello_world.fap](https://github.com/marghost/Flipper-Project/raw/main/DEV/apps/Misc/hello_world.fap)

#### CREDIT
- Hacked together by @Willy-JL
- Custom adv API by @Willy-JL (idea by @xMasterX)
- iOS 17 Crash by @ECTO-1A
- Android, Samsung and Windows Pairs by @Spooks4576 and @ECTO-1A
- Research on behaviors and parameters by @Willy-JL, @ECTO-1A and @Spooks4576

## Resources
### Basic doc
- https://docs.flipper.net/
- https://www.youtube.com/watch?v=12M_oHmxcCQ (Starter Guide)
### Extended doc and file repo
- https://github.com/UberGuidoZ/Flipper
- https://github.com/skizzophrenic/Ubers-SD-Files
- https://github.com/djsime1/awesome-flipperzero
- https://github.com/hak5/usbrubberducky-payloads
### Firmwares
- https://github.com/Flipper-XFW/Xtreme-Firmware
- https://github.com/Next-Flip/Momentum-Firmware
### Dev ressources
- https://github.com/flipperdevices/flipperzero-ufbt (SDK)
- https://github.com/flipperdevices/flipperzero-firmware/blob/dev/documentation/fbt.md (All in one developpement toolkit)
- https://github.com/jamisonderek/flipper-zero-tutorials/
- https://www.youtube.com/watch?v=27RtJAxY2RY (DEV / Hello World / How to compile for the flipper zero)
- https://www.youtube.com/watch?v=gqovwRkn2xw&list=PLM1cyTMe-PYJaMQ6TWeK1mAWxORdjYJZ5 (Full playlist)
- https://instantiator.dev/post/flipper-zero-app-tutorial-01/
- https://instantiator.dev/post/flipper-zero-app-tutorial-02/
