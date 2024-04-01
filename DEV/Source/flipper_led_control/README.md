# Flipper LED Control
This is a small app built to control the onboard Status LED of the Flipper Zero.

## How to interact with the led
Using the NotificationSequence to interact with the Status LED.  

Include this header :
```
NotificationApp* notifications = furi_record_open(RECORD_NOTIFICATION);
```
Then integrate this code to a triggered function : 
```
            notification_message(notifications, &sequence_reset_rgb);
            notification_message(
                notifications, 
                &sequence_set_only_blue_255
                ); 
```

Here is the complete list of possible interactions with the builtin led : https://developer.flipper.net/flipperzero/doxygen/notification__messages_8h_source.html

To see it in action you can test the application by downloading the release below.  

## RELEASE
Beta v0.1 : 

## Resources
- https://github.com/Mywk/FlipperTemperatureSensor
- https://developer.flipper.net/flipperzero/doxygen/notification_8h_source.html
- https://docs.rs/flipperzero/latest/flipperzero/notification/led/index.html#constants