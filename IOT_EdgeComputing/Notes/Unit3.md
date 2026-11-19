### 1. IoT Communication Models

#### 1.1 Request-Response Model

- A **client-server** model in which the client sends a request and the server returns a response.
- Communication is **synchronous** and **pull-based**: data is transferred only when the client explicitly requests it.
- The server is stateless and processes each request independently.
- **Advantages:** simple to implement, suits on-demand data retrieval.
- **Disadvantages:** continuous polling wastes bandwidth and energy, and it scales poorly for event-driven data.
- **Example:** an application sends an HTTP GET request to a device to read the current temperature.

#### 1.2 Publish-Subscribe Model

- An **asynchronous**, **push-based** model with three entities:
    - **Publisher:** produces data and sends it to a _topic_, such as a sensor node.
    - **Subscriber:** registers interest in one or more topics and receives matching messages.
    - **Broker:** an intermediary that receives published messages, filters them by topic, and forwards them to subscribers.
- **Decoupling** between publisher and subscriber exists in three dimensions:
    - **Space:** they need not know each other’s address.
    - **Time:** they need not be active simultaneously.
    - **Synchronization:** neither blocks the other.
- **Advantages:** scalable, supports one-to-many communication, energy-efficient, suited to event-driven IoT.
- **Disadvantage:** the broker is a single point of failure and a possible bottleneck.

**Comparison**

| Parameter     | Request-Response | Publish-Subscribe |
| ------------- | ---------------- | ----------------- |
| Communication | Synchronous      | Asynchronous      |
| Data flow     | Pull             | Push              |
| Coupling      | Tight            | Loose (decoupled) |
| Cardinality   | One-to-one       | One-to-many       |
| Intermediary  | None             | Broker            |

### 2. IoT Application Layer Protocols

#### 2.1 HTTP (Hypertext Transfer Protocol)

- A request-response protocol that runs over **TCP** (default port 80, 443 for HTTPS).
- Uses the methods GET, POST, PUT and DELETE (RESTful).
- Its large, text-based headers create high overhead.
- **Limitation:** unsuitable for resource-constrained devices because of its high power and bandwidth consumption.
- application:- smart 
#### 2.2 MQTT (Message Queuing Telemetry Transport)

- A lightweight **publish-subscribe** protocol over **TCP** (port 1883, 8883 for TLS).
- Fixed header as small as **2 bytes**.
- **Features:**
    - **QoS levels:** (Quality of Service)
        - QoS 0: _at most once_ (fire and forget).
        - QoS 1: _at least once_ (acknowledged, duplicates possible).
        - QoS 2: _exactly once_ (four-way handshake).
    - **Retained messages:** the broker stores the last message on a topic and delivers it to new subscribers.
    - **Last Will and Testament (LWT):** the broker publishes a predefined message if a client disconnects abnormally.
    - **Keep-alive** mechanism to detect broken connections.
    - Topic hierarchy with wildcards (`+` single level, `#` multi level).
- **Applications:** telemetry, smart home, remote monitoring.

#### 2.3 CoAP (Constrained Application Protocol)

- A lightweight **request-response** protocol designed for constrained nodes and networks, standardized in RFC 7252.
- Runs over **UDP** (port 5683, DTLS for security).
- Uses a RESTful model with the methods GET, POST, PUT and DELETE, so it maps easily to HTTP.
- **Features:**
    - **Confirmable (CON)** and **Non-confirmable (NON)** message types, giving reliability at the application layer. (CON means reliable delivery, NoN means fire and forget)
    - **reset** indicates received but don't process.
    - **Observe** option, which gives publish-subscribe-like notifications.
    - Supports **multicast** and resource discovery (`/.well-known/core`).
    - Small **4-byte** fixed header.
- **Applications:** battery-powered sensors, 6LoWPAN networks.
- DTLS used -> Datagram Transport layer security.

#### 2.4 AMQP (Advanced Message Queuing Protocol)

- A reliable, **message-oriented** protocol over **TCP** (port 5672), with queue-based publish-subscribe and point-to-point messaging.
- **Architecture:**
    - **Exchange:** receives messages from producers and routes them.
    - **Queue:** stores messages until consumers process them.
    - **Binding:** the routing rule linking an exchange to a queue.
- **Exchange types:** direct, fanout, topic, headers.
- **Features:** guaranteed delivery, transactions, acknowledgements and security.
- **Applications:** enterprise integration, financial systems, back-end messaging.

---

### 3. Protocol Comparison (Exam Table)

