### 1. What is 5G?

5G is the fifth generation. Compared to 4G it improves three things:

1. Speed: more data per second.
2. Delay: how long a message takes to reach the other side. Less delay means quicker reply.
3. Number of devices: more devices can connect at the same time.

It is important for IoT because billions of devices need to communicate reliably.

### 2. Key Features of 5G

| Feature              | Meaning                                                      |
| -------------------- | ------------------------------------------------------------ |
| High Data Rate       | Supports faster data transmission                            |
| Low Latency          | Reduces communication delay                                  |
| Massive Connectivity | Supports a huge number of connected devices                  |
| High Reliability     | Provides dependable communication                            |
| Network Slicing      | Creates separate virtual networks for different applications |
| Energy Efficiency    | Helps support low-power IoT devices                          |

### 3. Three Major 5G Use Cases

These are extremely important for exams.

|Category|Full Form|Purpose|Example|
|---|---|---|---|
|eMBB|Enhanced Mobile Broadband|High-speed data|4K/8K video streaming|
|URLLC|Ultra-Reliable Low-Latency Communication|Very low delay and high reliability|Autonomous vehicles, remote surgery|
|mMTC|Massive Machine-Type Communications|Connects a huge number of IoT devices|Smart city sensors|
**Easy way to remember:**

- eMBB = High speed.
- URLLC = Low delay + high reliability.
- mMTC = Many devices.

### Basic 5G architecture
![[Pasted image 20261117231102.png]]

![[Pasted image 20261117231116.png]]

### The three features: eMBB, URLLC, mMTC

5G was designed because different things need different qualities. So it has three “modes”:

**eMBB (Enhanced Mobile Broadband)** means very high speed. Think of a very wide water pipe. Lots of water (data) flows at once. Use: HD and 4K video, VR games.

**URLLC (Ultra-Reliable Low-Latency Communication)** means very quick and very dependable. Think of your hand pulling back from a hot pan. The reaction is instant and it must always work. Use: self-driving cars, remote surgery, factory robots. A delay or lost message here can cause an accident.

**mMTC (Massive Machine-Type Communication)** means a huge crowd of devices. Think of a stadium with a million people, where each person whispers one short word now and then. No one needs high speed, but the system must handle everyone. Use: smart meters, farm sensors, city sensors.

For IoT, mMTC and URLLC are the most important.


```
       User Equipment (UE)
      (Mobile / IoT Devices)
               |
               |
          5G Radio Network
             (gNB)
               |
               |
          5G Core Network
         /      |       \
       AMF     SMF      UPF
        |       |        |
   Mobility  Session   Data
  Management Management Forwarding
               |
               |
         Internet / Cloud
```

### 5. Components of 5G Architecture

|Component|Function|
|---|---|
|UE (User Equipment)|Mobile phones and IoT devices|
|gNB (Next Generation Node B)|5G base station that connects devices wirelessly|
|AMF|Handles device registration, authentication-related signalling, and mobility|
|SMF|Manages communication sessions and IP address allocation|
|UPF|Forwards user data between devices and external networks|
|5G Core|Manages network services and communication|

### 6. How Does 5G Work?

1. IoT device connects to a nearby 5G base station (gNB).
2. gNB forwards signalling to the 5G Core.
3. AMF manages device registration and mobility.
4. SMF establishes and manages the data session.
5. UPF forwards user data to the Internet or cloud.
6. Cloud processes the data and sends responses when required.

### 7. Advantages and Limitations

|Advantages|Limitations|
|---|---|
|High data speed|Expensive infrastructure|
|Low latency|Coverage may be limited in some areas|
|Supports massive IoT connectivity|Requires compatible devices|
|High reliability|Deployment and maintenance costs|
|Enables advanced applications|Higher-frequency signals have shorter range|

### 8. Applications of 5G in IoT

- Autonomous vehicles
- Smart cities
- Industrial automation
- Remote healthcare
- Smart factories
- Connected defence systems

### 9. Case Study – Smart Factory

**Problem:** A factory has hundreds of robots, cameras, and sensors. They need fast and reliable communication to coordinate production.

