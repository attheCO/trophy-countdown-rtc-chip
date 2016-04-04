# trophy-countdown-rtc-chip
theCO - CO:DE trophy with Tiny RTC I2C chip


## How to change countdown date
- open Arduino app on computer and connect Arduino (CO:de trophy)
- open this file (might need to copy file into ~/Documents/Arduino/ folder)
- grab unix time stamp of date:time to count down to (http://www.onlineconversion.com/unix_time.htm)
- change line 35 (eventDate) with a new unix time stamp from above step
- upload change to Arduino

## Heads up
- line 36 changes timeLeft to a Central time zone countdown

## Troubleshooting
- you might have to reconnect Arduino to computer every time before uploading a change

## Todo:
- add random message every 5secs (maybe a for-loop)
Any other suggestions?