| Feature     | HTTP                | MQTT                | CoAP                        | AMQP               |
| ----------- | ------------------- | ------------------- | --------------------------- | ------------------ |
| Model       | Request-Response    | Pub-Sub             | Request-Response (+Observe) | Pub-Sub / Queue    |
| Transport   | TCP                 | TCP                 | UDP                         | TCP                |
| Header size | Large               | 2 bytes             | 4 bytes                     | Larger             |
| Reliability | TCP-based           | QoS 0/1/2           | CON/NON                     | Very high          |
| Overhead    | High                | Low                 | Very low                    | Medium to high     |
| Suitability | Web, strong devices | Constrained sensors | Highly constrained devices  | Enterprise systems |

## Wireless communication Technologies

## 1. Zigbee
- Zigbee is a low-power, low-data-rate wireless communication technology designed for communication between IoT devices.
- Zigbee adds network and application-layer functionality on top of IEEE 802.15.4.

Zigbee provides:

- Low power consumption.
- Short-range wireless communication.
- Support for many interconnected devices.
- Mesh networking.

## Zigbee Architecture


![[../Pasted image 20261117133243.png]]

### 1. Zigbee Coordinator
- Responsible for establishing the network.
- Selects the network channel.
- Manages network formation.
- There is generally one coordinator per Zigbee network.
this component manages the network.
### 2. Zigbee Router (ZR)

- Forwards messages between devices.
- Extends network coverage.
- Allows other devices to connect through it.
- Helps establish mesh communication.
forward data think of it as network relay
### 3. Zigbee End Device (ZED)
- Performs specific tasks such as sensing or controlling.
- Communicates through a parent coordinator or router.
- Does not forward messages for other devices.
- Can sleep to conserve battery power.

## ZigBee Topologies

### A. Star Topology

All devices communicate directly with a central coordinator.

```
             Sensor
                |
     Sensor -- Coordinator -- Bulb
                |
              Switch
```

**Characteristics**:
- Simple architecture.
- Easy to manage.
- Coordinator is a central dependency.
- Limited coverage compared with mesh networks.

### B. Tree Topology

Devices are arranged hierarchically.

```
          Coordinator
                |
        ----------------
        |              |
      Router 1       Router 2
        |              |
      ------         ------
      |    |         |    |
     ED    ED        ED   ED
```

**Characteristics:**

- Hierarchical communication.
- Routers connect different branches.
- Supports network expansion.
- Communication generally follows parent-child relationships.

### C. Mesh Topology

Devices can communicate through multiple router paths.

```
          Coordinator
           /       \
       Router 1---Router 2
          |          |
       Router 3---Router 4
          |          |
        Sensor     Sensor
```

**Characteristics:**

- Multiple possible communication paths.
- Better coverage.
- Can provide alternative routes if a link fails.
- Self-healing routing can improve reliability.

**Important:** Zigbee mesh networking is particularly useful in smart homes and industrial automation.


## 4. Zigbee Technical Specifications

|Parameter|Details|
|---|---|
|Standard|IEEE 802.15.4|
|Frequency bands|2.4 GHz, 868 MHz, 915 MHz|
|Data rate at 2.4 GHz|250 kbps|
|Network topology|Star, Tree, Mesh|
|Range|Typically around 10–100 metres per hop, depending on environment|
|Power consumption|Low|
|Communication|Wireless|
|Application|Smart homes, automation, monitoring|

**Note:** Actual range depends on transmission power, obstacles, interference and antenna design.

### Frequency Bands

Zigbee operates in different frequency bands:

- 2.4 GHz – Globally used, with 16 channels.
- 868 MHz – Used in certain European regions.
- 915 MHz – Used in certain North American regions.

## 5. Working of Zigbee

Consider a smart home lighting system.

1. A user switches ON a smart bulb using a mobile application.
2. The application communicates with the Zigbee coordinator through a gateway.
3. The coordinator forwards the command through the Zigbee network.
4. The smart bulb receives the command.
5. The bulb switches ON.

```
    Mobile Application
            |
            v
      Zigbee Gateway
            |
            v
       Coordinator
            |
            v
         Router
            |
            v
        Smart Bulb
            |
            v
         ON/OFF
```

A gateway is commonly used to connect the Zigbee network to IP-based networks, although it is not itself a required Zigbee device role.

## 8. Applications of Zigbee

| Application     | Usage                             |
| --------------- | --------------------------------- |
| Smart Homes     | Smart bulbs, switches and sensors |
| Smart Buildings | Lighting and HVAC automation      |
| Industrial IoT  | Machine monitoring                |
| Smart Energy    | Smart meters                      |
| Healthcare      | Low-data-rate monitoring devices  |