**Solution:** Use a private 5G network.

- Sensors continuously send machine data.
- Robots communicate with control systems.
- Cameras transmit high-resolution video.
- URLLC supports time-critical control.
- eMBB supports high-bandwidth video.
- mMTC supports large numbers of sensors.

**Result:** Faster production, reduced delays, and improved automation.


## Network Slicing

**Network Slicing** is a 5G technology that divides one physical network into multiple independent virtual networks called _network slices_.

Each slice is configured for a specific application with different requirements, such as high speed, low latency, or massive device connectivity.

**Simple example:** One 5G network can support autonomous vehicles, video streaming, and smart 
city sensors simultaneously, while providing different network resources to each.

```
             Physical 5G Infrastructure
                       |
              5G Core + Radio Network
                       |
          +------------+------------+
          |            |            |
       Slice 1      Slice 2      Slice 3
        eMBB         URLLC        mMTC
          |            |            |
      Streaming    Autonomous    Smart City
       /Video       Vehicles      Sensors
```

### 3. Types of Network Slices

|Slice|Purpose|Example|
|---|---|---|
|eMBB|High bandwidth and speed|HD video streaming|
|URLLC|Very low latency and high reliability|Autonomous vehicles|
|mMTC|Massive device connectivity|Smart meters and sensors|

### 4. How Does Network Slicing Work?

1. A physical 5G infrastructure is created.
2. Network resources are divided into virtual slices.
3. Each slice receives specific resources and configurations.
4. Applications connect to their suitable slices.
5. Network management monitors and adjusts resources as needed.

**Example:**

- A video streaming application uses an eMBB slice.
- An autonomous vehicle uses a URLLC slice.
- Thousands of smart meters use an mMTC slice.

All operate on the same physical 5G infrastructure.

### 5. Important Components

| Component         | Function                                |
| ----------------- | --------------------------------------- |
| Network Slice     | Independent logical network             |
| Slice Management  | Creates and manages slices              |
| Network Functions | Provide services within each slice      |
| Orchestrator      | Allocates and manages network resources |
| 5G Core           | Provides core network services          |

### 6. Advantages

- Supports different IoT requirements.
- Better resource utilization.
- Provides application-specific performance.
- Improves flexibility and scalability.
- Allows multiple services to share infrastructure.

### 7. Limitations

- Complex network management.
- Requires advanced infrastructure.
- Security isolation must be maintained.
- Resource allocation can be challenging.

### 8. Applications

- Autonomous vehicles
- Smart cities
- Industrial IoT
- Remote healthcare
- Smart factories
- Defence communication

### 9. Case Study – Smart City

**Problem:** A smart city uses one 5G network for traffic management, CCTV cameras, and smart electricity meters. Each application has different network requirements.

**Solution:** Implement network slicing.

|Application|Network Slice|Requirement|
|---|---|---|
|Traffic control|URLLC|Low latency|
|CCTV cameras|eMBB|High bandwidth|
|Smart meters|mMTC|Massive connectivity|

**Result:** Each application receives suitable network resources without requiring separate physical networks.

---
# Unit 4.3 – Edge Computing Integration with 5G (MEC)

### 1. Meaning

**MEC (Multi-access Edge Computing)** is a technology that brings cloud-like computing and storage resources closer to users and IoT devices, usually near the 5G base station or network edge.

Instead of sending all data to a distant cloud server, data is processed closer to its source.

**Main objective:** Reduce latency, save bandwidth, and enable real-time applications.

### 2. Why is MEC Needed?

Consider an autonomous vehicle detecting an obstacle.

**Without MEC:**

1. Vehicle sends camera data to a distant cloud.
2. Cloud processes the data.
3. Cloud sends instructions back.
4. Network delay may affect the vehicle's response.

**With MEC:**

1. Vehicle sends data to a nearby edge server.
2. Edge server processes it immediately.
3. Vehicle receives instructions with lower delay.

### 3. MEC Architecture

```
        IoT Devices / Vehicles
                  |
                  |
             5G Base Station
                 (gNB)
                  |
          +-------+-------+
          |               |
       MEC Server      5G Core
          |               |
    Local Processing   Internet
          |               |
    Quick Response    Central Cloud
```

