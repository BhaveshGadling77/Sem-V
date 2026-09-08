# Edge Computing — Complete Syllabus Summary

## 1. Introduction to Edge Computing

> **Edge Computing** is a computing paradigm in which computation and data processing are moved closer to the location where data is generated or consumed.

### Cloud-Centric vs Edge

```text
Cloud-centric:
IoT Device → Internet → Cloud → Processing → Response

Edge:
IoT Device → Edge Node → Processing → Response
                         ↓
                       Cloud
```

### Why Edge Computing?

Cloud-only systems can have problems with:

- **Latency** — response may take too long.
- **Bandwidth** — huge amounts of raw IoT data consume network bandwidth.
- **Privacy** — sensitive data may need to leave the local environment.
- **Connectivity dependency** — applications may suffer when Internet connectivity is poor.

> **Core idea:** Instead of always taking data to the computation, bring computation closer to the data.

---

## 2. Edge Computing Architecture

```text
┌──────────────┐
│ IoT Devices  │
│ Sensors etc. │
└──────┬───────┘
       ↓
┌──────────────┐
│  Edge Node   │
│ Processing   │
│ Filtering    │
│ Decisions    │
└──────┬───────┘
       ↓
┌──────────────┐
│    Cloud     │
│ Storage      │
│ Analytics    │
│ Heavy Compute│
└──────────────┘
```

### Edge Node

An **Edge Node** is a computing device located close to the IoT devices/data source.

Examples:

- IoT gateway
- Smart router
- Local server
- Industrial computer
- Raspberry Pi
- Smart camera

### Edge Node Functions

**Collect → Filter → Process → Analyze → Decide → Forward**

Example:

```text
Camera → Edge Node → Detect "Person" → Send event to Cloud
```

---

## 3. Edge Data Center

An **Edge Data Center** is a smaller, distributed data-center facility located closer to users/devices than a traditional centralized cloud data center.

```text
IoT Device
    ↓
Edge Node
    ↓
Edge Data Center
    ↓
Cloud Data Center
```

### Edge Node vs Edge Data Center

| Edge Node | Edge Data Center |
|---|---|
| Individual computing device | Computing facility |
| Smaller | Larger |
| Limited/moderate resources | More computing/storage resources |
| Gateway, Raspberry Pi, industrial PC | Regional mini data center |

> **Remember:** Edge Node = nearby computing device; Edge Data Center = nearby computing facility.

---

## 4. Edge vs Fog vs Cloud

### Cloud

- Farther from devices
- Very high computing power
- Huge storage
- Heavy analytics
- ML training
- Higher latency compared with edge

### Fog

- Intermediate layer
- Distributed computing
- Located between edge and cloud
- Can aggregate/process data from multiple edge nodes
- Lower latency than traditional cloud-centric processing

### Edge

- Closest to data source
- Local processing
- Very low latency
- Fast decisions
- Usually more resource constrained

### Easy Memory Trick

> **Edge = closest**  
> **Fog = intermediate**  
> **Cloud = farthest**

| | Edge | Fog | Cloud |
|---|---|---|---|
| Location | Closest | Intermediate | Remote |
| Processing | Local | Distributed/intermediate | Centralized/large-scale |
| Latency | Very low | Low | Higher |
| Resources | Limited | Moderate | Very high |
| Main use | Immediate decisions | Regional coordination | Heavy processing/storage |

> **Note:** Edge/Fog terminology can vary somewhat across literature, but this is the conceptual distinction used for this syllabus.

---

## 5. Real-Time Processing Requirements

Some IoT applications have **strict time constraints**.

### Real-Time Processing

> The system must produce a response within a specified deadline.

Example:

```text
Temperature > 80°C
        ↓
Shutdown machine
        ↓
Must happen within 100 ms
```

```text
Response ≤ 100 ms → Meets requirement
Response > 100 ms → Misses deadline
```

### Real-Time Applications

- Autonomous vehicles
- Industrial robots
- Smart traffic systems
- Emergency systems
- Industrial safety

### Important Point

**Real-time does not simply mean "very fast."**

> It means the response must satisfy the required timing deadline.

---

## 6. RTT and Latency

### Latency

> **Latency** is the delay involved in transmitting data from one point to another.

Example:

```text
Device ─────────→ Cloud
       40 ms
```

Latency = **40 ms**

### RTT (Round Trip Time)

RTT is the time for a request to travel to the destination and the response to return.

```text
Device                    Cloud
  │                         │
  │──── Request ───────────>│
  │                         │
  │<──── Response ──────────│
  │                         │
       ←── RTT ──→
```

If:

```text
Device → Cloud = 40 ms
Cloud → Device = 40 ms

RTT = 80 ms
```

> **Latency = one-way delay**  
> **RTT = there + back**

---

## 7. Latency Optimization

Latency optimization means:

> **Reducing the delay required to process data and produce a response.**

### Main Techniques

#### 1. Move computation closer

```text
Device → Edge
```

instead of:

```text
Device → Internet → Remote Cloud
```

#### 2. Local Processing

```text
Sensor
  ↓
Edge
  ↓
Process
  ↓
Actuator
```

#### 3. Data Filtering