## 2. LoRaWAN (Long Range Wide Area Network)

While Zigbee is useful for communication between nearby devices, **LoRaWAN is designed for long-range communication with very low power consumption.**

### Introduction

LoRaWAN is a Low Power Wide Area Network (LPWAN) communication protocol designed for connecting IoT devices over long distances.
It is commonly used when:

- Devices are spread across large geographical areas.
- Only small amounts of data need to be transmitted.
- Devices operate on batteries.
- Frequent charging or battery replacement is undesirable.
---
### LoRa vs LoRaWAN

These two terms are different.

| LoRa                                        | LoRaWAN                                                       |
| ------------------------------------------- | ------------------------------------------------------------- |
| Physical-layer radio technology             | Network communication protocol                                |
| Defines wireless modulation                 | Defines network architecture and communication                |
| Uses Chirp Spread Spectrum (CSS) modulation | Defines device communication, security and network management |
| Responsible for transmitting radio signals  | Manages how devices communicate through the network           |

---
### LoRaWAN Architecture

![[Pasted image 20261117134659.png]]

### A. End Devices / end nodes

These are IoT devices that collect information.

Examples:

- Soil moisture sensors.
- Water-level sensors.
- Smart meters.
- Environmental monitoring devices.

They transmit small packets of information using LoRa radio.

### B. Gateway

The gateway receives LoRa radio transmissions from end devices and forwards them to the network server over an IP infra that connects the network.

Examples of backhaul connectivity:

- Ethernet.
- Wi-Fi.
- Cellular networks.

**Important:** A gateway primarily acts as a transparent bridge between LoRa radio communication and the IP network.

### C. Network Server

The Network Server manages the LoRaWAN network.

Its responsibilities include:

- Device authentication and session management.
- Managing communication and network parameters.
- Removing duplicate packets received by multiple gateways.
- Selecting an appropriate gateway for downlink transmission.
- Managing Adaptive Data Rate (ADR).

### D. Application Server

The Application Server processes application-level data.

For example:

- Receives soil moisture readings.
- Analyzes agricultural conditions.
- Displays readings on a dashboard.
- Triggers irrigation alerts.

### E. Join Server

The Join Server manages device activation and session-key derivation during the joining process.

---

## 3. Working of LoRaWAN

Consider a smart agriculture system.

1. Soil moisture sensors collect soil moisture readings.
2. Sensors transmit data using LoRa radio.
3. Nearby gateways receive these transmissions.
4. Gateways forward the data to the Network Server.
5. Network Server processes network-level information and removes duplicates.
6. Application Server receives the application data.
7. Farmer accesses the information through a mobile application.

```
 Soil Moisture Sensor
          |
          | LoRa Radio
          v
       Gateway
          |
          | IP Network
          v
    Network Server
          |
          v
   Application Server
          |
          v
     Farmer's App
```

---

## 4. LoRaWAN Device Classes

LoRaWAN defines three device classes based on how devices receive downlink messages.

|Class|Working|Power Consumption|
|---|---|---|
|Class A|Receives downlink messages in two scheduled receive windows after each uplink|Lowest|
|Class B|Opens additional scheduled receive windows using network-synchronized beacons|Medium|
|Class C|Keeps its receiver open almost continuously except while transmitting|Highest|

### Class A

- Every device must support Class A.
- Downlink communication happens after an uplink transmission.
- Best for battery-powered sensors.

### Class B

- Uses scheduled receive windows.
- Receives downlink messages at predictable times.
- Useful when more predictable downlink availability is needed.

### Class C

- Keeps the receiver open almost continuously.
- Provides low-latency downlink availability.
- Suitable for devices with continuous power.

**Memory trick:**

- A = All devices must support it.
- B = Beacon-based scheduled reception.
- C = Continuous reception.

## 8. Applications

| Application            | Usage                                       |
| ---------------------- | ------------------------------------------- |
| Smart Agriculture      | Soil moisture and weather monitoring        |
| Smart Cities           | Waste management and streetlight monitoring |
| Smart Water Management | Water-level and leakage monitoring          |
| Industrial IoT         | Remote asset monitoring                     |
| Smart Metering         | Electricity and water consumption           |

## Zigbee vs LoRaWAN: Important Comparison

|Parameter|Zigbee|LoRaWAN|
|---|---|---|
|Standard|IEEE 802.15.4-based|LoRaWAN specification|
|Network type|Personal Area Network|Wide Area Network|
|Range|Short range per hop|Long range|
|Data rate|Higher|Lower|
|Power|Low|Very low|
|Topology|Star, Tree, Mesh|Star-of-stars|
|Frequency|2.4 GHz and sub-GHz bands|Regional sub-GHz bands|
|Main application|Smart homes|Smart agriculture|
|Best suited for|Local device communication|Long-distance sensor communication|

