// Our ESP32CAM module consists of inbuilt ttl module, so we have quickly completed our task
// some ESP32CAM modules are avaiable without inbuilt TTL module,soo you have to buy seperate TTL module OR MB Board to programme ESP32CAM
// You have to connect GPI0 and GND pins should be shorted, so it is a mode that ESP32 cam to ready to upload code.

Please watch the video link provided to programme the ESP32 cam take care while uploading code and give accurate connecions and don't make any connecions wrong otherwise the board will be burned out.
ESP32 CAM programming reference link
https://youtu.be/vPcJ5HOVSRQ?list=PLwF0yC5nSNDORbWNjStQwxw30pgAs9AAQ

ISSUES:
While operating the ESP32 cam we face a lot of issues such as
The 5 volt supply should be mandatory to operate ESP32 cam, It won't work on 3.3 volt supply.
Please cheque the connecions while connecting the ttl board to the ESP32 cam and check the connecions of Tx and Rx of arduino uno should be connected to the Rx and Tx Of ESP32 cam
While uploading a code you have to add your ssid and password of your local WIFI, And the same device you are going to watch the video that device should be connected to that WIFI only.
The code compile and uploading process takes more than a minute don't worry about it.
When the code going to upload it shows like connecting......... at that time you have to press the reset button of the ESP32 cam, After pressing it boots up and erases the recent data and it successfully uploads the code inside it.
If it is shows the message like "serial data is not found" means there is no  proper conneCion between ESP32 cam and your device, Also check the connecions between GPI0 and GND pins properly shorted or not.
If the code is properly uploaded in the ESP32 cam, How to remove the GPIO pin and GND pin connecions and go to serial monitor And again press reset button.
After it shows a customised IP address you have to copy it and paste in your browser to have a look in a live video.




Bluetooth Car Making Video link
https://youtu.be/o6g6G23UA3c

//Bluetooth control App provided in the files