### 4. Components

|Component|Function|
|---|---|
|IoT Devices|Generate data|
|gNB|Connects devices to the 5G network|
|MEC Server|Processes data near the network edge|
|5G Core|Manages network connectivity|
|Central Cloud|Provides large-scale storage and processing|

### 5. How Does MEC Work?

1. IoT device generates data.
2. Data travels through the 5G base station.
3. Nearby MEC server receives the data.
4. MEC server processes it locally.
5. Response is sent back to the device.
6. Important data can also be forwarded to the central cloud for long-term storage.

### 6. MEC vs Cloud Computing

|Feature|MEC|Cloud|
|---|---|---|
|Processing location|Near devices|Centralized data centers|
|Latency|Low|Generally higher|
|Response time|Faster for local tasks|Depends on network distance|
|Storage|Limited|Very large|
|Bandwidth usage|Reduces unnecessary cloud traffic|May require more data transmission|
|Best suited for|Real-time applications|Large-scale processing and storage|

### 7. Advantages

- Reduces network latency.
- Supports real-time processing.
- Reduces bandwidth consumption.
- Improves application responsiveness.
- Supports location-aware services.
- Can improve privacy by processing sensitive data locally.

### 8. Limitations

- Requires edge infrastructure.
- Limited computing and storage resources.
- Requires distributed server management.
- Edge nodes also need security protection.

### 9. Applications

- Autonomous vehicles
- Smart traffic management
- Industrial automation
- AR/VR applications
- Remote healthcare
- Smart surveillance

### 10. Case Study – Autonomous Vehicles

**Problem:** Autonomous vehicles must detect obstacles and make decisions quickly. Sending all camera and sensor data to a distant cloud may introduce unacceptable delays.

**Solution:** Use 5G with MEC.

1. Vehicle collects camera and sensor data.
2. Data is transmitted through 5G.
3. Nearby MEC server processes the information.
4. It identifies obstacles and traffic conditions.
5. Instructions are sent back to the vehicle.
6. Historical information can be stored in the cloud.

**Result:** Faster decision-making and improved responsiveness.

## Beyond 5G / 6G
### 1. Meaning

**Beyond 5G (B5G)** refers to advanced technologies that improve 5G through higher speeds, lower latency, better connectivity and intelligent network management.

**6G** is the next generation of wireless communication after 5G. It is expected to integrate AI, advanced sensing, satellite communication and extremely high-speed connectivity.

_Note: 6G is still under research and standardization; its capabilities are expected targets, not guaranteed commercial performance._

### 2. Why do we need B5G and 6G?

5G supports high-speed communication and massive IoT connectivity, but future applications may require:

- Even lower communication delays.
- Higher data rates.
- Connectivity in remote areas.
- Better support for autonomous systems.
- AI-driven network management.

### 3. 5G vs B5G vs 6G

|Feature|5G|B5G / 6G vision|
|---|---|---|
|Speed|Up to 10 Gbps theoretical peak|6G targets much higher speeds|
|Latency|As low as 1 ms in specific conditions|Targets sub-millisecond latency|
|Connectivity|Massive IoT support|Even denser device connectivity|
|Intelligence|AI-assisted features|AI-native network design|
|Coverage|Cellular networks|Cellular + satellite + other networks|

### 4. Important Technologies

| Technology                                  | Meaning                                                         | Application                    |
| ------------------------------------------- | --------------------------------------------------------------- | ------------------------------ |
| AI-native Networks                          | AI helps manage and optimize networks                           | Automatic network optimization |
| THz Communication                           | Uses extremely high-frequency terahertz bands                   | Ultra-high-speed data transfer |
| Integrated Sensing and Communication (ISAC) | Communication signals also help detect objects and surroundings | Smart transportation           |
| Satellite Integration                       | Combines terrestrial and satellite networks                     | Remote-area connectivity       |
| Digital Twins                               | Virtual representations of real-world systems                   | Smart factories and cities     |


### 5. 6G Architecture – Concept