## 3 NB-IoT (Narrowband Internet of Things)

It is a Low Power Wide Area Network (LPWAN) technology developed by 3GPP for connecting IoT devices using cellular network infrastructure.

Unlike Zigbee and LoRaWAN, NB-IoT uses licensed cellular spectrum and is designed to work with cellular operator networks.

### NB-IoT Architecture

NB-IoT uses cellular network infrastructure.

Its major components are:

1. **NB-IoT Devices (UE):** Sensors and smart meters that collect and transmit data.
2. **Base Station (eNodeB):** Provides wireless connectivity between IoT devices and the cellular network.
3. **Core Network (EPC):** Manages connectivity, authentication, mobility and data routing.
4. **IoT Application Server:** Receives and processes the sensor data.

### Architecture Diagram

```
       NB-IoT Devices
       /     |      \
      /      |       \
  Meter    Sensor   Tracker
      \      |       /
       \     |      /
        eNodeB
     (Base Station)
            |
            |
      Core Network
          (EPC)
            |
            |
      Internet / Cloud
            |
            |
    IoT Application Server
            |
            |
       User Dashboard
```

### Explanation of Components

**A. NB-IoT Devices**

These are low-power IoT devices equipped with NB-IoT cellular communication modules.

Examples:

- Smart water meters.
- Electricity meters.
- Environmental sensors.

**B. eNodeB (Base Station)**

- Provides radio connectivity.
- Receives data from IoT devices.
- Transmits data towards the core network.
- Manages radio resources.

**C. Evolved Packet Core (EPC)**

The EPC is the core network used in LTE-based cellular architecture.

It manages:

- Device authentication.
- Network connectivity.
- Data routing.
- Mobility management.

**D. Application Server**

Processes the data received from IoT devices.

For example, a water management application receives water consumption readings and generates billing information.

---

### Working of NB-IoT

Consider a smart water meter installed in a residential building.

1. The meter measures water consumption.
2. Its NB-IoT module prepares the reading for transmission.
3. The device sends the data to a nearby cellular base station (eNodeB).
4. The base station forwards the information to the core network.
5. The core network routes the data to the application server.
6. The application server stores and processes the information.
7. The water department accesses the readings through a dashboard.

```
 Smart Water Meter
        |
        | Cellular Radio
        v
     eNodeB
        |
        v
    Core Network
        |
        v
    Cloud Server
        |
        v
  Water Management
     Application
```

---

### Important Features of NB-IoT

### A. Low Power Consumption

NB-IoT is designed for devices that operate on batteries for extended periods.

Two important power-saving mechanisms are used.

**1. Power Saving Mode (PSM)**

PSM allows an IoT device to enter a deep sleep state when it does not need to communicate.

- Device can remain registered with the network.
- It becomes temporarily unreachable for normal mobile-terminated communication.
- It wakes up when its scheduled activity or configured timer requires it.

Example: A smart water meter sends readings once every few hours and sleeps between transmissions.

**2. Extended Discontinuous Reception (eDRX)**

eDRX allows the device to extend the intervals at which it checks for incoming messages.

- Device periodically wakes up to check for downlink communication.
- It reduces unnecessary receiver activity.
- It consumes less power than continuously monitoring the network.

**Difference between PSM and eDRX:**

| PSM                                                                            | eDRX                                                      |
| ------------------------------------------------------------------------------ | --------------------------------------------------------- |
| Deep sleep mode                                                                | Extended sleep intervals between paging checks            |
| Device is generally unreachable for normal downlink communication while asleep | Device periodically checks for incoming messages          |
| Lower power consumption                                                        | More frequent downlink availability                       |
| Suitable for infrequent communication                                          | Suitable when occasional downlink communication is needed |

### B. Extended Coverage

NB-IoT provides enhanced coverage compared with conventional cellular IoT connectivity.

It can support communication in:

- Basements.
- Underground locations.
- Remote buildings.
- Indoor environments.

This makes it useful for smart meters and underground infrastructure monitoring.

### C. Massive Device Connectivity

NB-IoT is designed to support a large number of connected devices within a cellular network.

### D. Licensed Spectrum

NB-IoT operates in licensed cellular spectrum.

Benefits include:

- Managed spectrum.
- Controlled interference.
- Operator-managed connectivity.
- Cellular-grade security mechanisms.

---

### NB-IoT Technical Specifications

