**Name: Princess Dianne Y. Estores
Assigned number: 07
Setup network name: BCA188-ESP32-07**

**Results Table**
| Task                 | What to do                                                          | Observation                                                                                            |
| :------------------: | :-----------------------------------------------------------------: | :----------------------------------------------------------------------------------------------------: |
| 1. Wrong password    | password	Enter a wrong password on the setup page.                  | The connection failed and the board went back to setup mode. After 3 minutes it restarted.             |
| 2. Reset settings    | Hold the BOOT button for 3 seconds while the board is running.      | The saved Wi-Fi was erased and the board restarted. The BCA188-ESP32-07 network appeared again.        |
| 3. Change the name   | Change the network name, upload, and check your phone's Wi-Fi list. | The new name BCA188-ESP32-dyanie showed up in my phone's Wi-Fi list. I changed it back afterward.      |
| 4. Different network | Reset the board, then connect to your phone hotspot.                | The board connected to my hotspot without re-uploading code and got a new IP address (10.108.165.127). |

**Screenshots**

1. Setup page
<img width="720" height="1600" alt="717b5903-0c51-41f3-b858-86bcbf57b65c" src="https://github.com/user-attachments/assets/bc38f2b5-5619-4792-b09c-f56703e0036d" />
2. Serial Monitor
<img width="1917" height="1021" alt="image" src="https://github.com/user-attachments/assets/5f290e0b-c3ab-43bf-833f-3ca5e5511b52" />

Why the board connected to a different network without a code change?
- WiFiManager stores the Wi-Fi name and password in the ESP32's flash memory, not in the sketch, so after I erased them with the BOOT button the setup portal let me enter new credentials at runtime and the same code joined the new network.