```
       IoT Devices / Vehicles / Robots
                    |
             6G Connectivity
          /         |          \
      Cellular   Satellite    THz Links
          \         |          /
             Intelligent Network
                    |
              Edge Computing
                    |
                Cloud / AI
```

**Working:**

1. Devices generate data.
2. 6G networks provide connectivity.
3. Edge servers process time-sensitive data.
4. AI helps optimize network performance.
5. Cloud systems perform large-scale processing.

### 6. Applications

- Autonomous transportation.
- Smart cities.
- Holographic communication.
- Remote healthcare.
- Smart defence systems.
- Industrial automation.
- Extended reality (XR).

### 7. Case Study – Smart Transportation

**Problem:** Future autonomous vehicles need to communicate with other vehicles, traffic infrastructure and road-monitoring systems.

**Solution:** Use B5G/6G technologies.

- Vehicles exchange information with nearby vehicles.
- ISAC helps detect objects and monitor surroundings.
- Edge computing processes traffic information.
- AI optimizes traffic flow.
- Satellite connectivity can support remote areas.

**Result:** Improved traffic coordination, situational awareness and autonomous transportation.

---

## Quick Revision

- B5G = Evolution and enhancement of 5G.
- 6G = Next-generation wireless communication.
- THz = Extremely high-frequency communication.
- ISAC = Communication + sensing.
- AI-native network = AI integrated into network management.
- Satellite integration = Connectivity beyond traditional cellular coverage.
---

# Unit 4.5 – Applications of 5G in Autonomous Vehicles and Smart Defence

5G provides high-speed connectivity, low latency and reliable communication. These capabilities make it useful in autonomous transportation and defence systems.

## 1. 5G in Autonomous Vehicles

**Autonomous vehicles** are self-driving vehicles that use sensors, cameras, AI and communication networks to navigate without continuous human control.

### How 5G helps

5G enables vehicles to exchange information with other vehicles, road infrastructure and network servers.

**Important concept: V2X (Vehicle-to-Everything)**

| Communication | Meaning                   |
| ------------- | ------------------------- |
| V2V           | Vehicle-to-Vehicle        |
| V2I           | Vehicle-to-Infrastructure |
| V2P           | Vehicle-to-Pedestrian     |
| V2N           | Vehicle-to-Network        |

### Architecture

`Vehicle A <--------> Vehicle B | | +----------+-----------+ | 5G Network | Edge Server | Traffic Management | Cloud Platform`

### Working

1. Vehicle sensors detect nearby objects.
2. Vehicles exchange information using V2X.
3. 5G provides communication with low latency.
4. Edge servers process traffic information.
5. Vehicles receive alerts about obstacles, congestion and accidents.
6. AI helps vehicles make driving decisions.

### Applications

- Collision avoidance.
- Smart traffic management.
- Autonomous driving.
- Emergency vehicle alerts.
- Vehicle platooning (vehicles travelling together in a coordinated group).

---

## 2. 5G in Smart Defence

**Smart Defence** uses advanced technologies such as IoT, AI, drones, robotics and 5G to improve military monitoring, communication and decision-making.

### Architecture

```
    Drones / Cameras / Sensors
                |
                |
           5G Network
                |
          Edge Computing
                |
         Command Centre
                |
          AI Analytics
                |
       Monitoring / Alerts
```

### Working

1. Drones and sensors collect field information.
2. Data is transmitted through 5G networks.
3. Edge servers process time-sensitive information.
4. AI analyzes the collected data.
5. Command centres receive alerts and monitoring updates.
6. Personnel use this information for decision-making.

### Applications

- Border surveillance.
- Drone communication.
- Remote monitoring.
- Military logistics.
- Disaster response.
- Secure communication systems.

---

## 3. Autonomous Vehicles vs Smart Defence

|Feature|Autonomous Vehicles|Smart Defence|
|---|---|---|
|Main purpose|Automated transportation|Defence monitoring and operations|
|Devices|Cars, sensors, traffic signals|Drones, cameras, sensors|
|Communication|V2X|Device-to-command-centre|
|Role of 5G|Low-latency vehicle communication|Fast data transmission|
|Role of Edge|Immediate traffic decisions|Local processing of surveillance data|
|Example|Collision avoidance|Border surveillance|