| Parameter         | Details                     |
| ----------------- | --------------------------- |
| Technology        | Cellular LPWAN              |
| Standardization   | 3GPP                        |
| Network           | Cellular                    |
| Frequency         | Licensed spectrum           |
| Bandwidth         | 180 kHz                     |
| Data rate         | Low, typically tens of kbps |
| Power consumption | Low                         |
| Coverage          | Extended coverage           |
| Infrastructure    | Cellular base stations      |
| Applications      | Smart metering, monitoring  |

**Important:** NB-IoT uses a narrow bandwidth of 180 kHz, making it suitable for low-data-rate IoT applications.

---

## 6. Advantages of NB-IoT

1. **Extended Coverage:** Suitable for indoor and underground communication.
2. **Low Power Consumption:** Supports battery-powered devices.
3. **Massive Connectivity:** Supports large numbers of IoT devices.
4. **Licensed Spectrum:** Uses cellular operator-managed spectrum.
5. **Security:** Benefits from cellular authentication and security mechanisms.
6. **Existing Infrastructure:** Can use cellular network infrastructure with suitable NB-IoT support.

## 7. Limitations of NB-IoT

1. Low data transmission rate.
2. Requires cellular network operator support.
3. SIM/eSIM provisioning and connectivity subscriptions may involve costs.
4. Not suitable for high-bandwidth applications.
5. Mobility and roaming support can be more limited than conventional cellular services, depending on network deployment.

---

## 8. Applications of NB-IoT

| Application                | Usage                                 |
| -------------------------- | ------------------------------------- |
| Smart Water Metering       | Monitoring water consumption          |
| Smart Electricity Metering | Automatic electricity readings        |
| Smart Cities               | Parking and infrastructure monitoring |
| Agriculture                | Remote environmental monitoring       |
| Industrial IoT             | Equipment monitoring                  |
| Smart Waste Management     | Monitoring garbage-bin levels         |

---
# Unit 3 – 3.4 Bluetooth Low Energy (BLE)

## 1. What is BLE?

**BLE (Bluetooth Low Energy)** is a wireless communication technology designed to transfer small amounts of data while consuming very little battery power.

It is mainly used for short-range communication between devices.

**Examples:** Smartwatches, fitness bands, wireless sensors and smart locks.

## 2. BLE Architecture

BLE has two main types of devices:

- **Central Device:** Searches for and connects to other BLE devices. Example: Smartphone.
- **Peripheral Device:** Advertises its availability and provides data. Example: Smartwatch.

|Component|Simple meaning|
|---|---|
|Central|Device that searches and connects.|
|Peripheral|Device that makes itself available for connection.|
|GATT|Defines how data is organized and exchanged.|
|GAP|Defines how devices discover and connect to each other.|
|Service|Group of related data.|
|Characteristic|Individual data item, such as heart rate.|

## 3. How does BLE work?

Example: Smartwatch connected to a smartphone.

1. Smartwatch broadcasts an advertisement.
2. Smartphone scans and discovers the smartwatch.
3. Smartphone establishes a connection.
4. Smartphone requests heart-rate data.
5. Smartwatch sends the data.
6. Smartphone displays the reading.

## 4. Important BLE Concepts

**A. Advertising**

A BLE device broadcasts small packets to announce its presence.

**B. Scanning**

Another device listens for these advertising packets to discover nearby devices.

**C. GATT (Generic Attribute Profile)**

Defines how data is structured and exchanged between connected BLE devices.

Example:

A smartwatch may have a Heart Rate Service containing a Heart Rate Measurement Characteristic.

**D. GAP (Generic Access Profile)**

Defines device discovery, advertising and connection procedures.

Remember:

- GAP = Finding and connecting devices.
- GATT = Exchanging organized data.

## 5. Technical Specifications

|Parameter|BLE|
|---|---|
|Standard|Bluetooth|
|Frequency|2.4 GHz|
|Range|Typically 10–100 metres, depending on environment|
|Power consumption|Very low|
|Data rate|Up to 2 Mbps (BLE 5.x PHY)|
|Communication|Wireless|
|Best suited for|Short-range communication|

## 6. Advantages

- Very low battery consumption.
- Easy smartphone integration.
- Low-cost implementation.
- Suitable for wearable devices.
- Supports short-range wireless communication.

## 7. Limitations

- Limited range compared with LPWAN technologies.
- Not suitable for large geographical areas.
- Not designed for high-bandwidth applications.
- 2.4 GHz interference can affect communication.

## 8. Applications

| Application  | Usage                            |
| ------------ | -------------------------------- |
| Smartwatch   | Sending health and activity data |
| Fitness Band | Tracking steps and heart rate    |
| Smart Locks  | Smartphone-based access          |
| Healthcare   | Wireless medical sensors         |
| Retail       | Location-based BLE beacons       |


