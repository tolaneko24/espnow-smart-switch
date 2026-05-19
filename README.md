# \# ESP-NOW Smart Switch

# 

# Hệ thống mạng điều khiển không dây thời gian thực sử dụng ESP-NOW trên ESP32/ESP8266 dành cho ứng dụng nhà thông minh và hệ thống nhúng IoT.

# 

# \---

# 

# \## 📌 Overview

# 

# Dự án xây dựng một hệ thống điều khiển thiết bị không dây sử dụng giao thức ESP-NOW nhằm giảm độ trễ truyền lệnh, tăng khả năng hoạt động realtime và giảm phụ thuộc vào Cloud trong các hệ thống Smart Home.

# 

# Hệ thống cho phép:

# 

# \* Điều khiển relay không dây.

# \* Giao tiếp thời gian thực giữa các node.

# \* Đồng bộ trạng thái thiết bị.

# \* Kết nối Blynk Cloud để điều khiển từ xa.

# \* Hỗ trợ ACK và retransmission.

# \* Khả năng mở rộng multi-node và multi-hop.

# 

# Dự án được phát triển như một đồ án môn học/hệ thống nhúng với định hướng mô phỏng kiến trúc của các hệ Smart Home thương mại như Zigbee Smart Switch.

# 

# \---

# 

# \# 🎯 Objectives

# 

# \* Xây dựng mạng điều khiển không dây realtime bằng ESP-NOW.

# \* Đánh giá độ trễ truyền lệnh và độ ổn định hệ thống.

# \* So sánh kiến trúc Star và Mesh.

# \* Kết hợp ESP-NOW với nền tảng IoT Cloud.

# \* Thiết kế hệ thống có khả năng mở rộng.

# 

# \---

# 

# \# 🧠 System Architecture

# 

# ```text

# Mobile App (Blynk)

# &#x20;       │

# &#x20;       ▼

# &#x20;  WiFi Router

# &#x20;       │

# &#x20;       ▼

# &#x20;ESP32 Gateway

# &#x20; (WiFi + ESP-NOW)

# &#x20;       │

# &#x20;┌──────┼──────┐

# &#x20;▼      ▼      ▼

# Node1  Node2  Node3

# Relay  Relay  Relay

# ```

# 

# \---

# 

# \# ⚙️ Main Features

# 

# \## Core Features

# 

# \* ESP-NOW peer-to-peer communication

# \* Realtime relay control

# \* ACK response

# \* Retransmission mechanism

# \* Device addressing

# \* Device pairing

# \* Multiple node management

# \* WiFi + ESP-NOW coexistence

# \* Blynk realtime dashboard

# 

# \---

# 

# \## Advanced Features

# 

# \* Multi-hop repeater

# \* ESP-NOW mesh experiment

# \* OTA firmware update

# \* AES encryption

# \* Deep sleep optimization

# \* RSSI monitoring

# \* Packet loss measurement

# 

# \---

# 

# \# 🛠 Hardware Used

# 

# | Hardware        | Description       |

# | --------------- | ----------------- |

# | ESP32 DevKit V1 | Gateway node      |

# | ESP8266/ESP32   | Relay node        |

# | Relay Module    | AC load switching |

# | Router WiFi     | Cloud connection  |

# | Power Supply    | 5V system power   |

# 

# \---

# 

# \# 💻 Software \& Technologies

# 

# | Technology        | Purpose                            |

# | ----------------- | ---------------------------------- |

# | ESP-NOW           | Low-latency wireless communication |

# | WiFi              | Cloud connectivity                 |

# | Blynk IoT         | Mobile dashboard                   |

# | Arduino Framework | Firmware development               |

# | PlatformIO        | Project management                 |

# | GitHub            | Version control                    |

# 

# \---

# 

# \# 📂 Project Structure

# 

# ```text

# espnow-smart-switch/

# │

# ├── firmware/

# │   ├── gateway/

# │   │   ├── src/

# │   │   ├── include/

# │   │   └── platformio.ini

# │   │

# │   ├── relay\_node/

# │   │   ├── src/

# │   │   └── include/

# │   │

# │   └── repeater\_node/

# │

# ├── docs/

# │   ├── report/

# │   ├── images/

# │   └── presentation/

# │