```text
Camera → Edge
          ↓
     Filter data
          ↓
    Important event
          ↓
        Cloud
```

#### 4. Data Aggregation

```text
S1 ─┐
S2 ─┤
S3 ─┼──→ Edge → Aggregated data → Cloud
S4 ─┘
```

### Latency vs Bandwidth

**Latency optimization:** Make the response arrive faster.

**Bandwidth optimization:** Reduce the amount of data transmitted.

They are different, but edge processing can improve both.

---

## 8. Edge AI

### Definition

> **Edge AI** means performing AI/ML processing on or near the edge device instead of sending all data to a remote cloud for AI processing.

**Cloud AI:**

```text
Camera → Cloud → AI → Result
```

**Edge AI:**

```text
Camera → Edge AI → Result
```

### Example: Smart Camera

```text
Camera
   ↓
Edge AI
   ↓
Person detected?
   ↓
YES
   ↓
Send alert
```

The system does not need to upload every frame.

---

## 9. AI Training vs AI Inference

### Training

The AI model learns from a large dataset.

```text
Thousands of images
        ↓
      Training
        ↓
   Trained Model
```

### Inference

Using the trained model to make a prediction.

```text
New image
    ↓
Trained Model
    ↓
"Person detected"
```

### Typical Edge AI Architecture

```text
              CLOUD
                │
          Model Training
                │
          Trained Model
                ↓
            EDGE DEVICE
                │
         Local Inference
                │
                ↓
            IoT System
```

> **Important:** Edge AI does not necessarily mean training the model at the edge. Usually, the model is trained in a powerful environment and **inference is performed at the edge**.

---

## 10. Advantages of Edge AI

### 1. Lower Latency

AI processing happens locally.

### 2. Lower Bandwidth

Only useful results may be sent to the cloud.

### 3. Better Privacy

Sensitive raw data can potentially remain local.

### 4. Better Local Operation

The device can potentially continue making local decisions even if cloud connectivity is temporarily unavailable.

---

## 11. Resource-Constrained Computing

IoT/edge devices often have limited:

- CPU
- RAM
- Storage
- Battery/energy
- Network bandwidth

Example:

```text
Cloud Server              IoT Device
────────────              ──────────
Powerful CPU              Limited CPU
Huge RAM                  Small RAM
Huge storage              Small storage
Continuous power          Battery
High bandwidth            Limited bandwidth
```

Therefore, running a large AI model directly on an IoT device can be difficult.

---

## 12. Handling Resource Constraints

### Model Compression

```text
Large model
     ↓
Compression
     ↓
Smaller model
```

Reduces model size and resource requirements.

### Quantization

Use lower-precision numerical representations.

Example:

```text
32-bit values
      ↓
8-bit values
```

This can reduce memory usage and computation, although excessive quantization may affect accuracy.

### Lightweight Models

Use smaller models designed to work with limited resources.

```text
Huge AI Model
      ↓
High computation

Lightweight AI Model
      ↓
Lower computation
      ↓
Better suited for Edge
```

---

## 13. Complete Edge Computing Picture

```text
                         CLOUD
                 ┌──────────────────┐
                 │ Huge Storage     │
                 │ Heavy Analytics  │
                 │ ML Training      │
                 │ Global Insights  │
                 └────────┬─────────┘
                          ↑
                    Useful Data
                          │
                    FOG / EDGE
                 ┌────────┴─────────┐
                 │ Local Processing │
                 │ Edge AI          │
                 │ Filtering        │
                 │ Aggregation      │
                 │ Fast Decisions   │
                 └────────┬─────────┘
                          ↑
                     Sensor Data
                          │
                    IoT Devices
                 ┌────────┴─────────┐
                 │ Sensors          │
                 │ Embedded System  │
                 │ Actuators        │
                 └──────────────────┘
```

---

## 14. One-Page Memory Map

```text
EDGE COMPUTING
│
├── Architecture
│   ├── IoT Device
│   ├── Edge Node
│   ├── Edge Data Center
│   └── Cloud
│
├── Edge vs Fog vs Cloud
│   ├── Edge → closest
│   ├── Fog → intermediate
│   └── Cloud → remote
│
├── Real-Time Processing
│   └── Meet timing deadlines
│
├── RTT & Latency
│   ├── Latency → one-way delay
│   ├── RTT → there + back
│   └── Optimization → reduce delay
│
├── Edge AI
│   ├── AI at/near edge
│   ├── Lower latency
│   ├── Lower bandwidth
│   └── Better local privacy
│
└── Resource-Constrained Computing
    ├── Limited CPU
    ├── Limited RAM
    ├── Limited storage
    ├── Limited energy
    ├── Model compression
    ├── Quantization
    └── Lightweight models
```

---

## 15. Five Lines to Memorize

1. **Edge Computing:** Bring computation closer to where data is generated.
2. **Edge Node:** A nearby computing device that performs local processing.
3. **Edge vs Fog vs Cloud:** Edge is closest, Fog is intermediate, Cloud is remote.
4. **Real-time:** The response must meet a specified timing deadline; RTT is the round-trip delay.
5. **Edge AI:** Run AI inference near the data source, using efficient techniques because edge devices are resource constrained.