## Network Topologies

A **network topology** is the arrangement of devices (nodes) and connections in a network. It defines how IoT devices communicate with each other.

There are three important types:

### 1. Star Topology

- All devices connect to one central device (gateway or hub).
- Devices communicate through the central device.
- Devices usually do not communicate directly with each other.

**Working:**

1. Sensor sends data to the gateway.
2. Gateway receives and forwards the data.
3. Gateway sends commands back to devices.

**Advantages:**

- Easy to install and manage.
- Failure of one device doesn't affect others.
- Easy to add new devices.

**Limitations:**

- If the central gateway fails, the entire network stops.
- Gateway handles all communication.

**Example:** Smart home devices connected to a central Wi-Fi router.

### 2. Mesh Topology

- Devices connect with multiple nearby devices.
- Data can travel through multiple paths.
- Devices can forward data for other devices.

**Working:**

1. Sensor A wants to send data to the gateway.
2. It forwards data through Sensor B.
3. Sensor B forwards it to Sensor C.
4. Sensor C delivers it to the gateway.

**Advantages:**

- Multiple communication paths.
- More reliable if one node fails.
- Can cover larger areas through multiple hops.

**Limitations:**

- More complex to configure.
- Routing consumes additional resources.
- More communication overhead.

**Example:** Zigbee-based smart lighting systems.

### 3. Hybrid Topology

- Combination of two or more network topologies.
- Commonly combines star and mesh.
- Different groups of devices can use different connection arrangements.

**Working:**

1. Sensors form a mesh network within a building.
2. A gateway collects data from the mesh.
3. Multiple gateways connect to a central server using a star arrangement.

**Advantages:**

- Flexible and scalable.
- Can combine benefits of star and mesh.
- Suitable for large IoT deployments.

**Limitations:**

- Complex design and management.
- Higher deployment cost.

**Example:** Smart city networks with local mesh-connected sensors and gateways connected to a central cloud.

### Comparison

|Feature|Star|Mesh|Hybrid|
|---|---|---|---|
|Structure|Central hub|Multiple connections|Combination|
|Reliability|Depends on hub|High|Depends on design|
|Complexity|Low|High|High|
|Cost|Usually low|Can be high|Varies|
|Example|Wi-Fi|Zigbee mesh|Smart city|

### Case-study questions: Which topology should you choose?

|Situation|Best choice|Reason|
|---|---|---|
|Smart home with one central router|Star|Simple setup|
|Industrial sensors needing alternate paths|Mesh|Fault tolerance|
|Large smart city with multiple sensor clusters|Hybrid|Scalable architecture|

(Exam tip) Remember: **Star = Central device, Mesh = Multiple paths, Hybrid = Combination.**

### 1. IPv6 – Meaning

**IPv6 (Internet Protocol Version 6)** is the latest version of IP used to assign unique addresses to devices and enable communication over networks.

IoT may contain billions of devices, so IPv6 provides a very large address space.

**Key points:**

- Uses **128-bit addresses**.
- Written in hexadecimal format.
- Provides approximately \(3.4 \times 10^{38}\) unique addresses.
- Supports automatic address configuration.
- Reduces the need for NAT.

**Example IPv6 address:**

```
2001:0db8:85a3:0000:0000:8a2e:0370:7334
```

### 2. 6LoWPAN – Meaning

**6LoWPAN (IPv6 over Low-Power Wireless Personal Area Networks)** allows IPv6 packets to be transmitted over low-power, resource-constrained wireless networks such as IEEE 802.15.4.

In simple words:

IPv6 packets are relatively large, while small IoT devices have limited memory and bandwidth. 6LoWPAN helps them communicate by compressing and adapting IPv6 packets.

### 3. Why do we need 6LoWPAN?

Consider a small battery-powered temperature sensor.

- It has limited processing power.
- It has limited memory.
- It communicates over a low-bandwidth wireless network.
- Normal IPv6 headers create unnecessary overhead.

**Solution:** 6LoWPAN compresses IPv6 headers and adapts packets to the smaller frames supported by IEEE 802.15.4.

### 4. Architecture

```
       IoT Sensor A
             |
       IoT Sensor B
             |
      IEEE 802.15.4
     Wireless Network
             |
        6LoWPAN
        Gateway
             |
       IPv6 Network
             |
       Internet/Cloud
```

**Components:**

