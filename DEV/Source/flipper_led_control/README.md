# Flipper LED Control
This is a small app built to control the onboard Status LED of the Flipper Zero.

## How to interact with the led
Using the NotificationSequence to make the led blink red.  

Include this header :
```
NotificationApp* notifications = furi_record_open(RECORD_NOTIFICATION);
```
Then integrate this to a triggered loop : 
```
notification_message(notifications, &sequence_blink_red_100);
```

## Ref
- https://github.com/Mywk/FlipperTemperatureSensor