## 4. Case Study – Smart Traffic Management

**Problem:** A city experiences frequent traffic congestion and road accidents.

**Solution:** Implement a 5G-based intelligent traffic system.

- Road sensors collect traffic data.
- Vehicles communicate with traffic infrastructure.
- 5G transfers information quickly.
- Edge servers analyze traffic conditions.
- AI identifies congestion and potential collisions.
- Traffic signals adjust based on traffic conditions.

**Result:** Better traffic flow, faster emergency response and improved road safety.

---
# Unit 4.6 – MEC in Beyond-5G and 6G Communication

### 1. Meaning

**Mobile Edge Computing (MEC)** brings computing, storage and processing resources closer to mobile users and IoT devices.

In Beyond-5G and 6G, MEC is expected to become more intelligent, distributed and powerful to support applications requiring extremely low latency and high data processing.

### 2. Why is MEC important in 6G?

Future applications generate enormous amounts of data and require quick responses.

Examples:

- Autonomous vehicles need immediate obstacle detection.
- Smart factories need real-time machine control.
- AR/VR requires fast processing to avoid delays.
- Smart defence requires rapid analysis of surveillance data.

Sending all this data to distant cloud servers can introduce delays. MEC processes time-sensitive data locally.

### 3. Architecture

```
       IoT Devices / Vehicles / Robots
                    |
              6G Network
                    |
          +---------+---------+
          |                   |
      Edge Node 1         Edge Node 2
          |                   |
     Local Processing    Local Processing
          |                   |
          +---------+---------+
                    |
              Central Cloud
                    |
              Large-scale AI
               and Storage
```

**Components:**

|Component|Function|
|---|---|
|IoT Devices|Generate data|
|6G Network|Provides connectivity|
|Edge Nodes|Perform nearby processing|
|AI Models|Analyze data and make predictions|
|Central Cloud|Handles large-scale processing and storage|

### 4. MEC Evolution: 5G vs B5G vs 6G

| Feature             | 5G MEC                            | B5G/6G MEC                                    |
| ------------------- | --------------------------------- | --------------------------------------------- |
| Processing          | Near base stations                | More distributed edge locations               |
| Intelligence        | Edge AI support                   | More advanced AI-native processing            |
| Connectivity        | 5G networks                       | Integrated terrestrial and satellite networks |
| Applications        | Smart cities, autonomous vehicles | Holographic communication, advanced robotics  |
| Resource management | Edge resource allocation          | Intelligent, dynamic resource optimization    |

### 5. Important Advancements in 6G MEC

1. **AI-enabled Edge:** AI models run directly on edge servers for faster decisions.
2. **Distributed Computing:** Processing is spread across multiple edge nodes.
3. **Integrated Sensing:** Edge systems process information from communication and sensing technologies.
4. **Edge-Cloud Collaboration:** Edge handles immediate tasks while cloud handles complex computations.
5. **Intelligent Resource Allocation:** AI dynamically allocates computing and network resources.

### 6. Case Study – Autonomous Vehicles

**Problem:** Self-driving vehicles must detect obstacles and respond immediately. Sending all camera and sensor data to distant cloud servers can cause delays.

**Solution using 6G MEC:**

1. Vehicle collects camera and sensor data.
2. Data is transmitted to a nearby edge node.
3. Edge AI processes the data and detects obstacles.
4. Nearby vehicles and infrastructure exchange relevant information.
5. Vehicle receives quick alerts and makes driving decisions.
6. Cloud stores historical data for further analysis.

**Result:** Faster decision-making, reduced dependence on distant cloud processing and improved road safety.

### 7. Advantages and Challenges

|Advantages|Challenges|
|---|---|
|Low latency|Expensive infrastructure|
|Reduced cloud traffic|Limited edge resources|
|Real-time AI processing|Edge security risks|
|Better user experience|Distributed management complexity|
|Supports advanced IoT applications|Requires reliable connectivity|