|Component|Function|
|---|---|
|IoT Sensors|Generate data|
|IEEE 802.15.4|Provides low-power wireless communication|
|6LoWPAN|Compresses and adapts IPv6 packets|
|Gateway/Border Router|Connects the IoT network to other IPv6 networks|
|Cloud|Stores and processes data|

### 5. How does 6LoWPAN work?

1. Sensor generates data.
2. IPv6 packet is created.
3. 6LoWPAN compresses the IPv6 header.
4. Packet is adapted to fit the wireless frame.
5. Data travels through the low-power wireless network.
6. Border router forwards it to the IPv6 network.

**Important:** 6LoWPAN is an adaptation layer, not a replacement for IPv6.

### 6. Important Features

- IPv6 header compression.
- Packet fragmentation and reassembly.
- Supports low-power wireless devices.
- Enables direct IP-based communication.
- Supports mesh networking arrangements.

### 7. Advantages and Limitations

|Advantages|Limitations|
|---|---|
|Large IPv6 address space|Limited bandwidth|
|Low communication overhead|Limited device resources|
|Internet connectivity for IoT|Fragmentation adds complexity|
|Suitable for battery-powered devices|Requires compatible networking support|

### 8. Applications

- Smart homes
- Smart lighting
- Industrial monitoring
- Smart agriculture
- Wireless sensor networks

### 9. Case Study – Smart Building

Suppose a building has 500 temperature and humidity sensors.

**Problem:** Each sensor needs to send readings to a central monitoring system, but the devices have limited power and bandwidth.

**Solution:** Use IEEE 802.15.4 with 6LoWPAN.

- Sensors communicate using low-power wireless links.
- 6LoWPAN compresses IPv6 headers.
- A border router connects the sensor network to the Internet.
- The cloud collects and analyzes sensor readings.

**Result:** Efficient communication with low-power IoT devices.

### IPv6 vs 6LoWPAN

|IPv6|6LoWPAN|
|---|---|
|Internet addressing protocol|Adaptation layer for IPv6|
|Uses 128-bit addresses|Compresses IPv6 headers|
|Designed for IP networks|Designed for constrained wireless networks|
|Does not specifically optimize for low-power links|Optimizes IPv6 for low-power links|

**Exam tip:** Remember these three points:

- IPv6 = Provides unique addresses.
- IEEE 802.15.4 = Provides low-power wireless communication.
- 6LoWPAN = Makes IPv6 suitable for low-power wireless networks.


## Unit 3.8 – Data Aggregation and IoT Gateways

### 1. Data Aggregation – Meaning

**Data aggregation** is the process of collecting data from multiple IoT devices and combining it into a smaller, meaningful dataset before sending it to the cloud.

**Example:** Instead of sending temperature readings from 100 sensors individually, a gateway calculates the average temperature and sends only the result.

### 2. Why is Data Aggregation Needed?

Imagine a smart city with 1,000 sensors continuously sending data.

Sending every reading directly to the cloud can:

- Increase network traffic.
- Consume more bandwidth.
- Increase cloud storage requirements.
- Increase communication costs and power consumption.

**Solution:** Aggregate data before transmission.

### 3. Types of Data Aggregation

|Technique|Meaning|Example|
|---|---|---|
|Average|Calculates mean value|Average temperature|
|Sum|Adds values|Total water consumption|
|Minimum|Finds lowest value|Minimum room temperature|
|Maximum|Finds highest value|Maximum pressure|
|Filtering|Removes unnecessary data|Ignore duplicate readings|
|Deduplication|Removes repeated records|Remove duplicate sensor messages|

### 4. IoT Gateway – Meaning

An **IoT Gateway** is an intermediate device that connects IoT sensors and devices to external networks, servers, or cloud platforms.

It acts as a bridge between IoT devices and the Internet.

### 5. IoT Gateway Architecture

```
   Sensor 1       Sensor 2       Sensor 3
      |              |              |
      +--------------+--------------+
                     |
                IoT Gateway
             (Data Aggregation)
                     |
             Internet / Network
                     |
                  Cloud
                     |
              User Dashboard
```

### 6. Functions of an IoT Gateway

|Function|Explanation|
|---|---|
|Data Aggregation|Combines data from multiple sensors|
|Protocol Conversion|Converts one protocol into another|
|Data Filtering|Removes unnecessary information|
|Security|Provides authentication and encryption support|
|Edge Processing|Processes data locally|
|Connectivity|Connects local devices to the Internet|

**Example of Protocol Conversion:**

A sensor communicates using Zigbee, but the cloud application uses HTTP.

The gateway receives Zigbee data and forwards it through an IP-based connection using HTTP.

### 7. How does an IoT Gateway work?