# ├── hardware/

# │   ├── schematic/

# │   └── pcb/

# │

# ├── README.md

# └── .gitignore

# ```

# 

# \---

# 

# \# 🚀 Getting Started

# 

# \## 1. Clone Repository

# 

# ```bash

# git clone https://github.com/NgvTrQuy/espnow-smart-switch.git

# ```

# 

# \---

# 

# \## 2. Open Project

# 

# Using:

# 

# \* VSCode

# \* PlatformIO Extension

# 

# \---

# 

# \## 3. Configure WiFi \& Blynk

# 

# Edit:

# 

# ```cpp

# config.h

# ```

# 

# ```cpp

# \#define WIFI\_SSID "your\_ssid"

# \#define WIFI\_PASS "your\_password"

# 

# \#define BLYNK\_TEMPLATE\_ID "..."

# \#define BLYNK\_AUTH\_TOKEN "..."

# ```

# 

# \---

# 

# \## 4. Upload Firmware

# 

# Select correct board:

# 

# \* ESP32 Dev Module

# \* NodeMCU ESP8266

# 

# Then upload firmware.

# 

# \---

# 

# \# 📡 Communication Flow

# 

# \## ESP-NOW Transmission

# 

# ```text

# Gateway

# &#x20;  │

# &#x20;  ├── Send command

# &#x20;  │

# &#x20;  ▼

# Relay Node

# &#x20;  │

# &#x20;  ├── Execute relay

# &#x20;  ├── Send ACK

# &#x20;  │

# &#x20;  ▼

# Gateway receives confirmation

# ```

# 

# \---

# 

# \# 📊 Performance Metrics

# 

# The project evaluates:

# 

# \* Command latency

# \* ACK response time

# \* Packet delivery ratio

# \* RSSI

# \* Packet loss

# \* Effect of transmission distance

# \* Effect of number of hops

# 

# \---

# 

# \# 🔒 Security

# 

# ESP-NOW supports:

# 

# \* Peer authentication

# \* AES encryption

# \* MAC-based addressing

# 

# Future work includes:

# 

# \* Dynamic pairing

# \* Secure provisioning

# \* Key management

# 

# \---

# 

# \# 🌐 Comparison with Commercial Systems

# 

# | System       | Communication | Topology         |

# | ------------ | ------------- | ---------------- |

# | Tuya WiFi    | WiFi          | Star             |

# | Aqara        | Zigbee        | Mesh             |

# | Philips Hue  | Zigbee        | Mesh             |

# | This Project | ESP-NOW       | Star / Multi-hop |

# 

# \---

# 

# \# 📈 Advantages

# 

# \* Very low latency

# \* No Internet required for local control

# \* Lower cost than Zigbee modules

# \* Fast response

# \* Easy firmware customization

# \* Suitable for embedded learning and research

# 

# \---

# 

# \# ⚠️ Limitations

# 

# \* ESP-NOW ecosystem is smaller than Zigbee

# \* No native routing stack

# \* Limited scalability compared to Zigbee Mesh

# \* WiFi coexistence requires channel synchronization

# 

# \---

# 

# \# 🔬 Future Development

# 

# \* Full ESP-NOW mesh routing

# \* Home Assistant integration

# \* MQTT gateway

# \* Node-RED dashboard

# \* Custom mobile application

# \* Energy optimization

# \* PCB design

# \* Industrial enclosure

# 

# \---

# 

# \# 👨‍💻 Team Members

# 

# | Member           | Responsibility                    |

# | ---------------- | --------------------------------- |

# | Nguyen Trong Quy |                                   |

# | Le Dang Quang    |                                   |

# | Bui Thanh Tung   | 				       |

# 

# \---

# 

# \# 📚 References

# 

# \* Espressif ESP-NOW Documentation

# \* ESP-IDF Programming Guide

# \* Blynk IoT Platform

# \* Zigbee Smart Home Architecture

# \* MQTT Protocol

# 

# \---

# 

# \# 📄 License

# 

# This project is developed for educational and research purposes.

# 

# \---

# 

# \# ⭐ Acknowledgements

# 

# Special thanks to:

# 

# \* Espressif Systems

# \* Arduino Community

# \* PlatformIO

# \* Open-source IoT developers