1. Sensors collect environmental data.
2. Gateway receives sensor readings.
3. Gateway filters and aggregates the data.
4. It converts protocols if required.
5. Processed data is transmitted to the cloud.
6. Cloud stores and analyzes the data.
7. Users view results through a dashboard.

### 8. Advantages and Limitations

|Advantages|Limitations|
|---|---|
|Reduces network traffic|Gateway can become a single point of failure|
|Saves bandwidth|Additional hardware cost|
|Enables local processing|Requires configuration and maintenance|
|Improves communication security|Gateway itself needs protection|
|Reduces cloud workload|Limited processing capacity|

### 9. Data Aggregation vs IoT Gateway

|Data Aggregation|IoT Gateway|
|---|---|
|A data-processing technique|A hardware/software component|
|Combines multiple readings|Connects IoT devices to external networks|
|Reduces redundant data|Performs multiple functions|
|Can happen inside a gateway|Can perform data aggregation|

### 10. Case Study – Smart Agriculture

**Problem:** A farm has 200 soil-moisture sensors distributed across different locations. Sending every reading directly to the cloud consumes bandwidth and battery power.

**Solution:**

- Sensors send readings to nearby gateways.
- Gateways calculate average soil moisture for each area.
- Unnecessary or duplicate readings are filtered.
- Aggregated data is sent to the cloud.
- If moisture falls below a threshold, an irrigation command is triggered.

**Result:** Reduced network traffic, efficient monitoring, and better water management.

### Important Exam Point

Remember:

- **Data Aggregation:** Combines and summarizes data.
- **IoT Gateway:** Connects devices to networks and performs functions such as protocol conversion, filtering, and local processing.
- **Edge Processing:** Processes data near its source instead of sending everything to the cloud.
--- 
## Unit 3.9 – Case Study: LoRaWAN in Smart Agriculture

### 1. Problem Statement

Consider a large agricultural farm spread across several kilometres.

Farmers need to monitor:

- Soil moisture
- Temperature
- Humidity
- Water levels

**Problem:** Wi-Fi has limited range, and installing cellular connectivity for every sensor can be expensive and power-consuming.

**Solution:** Use **LoRaWAN**, which provides long-range, low-power wireless communication.

### 2. Architecture

```
 Soil Sensors       Weather Sensors
      |                    |
      +---------+----------+
                |
          LoRaWAN Network
                |
             Gateway
                |
          Network Server
                |
         Application Server
                |
          Farmer Dashboard
                |
        Irrigation System
```
### 3. Working

1. Soil sensors measure moisture levels.
2. Sensors transmit readings using LoRa radio communication.
3. LoRaWAN gateways receive the signals.
4. Gateways forward data to the Network Server through the Internet.
5. Network Server manages devices and removes duplicate packets.
6. Application Server processes the sensor data.
7. Farmer views readings on a mobile dashboard.
8. If soil moisture is too low, an irrigation command can be triggered.

### 4. Role of Each Component

| Component             | Function                                            |
| --------------------- | --------------------------------------------------- |
| Sensors               | Collect soil and environmental data                 |
| LoRaWAN Gateway       | Receives sensor signals                             |
| Network Server        | Manages network communication and duplicate packets |
| Application Server    | Processes application data                          |
| Farmer Dashboard      | Displays readings and alerts                        |
| Irrigation Controller | Controls water pumps/valves                         |

### 5. Why LoRaWAN?

- Long communication range.
- Low power consumption.
- Suitable for battery-powered sensors.
- Supports large numbers of IoT devices.
- Does not require Wi-Fi connectivity at every sensor.

### 6. Advantages

- Reduces manual monitoring.
- Saves water through efficient irrigation.
- Supports remote agricultural areas.
- Provides real-time or periodic monitoring.
- Reduces communication costs.

### 7. Limitations

- Low data transmission rate.
- Not suitable for video or large files.
- Downlink communication is more constrained.
- Performance depends on terrain and radio interference.

### 8. Exam-Oriented Case Study Answer

**Question:** A farmer wants to monitor soil moisture across a large farm and automatically control irrigation. Suggest a suitable IoT communication technology and explain its architecture.

**Answer:**

LoRaWAN is suitable because it provides long-range communication with low power consumption.

The architecture consists of:

1. Sensors to collect soil moisture data.
2. Gateways to receive LoRa signals.
3. Network Server to manage communication.
4. Application Server to process data.
5. Dashboard to display information.
6. Irrigation controller to control water supply.

The system continuously monitors soil moisture and triggers irrigation when moisture falls below a predefined threshold.

**Result:** Efficient water usage, reduced manual effort, and remote farm monitoring.


