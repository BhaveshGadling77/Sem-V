# Unit 6 – IoT Security Using ML and Deep Learning

## Topic 6.1 – IoT Security Challenges

### 1. Introduction to IoT Security

**IoT Security** refers to protecting IoT devices, communication networks and collected data from unauthorized access, attacks, manipulation and misuse.

IoT devices are often connected to the internet, have limited computing resources and operate continuously. This makes them potential targets for cyberattacks.

**Example:** An attacker gains control of a smart security camera and accesses its video feed without permission.

### 2. Why is IoT Security Important?

IoT systems handle sensitive information and control physical devices.

A security breach can result in:

- Personal data leakage.
- Unauthorized device control.
- Financial losses.
- Disruption of industrial operations.
- Physical safety risks.

For example, hacking a smart electricity meter may allow an attacker to manipulate consumption readings.

## 3. Major IoT Security Challenges

### A. Weak Authentication

Many IoT devices use default or weak passwords.

**Example:** An attacker accesses a camera using its default administrator password.

**Solution:** Strong passwords, multi-factor authentication and device identity verification.

### B. Data Privacy

IoT devices collect sensitive information such as location, health readings and personal activities.

**Example:** A compromised smartwatch exposes a user's health information.

**Solution:** Encryption, access control and data minimization.

### C. Insecure Communication

Data transmitted without proper encryption can be intercepted or modified.

**Example:** An attacker captures unencrypted sensor data transmitted over a wireless network.

**Solution:** Use secure communication protocols such as HTTPS, TLS and DTLS where appropriate.

### D. Limited Device Resources

Many IoT devices have limited CPU, memory and battery capacity. They may not support resource-intensive security mechanisms.

**Example:** A small temperature sensor may struggle with complex security operations.

**Solution:** Lightweight cryptographic algorithms and efficient security protocols.

### E. Firmware Vulnerabilities

Outdated firmware may contain known security weaknesses.

**Example:** An attacker exploits an unpatched vulnerability in a smart home device.

**Solution:** Secure firmware updates, vulnerability patching and signed firmware.

### F. Physical Attacks

IoT devices are often installed in publicly accessible locations.

**Example:** An attacker physically accesses a smart meter and extracts stored information.

**Solution:** Tamper-resistant hardware, secure boot and physical access protection.

### G. Botnet Attacks

Attackers infect multiple IoT devices with malware and control them remotely as a group.

**Example:** Compromised security cameras are used together to launch a DDoS attack.

**Solution:** Device authentication, secure firmware, network monitoring and anomaly detection.

## 4. Common Attacks on IoT Systems

|Attack|Meaning|Example|
|---|---|---|
|DoS|Makes a service unavailable|Flooding a sensor server with requests|
|DDoS|Attack launched from multiple compromised devices|IoT botnet flooding a website|
|Man-in-the-Middle (MITM)|Intercepts or modifies communication|Changing sensor readings during transmission|
|Spoofing|Pretending to be a legitimate device|Fake sensor sending false readings|
|Replay Attack|Reusing previously captured messages|Replaying an old authentication message|
|Malware|Malicious software infects devices|Malware controlling a smart camera|
|Eavesdropping|Secretly monitoring communication|Capturing unencrypted sensor data|

### Important Difference: DoS vs DDoS

- **DoS:** Attack generally originates from a single source.
- **DDoS:** Attack originates from multiple sources, often compromised devices.

## 5. CIA Triad in IoT Security

The CIA Triad represents three fundamental security objectives.

|Principle|Meaning|IoT Example|
|---|---|---|
|Confidentiality|Prevent unauthorized access to data|Encrypting patient health readings|
|Integrity|Prevent unauthorized modification of data|Ensuring temperature readings are not altered|
|Availability|Ensure systems remain accessible|Keeping smart traffic systems operational|

**Easy memory:**

- Confidentiality = Keep data secret.
- Integrity = Keep data correct.
- Availability = Keep systems working.

## 6. Security Mechanisms in IoT

1. **Authentication:** Verifies the identity of a device or user.
2. **Authorization:** Determines what an authenticated entity is allowed to access.
3. **Encryption:** Converts readable data into an unreadable form for unauthorized parties.
4. **Access Control:** Restricts access based on permissions.
5. **Secure Boot:** Ensures that only trusted software runs during device startup.
6. **Firmware Updates:** Fix vulnerabilities and improve device security.
7. **Intrusion Detection:** Identifies suspicious activities in the network or devices.

## 7. Case Study: Smart Home Security

Consider a smart home containing cameras, smart locks and motion sensors.

**Possible threats:**

- Weak passwords allow unauthorized camera access.
- MITM attacks expose sensor communication.
- Malware compromises smart devices.
- A DDoS attack disrupts the home gateway.

**Security measures:**

1. Use strong authentication for all devices.
2. Encrypt communication using secure protocols.
3. Regularly update device firmware.
4. Monitor network traffic for unusual behaviour.
5. Separate IoT devices from sensitive personal devices using network segmentation.

**Conclusion:** IoT security requires protection at the device, communication and application levels.

---

## 8. Important Exam Points

- IoT security protects devices, networks and data.
- Common challenges include weak authentication, privacy, limited resources and outdated firmware.
- Common attacks include DoS, DDoS, MITM, spoofing and replay attacks.
- CIA stands for Confidentiality, Integrity and Availability.
- Authentication verifies identity; authorization determines permissions.
- Encryption protects data during storage or transmission.
- ML-based anomaly detection can help identify suspicious device behaviour.

# Unit 6.2 – Symmetric and Asymmetric Cryptography in IoT

## 1. What is Cryptography?

**Cryptography** is the technique of protecting information by converting readable data (plaintext) into an unreadable form (ciphertext) using mathematical algorithms and keys.

It helps provide:

- **Confidentiality:** Prevents unauthorized people from reading data.
- **Integrity:** Helps detect unauthorized data modification.
- **Authentication:** Helps verify the identity of communicating entities.
- **Non-repudiation:** Provides evidence that a message or action came from a particular entity.

**Example:** A smart health monitor sends a patient's heart rate to a hospital server. Encryption prevents unauthorized parties from reading the transmitted data.

### Basic Encryption Process

`Plaintext → Encryption Algorithm + Key → Ciphertext`

`Ciphertext → Decryption Algorithm + Key → Plaintext`

Where:

- Plaintext = Original readable data.
- Ciphertext = Encrypted, unreadable data.
- Key = Value used by the cryptographic algorithm.

## 2. Symmetric Key Cryptography

**Symmetric cryptography** uses the same secret key for both encryption and decryption.

The sender and receiver must securely share the secret key beforehand.

### Working

1. Sender has the original message.
2. Sender encrypts it using a secret key.
3. Encrypted data is transmitted.
4. Receiver uses the same secret key to decrypt it.
5. Original message is recovered.

**Diagram:**

`Sender → Encryption (Secret Key) → Ciphertext → Decryption (Same Secret Key) → Receiver`

### Example

Suppose a temperature sensor sends data to an IoT gateway.

- Original message: `Temperature = 35°C`
- Both sensor and gateway possess the same secret key.
- Sensor encrypts the message.
- Gateway decrypts it using that same key.

### Common Symmetric Algorithms

|Algorithm|Description|
|---|---|
|AES|Advanced Encryption Standard; widely used|
|DES|Older encryption algorithm; considered insecure|
|3DES|Applies DES multiple times; legacy algorithm|
|ChaCha20|Modern stream cipher|

**AES** is commonly used in IoT because it provides strong security and has efficient hardware implementations on many devices.

## 3. Asymmetric Key Cryptography

**Asymmetric cryptography** uses two mathematically related keys:

1. **Public Key:** Can be shared with others.
2. **Private Key:** Must be kept secret by its owner.

Data encrypted using the recipient's public key can generally be decrypted only using the corresponding private key.

### Working: Confidentiality

Suppose an IoT sensor wants to send confidential information to a cloud server.

1. Cloud server generates a public-private key pair.
2. Server shares its public key with the sensor.
3. Sensor encrypts the message using the server's public key.
4. Encrypted message is transmitted.
5. Server decrypts it using its private key.

**Diagram:**

`Sender → Encrypt (Receiver's Public Key) → Ciphertext → Decrypt (Receiver's Private Key) → Receiver`

### Common Asymmetric Algorithms

|Algorithm|Description|
|---|---|
|RSA|Public-key cryptographic algorithm|
|ECC|Elliptic Curve Cryptography; useful for constrained devices|
|Diffie-Hellman|Establishes a shared secret over an insecure channel|
|ECDH|Elliptic Curve Diffie-Hellman; efficient key agreement|

**Important:** Diffie-Hellman and ECDH are key-agreement methods, not direct message-encryption algorithms.

## 4. Digital Signatures

A **digital signature** verifies the authenticity and integrity of a message.

It uses asymmetric cryptography.

### Working

1. Sender calculates a hash of the message.
2. Sender signs the hash using their private key.
3. Receiver verifies the signature using the sender's public key.
4. Receiver also calculates the message hash.
5. If the hashes match and signature verification succeeds, the message is considered authentic and unchanged.

**Example:** An IoT manufacturer digitally signs firmware updates. Devices verify the signature before installing an update, helping prevent malicious firmware installation.

**Remember:**

- Encryption protects confidentiality.
- Digital signatures help provide authenticity and integrity.

## 5. Symmetric vs Asymmetric Cryptography

|Parameter|Symmetric|Asymmetric|
|---|---|---|
|Keys|One shared secret key|Public and private key pair|
|Speed|Generally faster|Generally slower|
|Computational cost|Lower|Higher|
|Key distribution|Secret key must be shared securely|Public key can be distributed openly|
|Scalability|Key management becomes difficult for many devices|Supports scalable public-key infrastructure|
|Common algorithms|AES, ChaCha20|RSA, ECC|
|IoT usage|Bulk data encryption|Authentication, signatures and key establishment|

### Key Distribution Problem

In symmetric cryptography, two devices must securely obtain the same secret key. Managing unique keys across thousands of IoT devices can be difficult.

Asymmetric cryptography helps solve this problem through public-key-based authentication and key establishment.

## 6. Hybrid Cryptography

In real-world IoT communication, symmetric and asymmetric cryptography are often used together.

This is called **hybrid cryptography**.

### Working

1. Devices authenticate each other using certificates and asymmetric cryptography.
2. They establish a shared symmetric session key using a key-agreement mechanism.
3. They use the symmetric key to encrypt actual data communication.

**Example:** HTTPS/TLS communication between an IoT gateway and a cloud server.

**Why hybrid cryptography?**

- Asymmetric cryptography supports authentication and secure key establishment.
- Symmetric cryptography provides efficient bulk data encryption.

---

## 7. Important Formulas

### A. Number of Symmetric Keys

For \(n\) devices, if every pair needs a unique shared secret key:

\[ K=\frac{n(n-1)}{2} \]

Where:

- \(K\) = Total number of unique keys.
- \(n\) = Number of devices.

**Example:** For 5 devices:

\[ K=\frac{5(5-1)}{2} =\frac{20}{2} \]\[ \boxed{K=10\text{ keys}} \]

This illustrates why symmetric key management becomes difficult as the number of devices increases.

### B. Key Space

For a cryptographic key of \(b\) bits:

\[ N=2^b \]

Where:

- \(N\) = Number of possible keys.
- \(b\) = Key length in bits.

**Example:** AES-128 uses a 128-bit key.

\[ N=2^{128} \]

This represents an extremely large number of possible keys, making brute-force key guessing computationally infeasible with current practical capabilities.

---

## 8. Case Study: Secure IoT Healthcare Monitoring

Consider a wearable health monitor transmitting patient information to a hospital cloud server.

**Working:**

1. The wearable and server authenticate each other.
2. Asymmetric cryptography helps establish a shared session key.
3. AES encrypts heart-rate and health data during transmission.
4. The server decrypts the received information.
5. Digital signatures can verify the authenticity of important software updates.

**Benefits:**

- Protects sensitive patient information.
- Prevents unauthorized data access.
- Helps detect data tampering.
- Supports secure communication between devices.

## 9. Important Exam Points

- Cryptography protects data using algorithms and keys.
- Symmetric cryptography uses the same secret key for encryption and decryption.
- Asymmetric cryptography uses public and private keys.
- AES is a symmetric algorithm.
- RSA and ECC are asymmetric cryptographic techniques.
- Diffie-Hellman and ECDH establish shared secrets.
- Digital signatures provide authenticity and integrity.
- Hybrid cryptography combines asymmetric key establishment with symmetric data encryption.
- ECC is useful in resource-constrained IoT devices because it offers strong security with comparatively smaller keys than RSA.

# Unit 6.3 – Authentication and Access Control in IoT

## 1. What is Authentication?

**Authentication** is the process of verifying the identity of a user, device or system before allowing it to access an IoT network or service.

It answers the question:

**"Who are you?"**

**Example:** A smart home gateway verifies whether a connected smart camera is a genuine registered device before accepting its data.

### Common Authentication Methods

1. **Password-based Authentication:** Uses a username and password.
2. **Token-based Authentication:** Uses tokens to verify identity.
3. **Certificate-based Authentication:** Uses digital certificates to establish device identity.
4. **Biometric Authentication:** Uses fingerprints, face recognition or other biological characteristics.
5. **Multi-Factor Authentication (MFA):** Uses two or more independent authentication factors.

### Three Authentication Factors

|Factor|Meaning|Example|
|---|---|---|
|Something you know|Information you know|Password, PIN|
|Something you have|Physical possession|Security key, phone|
|Something you are|Biological characteristic|Fingerprint, face|

**MFA example:** Logging into a system using a password and a one-time code sent to an authenticator app.

---

## 2. What is Access Control?

**Access Control** is the process of deciding what resources an authenticated user or device is allowed to access and what operations it can perform.

It answers:

**"What are you allowed to do?"**

**Example:** In a smart factory:

- Operator can monitor machine readings.
- Engineer can modify machine settings.
- Administrator can manage users and devices.

### Difference Between Authentication and Authorization

|Authentication|Authorization|
|---|---|
|Verifies identity|Determines permissions|
|Answers who are you?|Answers what can you access?|
|Happens before authorization|Follows successful authentication|
|Example: Login using password|Example: Permission to control a motor|

**Important:** Authentication and authorization are different processes. Successful authentication does not automatically grant access to every resource.

---

## 3. Access Control Models

### A. Discretionary Access Control (DAC)

In DAC, the resource owner decides who can access a resource.

**Example:** A smart home owner allows a family member to access a security camera.

**Advantages:**

- Flexible.
- Easy to manage in small systems.

**Limitation:** Permissions can become difficult to manage in large IoT networks.

### B. Mandatory Access Control (MAC)

In MAC, access is determined by centrally defined security policies and classifications.

Users cannot freely change permissions.

**Example:** A defence IoT system allows access to surveillance data based on security clearance levels.

**Advantages:**

- Strong centralized security.
- Suitable for highly sensitive systems.

**Limitation:** Less flexible and more complex to administer.

### C. Role-Based Access Control (RBAC)

In RBAC, permissions are assigned to roles, and users or devices receive permissions through those roles.

**Example:**

|Role|Permissions|
|---|---|
|Admin|Manage users and devices|
|Engineer|Modify machine settings|
|Operator|View machine readings|
|Guest|Limited read-only access|

**Advantages:**

- Easy permission management.
- Suitable for organizations with multiple users.
- Reduces repetitive permission assignment.

### D. Attribute-Based Access Control (ABAC)

In ABAC, access decisions are made using attributes of the user, resource, action and environment.

**Example:** A hospital doctor can access a patient's health records only when:

- The doctor is assigned to that patient.
- The doctor is authenticated.
- The access request comes from an authorized hospital system.

**Advantages:**

- Highly flexible.
- Supports context-aware access decisions.

**Limitation:** Policies can become complicated to design and manage.

### Comparison

|Model|Access Based On|
|---|---|
|DAC|Resource owner|
|MAC|Central security policies and classifications|
|RBAC|User roles|
|ABAC|Attributes and contextual conditions|

---

## 4. Authentication and Access Control Architecture

`IoT Device/User → Authentication → Authorization → Resource Access`

### Working

1. User or device requests access.
2. Authentication system verifies identity.
3. Authorization system checks permissions.
4. Access is granted or denied.
5. System records the access activity for auditing.

**Example:** A factory engineer logs into an IoT dashboard. The system verifies the engineer's credentials and then checks whether the engineer has permission to change machine parameters.

---

## 5. Important Security Concepts

### A. Identity Management

Managing the identities and credentials of users and IoT devices.

Example: Assigning a unique device identity to every smart electricity meter.

### B. Least Privilege Principle

Every user or device should receive only the minimum permissions required to perform its task.

Example: A temperature sensor should be allowed to send readings but should not be allowed to modify administrator settings.

### C. Mutual Authentication

Both communicating entities verify each other's identities.

Example: An IoT device verifies the cloud server, and the cloud server verifies the IoT device.

### D. Zero Trust Security

Zero Trust follows the principle:

**"Never trust, always verify."**

Every access request is verified instead of automatically trusting devices because they are already connected to the network.

---

## 6. Case Study: Smart Hospital Access Control

Consider a hospital using IoT devices to monitor patients.

**Devices:**

- Wearable health monitors.
- Patient monitoring systems.
- Doctor dashboards.
- Hospital servers.

**Working:**

1. Each IoT device has a unique identity.
2. Devices authenticate themselves before connecting.
3. Doctors log in using secure authentication.
4. RBAC assigns permissions based on roles.
5. Doctors can access assigned patient records.
6. Administrators manage users and device permissions.
7. All important access events are logged.

**Benefits:**

- Prevents unauthorized access to patient records.
- Protects sensitive health information.
- Restricts access according to job responsibilities.
- Improves accountability and security.

---

## 7. Important Exam Points

- Authentication verifies identity.
- Authorization determines access permissions.
- MFA uses two or more independent authentication factors.
- DAC: Resource owner controls access.
- MAC: Central security policies control access.
- RBAC: Access depends on assigned roles.
- ABAC: Access depends on attributes and context.
- Least privilege grants minimum necessary permissions.
- Mutual authentication verifies both communicating entities.
- Zero Trust requires verification for every access request


# Unit 6.4 – Blockchain in IoT Security

## 1. What is Blockchain?

**Blockchain** is a distributed digital ledger that stores information in blocks connected together using cryptographic hashes.

Each block contains data and a reference (hash) to the previous block, forming a chain.

Once data is added and confirmed by the network, changing it becomes extremely difficult because modifications can be detected by other participants.

**Example:** In a smart electricity grid, blockchain can maintain a shared record of electricity transactions between consumers and producers.

## 2. How Blockchain Works

### Components of Blockchain

|Component|Function|
|---|---|
|Block|Stores transactions or records|
|Hash|Unique cryptographic fingerprint of data|
|Previous Hash|Links a block to the previous block|
|Distributed Ledger|Shared copy of transaction records|
|Nodes|Computers participating in the network|
|Consensus Mechanism|Helps nodes agree on valid transactions|
|Smart Contract|Automatically executes predefined rules|

### Working Steps

1. An IoT device generates a transaction or data record.
2. The transaction is submitted to the blockchain network.
3. Network nodes validate the transaction.
4. A consensus mechanism helps the network agree on its validity.
5. The validated transaction is added to a block.
6. The block is linked to the previous block using its hash.
7. Participants maintain synchronized copies of the ledger.

**Important:** Blockchain does not necessarily store all raw IoT sensor data. Large data is often stored off-chain, while blockchain stores hashes, timestamps or references.

## 3. Important Blockchain Concepts

### A. Hashing

Hashing converts input data into a fixed-length output called a hash.

For example, SHA-256 generates a 256-bit hash.

Properties:

- Same input produces the same hash.
- A small input change produces a significantly different hash.
- It is computationally infeasible to recover the original input from a secure hash alone.

**Example:**

If a temperature record is modified from 30°C to 35°C, its hash changes. This helps detect tampering.

### B. Distributed Ledger

A distributed ledger is a database shared across multiple network participants.

Instead of relying on a single central authority, multiple nodes maintain copies of the records.

### C. Consensus Mechanism

A consensus mechanism is a method through which blockchain participants agree on which transactions or blocks are valid.

Common mechanisms:

|Mechanism|Working|
|---|---|
|Proof of Work (PoW)|Participants solve computational puzzles|
|Proof of Stake (PoS)|Validators are selected based on their stake and protocol rules|
|Practical Byzantine Fault Tolerance (PBFT)|Nodes exchange messages to reach agreement despite some faulty or malicious nodes|

**IoT consideration:** Lightweight or permissioned consensus mechanisms are generally more suitable for IoT environments than energy-intensive Proof of Work.

### D. Smart Contracts

Smart contracts are programs stored and executed on a blockchain when predefined conditions are satisfied.

**Example:** A smart electricity meter records energy consumption. A smart contract can automatically calculate the amount payable according to predefined pricing rules.

---

## 4. Role of Blockchain in IoT Security

### A. Data Integrity

Blockchain's hash-linked records help detect unauthorized modifications.

### B. Decentralization

Distributed records reduce dependence on a single central database.

### C. Device Identity Management

Blockchain can maintain records of registered IoT devices and their identities.

### D. Secure Transactions

It can maintain tamper-evident records of transactions between IoT devices.

### E. Traceability

Transactions can be tracked through an auditable history.

## 5. Blockchain Architecture in IoT

`IoT Devices → IoT Gateway → Blockchain Network → Distributed Ledger`

**Working:**

1. IoT sensors generate data.
2. Gateway collects and prepares the data.
3. A transaction containing relevant information is submitted.
4. Blockchain nodes validate it.
5. Consensus is reached.
6. The transaction is added to the ledger.
7. Authorized participants can verify the record.

## 6. Advantages and Limitations

### Advantages

- Improves data integrity.
- Provides transparent and auditable records.
- Reduces dependence on a single central authority.
- Supports secure device identity management.
- Enables automated transactions using smart contracts.

### Limitations

- Blockchain can introduce processing and communication overhead.
- Some consensus mechanisms consume significant energy.
- Storage requirements can grow over time.
- Transaction processing may introduce latency.
- Public blockchain transactions may expose metadata.
- Blockchain cannot guarantee that the original sensor data was truthful.

**Important exam point:** Blockchain can protect the integrity of recorded data, but it cannot automatically verify whether a sensor was faulty or compromised when the data was generated. This is sometimes called the _garbage-in, garbage-out problem_.

---

## 7. Public vs Private Blockchain

|Parameter|Public Blockchain|Private Blockchain|
|---|---|---|
|Access|Generally open|Restricted|
|Control|Decentralized|Managed by an organization|
|Participants|Anyone meeting protocol requirements|Authorized participants|
|Speed|Depends on network and consensus|Often faster in controlled environments|
|IoT suitability|Public applications|Industrial and enterprise IoT|

**Example:**

- Public: Ethereum.
- Private/permissioned: Hyperledger Fabric.

## 8. Case Study: Smart Electricity Grid

Consider a smart electricity grid where households can generate electricity using solar panels and sell excess energy to other consumers.

**Working:**

1. Smart meters measure electricity generation and consumption.
2. Meter readings are sent through IoT gateways.
3. Transaction details are submitted to a permissioned blockchain.
4. Network participants validate transactions.
5. Smart contracts calculate payments.
6. Transactions are recorded in the distributed ledger.

**Benefits:**

- Transparent electricity transactions.
- Tamper-evident billing records.
- Automated payments.
- Improved traceability.
- Reduced dependence on a single transaction database.

---

## 9. Important Formulas

### A. Hash Size

For SHA-256:

\[ Hash\ Size=256\text{ bits} \]

Converting into bytes:

\[ \frac{256}{8}=32\text{ bytes} \]

Where:

- 256 = Number of hash output bits.
- 8 = Number of bits in one byte.

### B. Basic Block Structure

A simplified block header may contain:

\[ Block\ Header=(Previous\ Hash,\ Timestamp,\ Nonce,\ Merkle\ Root) \]

Where:

- Previous Hash = Hash of the previous block.
- Timestamp = Time of block creation.
- Nonce = Value used in some consensus mechanisms.
- Merkle Root = Single hash representing the block's transaction hashes.

The actual block structure depends on the blockchain implementation.

**Remember:** Blockchain questions are more likely to test architecture, working, consensus and applications than lengthy numerical calculations.

---

## 10. Important Exam Points

- Blockchain is a distributed digital ledger.
- Blocks are linked using cryptographic hashes.
- Hashing helps detect data modification.
- Consensus mechanisms help participants agree on valid records.
- Smart contracts automatically execute predefined rules.
- Public blockchains are generally open; private blockchains restrict participation.
- Blockchain improves traceability and data integrity.
- It does not guarantee that sensor data is originally accurate.
- Permissioned blockchain can be useful in industrial IoT.


# Unit 6.5 – Anomaly Detection in IoT Security

## 1. What is Anomaly Detection?

**Anomaly Detection** is the process of identifying unusual patterns or behaviour that differ significantly from normal system behaviour.

In IoT security, it helps detect suspicious activities, compromised devices, abnormal network traffic and potential cyberattacks.

**Example:** A smart electricity meter normally sends 10 messages per minute. Suddenly, it starts sending 1,000 messages per minute. An anomaly detection system can identify this unusual behaviour.

## 2. Why is Anomaly Detection Needed in IoT?

IoT networks contain thousands of connected devices that continuously exchange data.

Traditional security systems may struggle to identify new or unusual attack patterns.

Anomaly detection helps:

- Identify compromised IoT devices.
- Detect unusual network traffic.
- Identify abnormal sensor readings.
- Detect potential malware activity.
- Identify possible DoS and DDoS attacks.
- Monitor device behaviour continuously.

## 3. Types of Anomalies

### A. Point Anomaly

A single data point significantly differs from normal observations.

**Example:** A temperature sensor normally reports 25–35°C but suddenly reports 100°C.

### B. Contextual Anomaly

A data point is unusual only in a particular context, such as time or location.

**Example:** High electricity consumption at midnight may be unusual for a particular building but normal during daytime.

### C. Collective Anomaly

A group or sequence of data points is abnormal when considered together.

**Example:** A device normally sends data every 10 seconds. Suddenly, it sends hundreds of messages in a short period.

### Comparison

|Type|Meaning|Example|
|---|---|---|
|Point|One unusual observation|Sudden temperature spike|
|Contextual|Unusual in a specific context|High night-time traffic|
|Collective|A group of observations is unusual|Repeated suspicious requests|

## 4. Techniques Used for Anomaly Detection

### A. Statistical Methods

Use statistical properties such as mean and standard deviation to identify unusual values.

**Example:** Detecting temperature readings that are far from the average.

### B. Machine Learning-Based Methods

ML algorithms learn normal behaviour and identify deviations.

Common algorithms:

- Isolation Forest.
- One-Class SVM.
- K-Means.
- DBSCAN.

### C. Deep Learning-Based Methods

Deep learning models learn complex patterns from large datasets.

Common approaches:

- Autoencoders.
- LSTM networks.
- Recurrent Neural Networks (RNNs).

### D. Rule-Based Detection

Uses predefined conditions or thresholds.

**Example:** If failed login attempts exceed 10 within one minute, generate an alert.

---

## 5. Important Anomaly Detection Algorithms

### A. Isolation Forest

Isolation Forest identifies anomalies by isolating observations through randomly selected features and split values.

**Working:**

1. Randomly select a feature.
2. Select a random split value.
3. Divide the data into smaller groups.
4. Repeat until observations are isolated.
5. Observations isolated using fewer splits are more likely to be anomalies.

**Example:** A smart meter suddenly reports extremely high electricity consumption. Isolation Forest may isolate this unusual reading quickly.

**Key point:** Anomalies are generally easier to isolate than normal observations.

### B. One-Class SVM

One-Class Support Vector Machine learns the boundary around normal data.

New observations outside this learned boundary are classified as anomalies.

**Example:** A network security system learns normal IoT device traffic and flags unusual traffic patterns.

### C. K-Means-Based Detection

K-Means groups similar observations into clusters.

Observations far away from their nearest cluster centroid may be treated as anomalies.

**Example:** IoT devices normally generate traffic within certain patterns. A device with significantly different traffic behaviour may be flagged.

### D. Autoencoder

An autoencoder is a neural network that learns to reconstruct its input.

It contains two major parts:

1. **Encoder:** Compresses input data into a smaller representation.
2. **Decoder:** Reconstructs the original input from that representation.

**Working:**

`Input Data → Encoder → Latent Representation → Decoder → Reconstructed Data`

The model is trained mainly on normal data.

If unusual data is given, the reconstruction error may be high, indicating a possible anomaly.

---

## 6. Important Formulas

### A. Z-Score

Z-score measures how far a data point is from the mean in terms of standard deviations.

\[ Z=\frac{x-\mu}{\sigma} \]

Where:

- \(Z\) = Z-score.
- \(x\) = Observed data value.
- \(\mu\) = Mean of the dataset.
- \(\sigma\) = Standard deviation.

**Example:**

Suppose:

- Mean temperature = 30°C.
- Standard deviation = 5°C.
- Observed temperature = 45°C.

\[ Z=\frac{45-30}{5} \]\[ \boxed{Z=3} \]

The reading is 3 standard deviations above the mean and may be considered anomalous.

A common rule is to flag values with \(|Z|>3\), assuming the distribution and application make this threshold appropriate.

### B. Euclidean Distance

Used to measure the distance between an observation and a cluster centroid.

\[ d(x,c)=\sqrt{\sum_{i=1}^{n}(x_i-c_i)^2} \]

Where:

- \(d\) = Euclidean distance.
- \(x_i\) = Feature value of the observation.
- \(c_i\) = Corresponding centroid feature value.
- \(n\) = Number of features.

**Example:**

Observation = (8, 9)

Centroid = (5, 5)

\[ d=\sqrt{(8-5)^2+(9-5)^2} \]\[ =\sqrt{9+16} \]\[ \boxed{d=5} \]

A large distance may indicate unusual behaviour.

### C. Reconstruction Error

Used in autoencoder-based anomaly detection.

\[ MSE=\frac{1}{n}\sum_{i=1}^{n}(x_i-\hat{x}_i)^2 \]

Where:

- \(MSE\) = Mean squared reconstruction error.
- \(n\) = Number of input features.
- \(x_i\) = Original input value.
- \(\hat{x}_i\) = Reconstructed value.

**Example:**

Original data = [10, 20, 30]

Reconstructed data = [10, 18, 35]

\[ MSE=\frac{(10-10)^2+(20-18)^2+(30-35)^2}{3} \]\[ =\frac{0+4+25}{3} \]\[ \boxed{MSE=9.67} \]

If the reconstruction error exceeds a predefined threshold, the input may be classified as anomalous.

---

## 7. Anomaly Detection vs Classification

|Parameter|Anomaly Detection|Classification|
|---|---|---|
|Purpose|Finds unusual behaviour|Assigns predefined categories|
|Training data|Can use mostly normal or unlabeled data|Usually uses labelled data|
|Output|Normal or anomalous|Specific class|
|Example|Detect unusual network traffic|Classify traffic as benign or malicious|

**Important:** Anomaly detection is particularly useful when labelled attack data is limited or new attack patterns may appear.

## 8. Case Study: Detecting a DDoS Attack in a Smart City

Consider a smart city network containing thousands of traffic sensors and surveillance cameras.

**Normal behaviour:**

- Devices send periodic sensor readings.
- Network traffic remains within expected limits.

**Attack scenario:**

- An attacker compromises several IoT cameras.
- These devices start sending a huge volume of requests to the central server.
- Network traffic increases abnormally.

**Working of anomaly detection:**

1. Network monitoring systems collect traffic data.
2. Features such as packet rate, connection frequency and traffic volume are extracted.
3. An ML model learns normal traffic patterns.
4. Unusual traffic is detected.
5. The security system generates an alert.
6. Compromised devices can be isolated or blocked.

**Benefits:**

- Early attack detection.
- Continuous network monitoring.
- Identification of compromised devices.
- Reduced damage from cyberattacks.

---

## 9. Important Exam Points

- Anomaly detection identifies deviations from normal behaviour.
- Three types: Point, Contextual and Collective anomalies.
- Isolation Forest isolates unusual observations using random splits.
- One-Class SVM learns the boundary of normal data.
- K-Means can identify observations far from cluster centroids.
- Autoencoders detect anomalies using reconstruction error.
- Z-score measures deviation from the mean.
- Anomaly detection is useful for detecting unknown or previously unseen attack patterns.
# Unit 6.6 – Intrusion Detection Systems (IDS) in IoT

## 1. What is an Intrusion Detection System (IDS)?

An **Intrusion Detection System (IDS)** is a security mechanism that monitors network traffic, device activities or system events to identify suspicious behaviour and potential cyberattacks.

When an attack is detected, the IDS generates an alert for administrators or other security systems.

**Example:** An IoT network contains 500 smart cameras. If one camera suddenly starts sending an unusually large number of requests, the IDS detects suspicious activity and alerts the administrator.

**Important:** A traditional IDS primarily detects and reports attacks. It does not necessarily block them.

## 2. How IDS Works

**Architecture:**

`IoT Devices → Network Monitoring → Detection Engine → Alert → Administrator`

### Working Steps

1. **Data Collection:** Collects network packets, device logs and system events.
2. **Preprocessing:** Filters and prepares collected data.
3. **Feature Extraction:** Extracts useful information such as packet rate, IP addresses and connection frequency.
4. **Detection Engine:** Analyses data using predefined rules or ML algorithms.
5. **Alert Generation:** Generates alerts when suspicious behaviour is detected.
6. **Response:** Administrators or security systems investigate and take action.

## 3. Types of Intrusion Detection Systems

### A. Network-Based IDS (NIDS)

Monitors network traffic to identify suspicious communication.

**Example:** Detecting unusual traffic between IoT devices and a cloud server.

**Advantages:**

- Monitors multiple devices.
- Detects network-based attacks.
- Provides centralized monitoring.

**Limitation:** Encrypted traffic may limit visibility into message contents.

### B. Host-Based IDS (HIDS)

Monitors activities on an individual device or host.

It examines:

- System logs.
- File modifications.
- Running processes.
- Device activities.

**Example:** Detecting unauthorized changes to the firmware of an IoT gateway.

**Advantages:**

- Monitors individual devices.
- Detects suspicious system-level activities.

**Limitation:** Requires resources on the monitored device.

### C. Wireless IDS (WIDS)

Monitors wireless networks to detect suspicious wireless activities.

**Example:** Detecting an unauthorized access point or suspicious Wi-Fi connection in a smart building.

### Comparison

|IDS Type|Monitors|Example|
|---|---|---|
|NIDS|Network traffic|Unusual packet transmission|
|HIDS|Individual device|Unauthorized file modification|
|WIDS|Wireless network|Rogue Wi-Fi access point|

## 4. IDS Detection Techniques

### A. Signature-Based Detection

Detects attacks by comparing observed activity with a database of known attack patterns or signatures.

**Example:** Identifying network traffic matching a known malware signature.

**Advantages:**

- Effective for known attacks.
- Usually produces fewer false alarms for well-defined signatures.

**Limitations:**

- Cannot reliably detect completely new attacks without suitable signatures.
- Requires regular signature updates.

### B. Anomaly-Based Detection

Learns normal system behaviour and identifies deviations from it.

**Example:** A smart meter normally sends 10 messages per minute but suddenly sends 1,000 messages per minute.

**Advantages:**

- Can identify previously unseen attacks.
- Useful for detecting unusual device behaviour.

**Limitations:**

- May generate false positives.
- Requires suitable training data or baseline behaviour.

### C. Hybrid Detection

Combines signature-based and anomaly-based detection.

**Advantages:**

- Detects known attack patterns.
- Can identify unusual and potentially unknown attacks.
- Provides broader security coverage.

### Comparison

|Parameter|Signature-Based|Anomaly-Based|
|---|---|---|
|Detection method|Known attack signatures|Deviations from normal behaviour|
|Unknown attacks|Limited capability|Can potentially detect|
|Training|Signature database|Normal behaviour baseline/model|
|False positives|Often lower for known signatures|Can be higher|
|Updates|Requires signature updates|Requires model/baseline maintenance|

---

## 5. Role of Machine Learning in IDS

Traditional IDS systems depend heavily on predefined rules and signatures.

ML-based IDS systems learn patterns from network traffic and identify suspicious activities.

### Common ML Algorithms

|Algorithm|Use in IDS|
|---|---|
|Decision Tree|Classifies traffic as normal or malicious|
|Random Forest|Improves classification using multiple decision trees|
|SVM|Separates normal and suspicious traffic|
|K-Means|Groups similar traffic patterns|
|Isolation Forest|Detects unusual network behaviour|
|Neural Networks|Learns complex attack patterns|

### Working of ML-Based IDS

1. Collect network traffic data.
2. Extract features such as packet size, duration and connection frequency.
3. Train an ML model using normal and/or attack data.
4. Feed incoming network traffic to the model.
5. Classify traffic as normal or suspicious.
6. Generate alerts when suspicious activity is detected.

## 6. IDS vs IPS

An important exam distinction:

**IDS (Intrusion Detection System):** Detects suspicious activity and generates alerts.

**IPS (Intrusion Prevention System):** Detects suspicious activity and can automatically block or prevent it.

|Parameter|IDS|IPS|
|---|---|---|
|Full form|Intrusion Detection System|Intrusion Prevention System|
|Main function|Detects attacks|Detects and prevents attacks|
|Action|Generates alerts|Can block malicious traffic|
|Deployment|Often monitors traffic passively|Often placed inline|
|Example|Alerts about suspicious traffic|Blocks suspicious traffic|

**Memory trick:** IDS = Detect, IPS = Detect + Prevent.

## 7. Important Evaluation Metrics

An IDS must be evaluated based on how accurately it detects attacks.

### A. Accuracy

\[ Accuracy=\frac{TP+TN}{TP+TN+FP+FN}\times100 \]

### B. Precision

\[ Precision=\frac{TP}{TP+FP}\times100 \]

### C. Recall / Detection Rate

\[ Recall=\frac{TP}{TP+FN}\times100 \]

### D. False Positive Rate (FPR)

\[ FPR=\frac{FP}{FP+TN}\times100 \]

**Symbols:**

|Symbol|Meaning|
|---|---|
|TP|True Positive: Attack correctly detected|
|TN|True Negative: Normal activity correctly identified|
|FP|False Positive: Normal activity incorrectly flagged as attack|
|FN|False Negative: Attack incorrectly identified as normal|

### Numerical Example

Suppose an IDS analyses 100 network activities:

- TP = 40
- TN = 50
- FP = 5
- FN = 5

**Accuracy:**

\[ =\frac{40+50}{100}\times100 =\boxed{90\%} \]

**Precision:**

\[ =\frac{40}{40+5}\times100 =\boxed{88.89\%} \]

**Recall:**

\[ =\frac{40}{40+5}\times100 =\boxed{88.89\%} \]

**False Positive Rate:**

\[ =\frac{5}{5+50}\times100 =\boxed{9.09\%} \]

**Exam insight:** In IoT security, recall is important because failing to detect a real attack can have serious consequences. However, precision also matters because too many false alerts can overwhelm administrators.

---

## 8. Case Study: IDS in a Smart Factory

Consider a smart factory containing IoT sensors, robotic machines and industrial gateways.

**Threat:** An attacker compromises a sensor and starts sending abnormal network traffic.

**IDS working:**

1. NIDS monitors communication between factory devices.
2. Network features such as packet rate and connection frequency are extracted.
3. An ML model analyses the traffic.
4. Unusual communication patterns are detected.
5. IDS generates an alert.
6. The administrator investigates and isolates the compromised device.

**Benefits:**

- Detects suspicious network activity.
- Identifies compromised devices.
- Supports continuous monitoring.
- Reduces the risk of industrial disruption.

---

## 9. Important Exam Points

- IDS monitors systems and networks to detect intrusions.
- NIDS monitors network traffic.
- HIDS monitors individual devices.
- WIDS monitors wireless networks.
- Signature-based detection identifies known attacks.
- Anomaly-based detection identifies deviations from normal behaviour.
- Hybrid IDS combines both techniques.
- ML improves detection of complex and unusual attacks.
- IDS detects and alerts; IPS can actively prevent attacks.
- Accuracy, precision, recall and FPR evaluate IDS performance.


# Unit 6.7 – Deep Learning in IoT Cybersecurity

## 1. What is Deep Learning?

**Deep Learning (DL)** is a subset of Machine Learning that uses artificial neural networks with multiple layers to learn complex patterns from large amounts of data.

In IoT cybersecurity, deep learning helps identify cyberattacks, detect unusual device behaviour, classify malicious network traffic, and predict potential security threats.

**Example:** In a smart factory, thousands of IoT sensors continuously send network traffic. A deep learning model can learn normal communication patterns and identify suspicious traffic that may indicate a DDoS attack.

## 2. Why is Deep Learning Used in IoT Security?

Traditional security systems often depend on predefined rules or known attack signatures.

Deep learning provides additional capabilities:

1. **Automatic feature extraction:** Learns important patterns directly from raw data.
2. **Unknown attack detection:** Can identify previously unseen attack patterns if they differ from learned normal behaviour.
3. **Complex pattern recognition:** Detects relationships that simpler algorithms may miss.
4. **Real-time threat detection:** Can classify network traffic as it arrives, provided sufficient computing resources are available.
5. **Behaviour analysis:** Learns normal device behaviour and identifies deviations.

## 3. Deep Learning Architectures Used in IoT Security

### A. Artificial Neural Network (ANN)

An ANN consists of interconnected artificial neurons arranged in layers.

Its basic architecture contains:

- **Input Layer:** Receives input features such as packet size, connection duration, and data rate.
- **Hidden Layers:** Learn patterns and relationships from the input.
- **Output Layer:** Produces the final prediction, such as normal or malicious traffic.

**Example:** An ANN classifies network traffic into normal traffic, DDoS attacks, or malware-related traffic.

### B. Convolutional Neural Network (CNN)

CNNs are primarily known for image processing, but they can also analyze network traffic represented as structured data or matrices.

**Working:**

1. Input network traffic data.
2. Convolution layers extract important patterns.
3. Pooling layers reduce dimensionality.
4. Fully connected layers perform classification.
5. Output identifies the traffic category.

**IoT applications:**

- Malware detection.
- Network traffic classification.
- Intrusion detection.
- Wireless signal analysis.

### C. Recurrent Neural Network (RNN)

RNNs are designed to process sequential data.

They maintain information from previous inputs using an internal hidden state.

**Why useful in IoT security?**

IoT devices generate continuous time-series data. RNNs can learn temporal patterns and detect suspicious changes over time.

**Example:** A smart camera normally sends data every few seconds. If it suddenly starts transmitting continuously to an unknown server, an RNN-based model may identify this unusual behaviour.

### D. Long Short-Term Memory (LSTM)

LSTM is a special type of RNN designed to learn long-term dependencies.

It uses three important gates:

|Gate|Function|
|---|---|
|Forget Gate|Decides what old information to discard.|
|Input Gate|Decides what new information to store.|
|Output Gate|Decides what information to pass forward.|

**Applications:**

- Detecting sequential cyberattacks.
- Identifying abnormal device behaviour.
- Analyzing time-series network traffic.
- Predicting potential security threats.

### E. Autoencoders

An autoencoder is a neural network trained to reconstruct its input.

It has two major components:

- **Encoder:** Compresses input data into a smaller representation.
- **Decoder:** Reconstructs the original input from that representation.

**Working in cybersecurity:**

1. Train the autoencoder using normal IoT network traffic.
2. The model learns to reconstruct normal traffic accurately.
3. Provide new network traffic.
4. Calculate reconstruction error.
5. If the error is high, flag the traffic as potentially anomalous.

This is particularly useful for anomaly-based intrusion detection.

## 4. Comparison of Deep Learning Models

|Model|Main Purpose|IoT Security Application|
|---|---|---|
|ANN|General pattern learning|Attack classification|
|CNN|Spatial/local pattern extraction|Traffic and malware classification|
|RNN|Sequential data processing|Behaviour monitoring|
|LSTM|Long-term sequence learning|Detecting sequential attacks|
|Autoencoder|Data reconstruction|Anomaly detection|

**Important exam distinction:**

- CNN → Spatial patterns.
- RNN → Sequential patterns.
- LSTM → Long-term sequential patterns.
- Autoencoder → Reconstruction and anomaly detection.

## 5. Deep Learning-Based Intrusion Detection System

A deep learning-based IDS uses neural networks to detect malicious activities in IoT networks.

### Architecture

**IoT Devices → Data Collection → Preprocessing → Deep Learning Model → Classification → Alert**

### Working

1. **Data Collection:** Collect network traffic from IoT devices.
2. **Preprocessing:** Remove noise, handle missing values, and normalize data.
3. **Feature Extraction:** Extract relevant characteristics such as packet size, protocol, and connection duration.
4. **Model Training:** Train the deep learning model using labelled or normal network data.
5. **Detection:** Analyze incoming traffic.
6. **Classification:** Identify traffic as normal or malicious.
7. **Alert Generation:** Notify the administrator when suspicious activity is detected.

## 6. Deep Learning vs Traditional Machine Learning

|Parameter|Traditional ML|Deep Learning|
|---|---|---|
|Feature extraction|Often requires manual feature engineering|Can learn features automatically|
|Data requirement|Often works with smaller datasets|Usually benefits from larger datasets|
|Computation|Generally lower|Generally higher|
|Model complexity|Comparatively simpler|More complex|
|IoT deployment|Often easier on constrained devices|Can require specialized hardware|
|Examples|Decision Tree, SVM, Random Forest|CNN, RNN, LSTM, Autoencoder|

## 7. Challenges of Deep Learning in IoT Security

1. **Limited Resources:** IoT devices have limited memory, processing power, and battery.
2. **Large Data Requirements:** Deep learning models often require substantial training data.
3. **High Computational Cost:** Training complex models requires significant resources.
4. **Privacy Issues:** Network traffic may contain sensitive user information.
5. **Adversarial Attacks:** Attackers may manipulate input data to fool the model.
6. **False Positives:** Legitimate activities may sometimes be classified as attacks.
7. **Model Updates:** Models must adapt to new attack patterns over time.

### Solutions

- Model compression and quantization.
- Edge AI for local inference.
- Federated learning for collaborative training without centralizing raw data.
- Regular model updates.
- Secure training datasets and adversarial robustness techniques.

## 8. Case Study: Deep Learning-Based Smart Home Security

Consider a smart home containing:

- Smart cameras.
- Motion sensors.
- Smart locks.
- Temperature sensors.

**Problem:** An attacker compromises a smart camera and starts sending unusual network traffic.

**Solution:**

1. The gateway collects network traffic.
2. Preprocessing extracts packet size, frequency, destination IP, and connection duration.
3. An LSTM model analyzes traffic patterns over time.
4. The model detects unusual communication behaviour.
5. The IDS generates an alert.
6. The administrator investigates and blocks the compromised device if necessary.

**Result:** Deep learning helps identify suspicious behaviour and improves the security of the smart home.

---

## 9. Important Formulas

### A. Neuron Output

A basic artificial neuron calculates:

\[ z=\sum_{i=1}^{n}w_ix_i+b \]

The activation function produces:

\[ a=f(z) \]

Where:

- \(x_i\) = Input features.
- \(w_i\) = Corresponding weights.
- \(b\) = Bias.
- \(n\) = Number of inputs.
- \(z\) = Weighted sum.
- \(f\) = Activation function.
- \(a\) = Neuron output.

**Example:**

Suppose:

\[ x_1=2,\quad x_2=3 \]\[ w_1=0.5,\quad w_2=0.2,\quad b=0.1 \]

Then:

\[ z=(0.5\times2)+(0.2\times3)+0.1 \]\[ z=1+0.6+0.1=1.7 \]

Using the sigmoid activation function:

\[ f(z)=\frac{1}{1+e^{-z}} \]\[ a=\frac{1}{1+e^{-1.7}}\approx0.846 \]

The neuron output is approximately **0.846**.

### B. Reconstruction Error

Used in autoencoder-based anomaly detection.

\[ MSE=\frac{1}{n}\sum_{i=1}^{n}(x_i-\hat{x}_i)^2 \]

Where:

- \(n\) = Number of input values.
- \(x_i\) = Original input.
- \(\hat{x}_i\) = Reconstructed input.
- MSE = Mean Squared Error.

**Example:**

Original input:

\[ [10,20,30] \]

Reconstructed input:

\[ [11,19,25] \]\[ MSE=\frac{(10-11)^2+(20-19)^2+(30-25)^2}{3} \]\[ =\frac{1+1+25}{3} \]\[ \boxed{MSE=9} \]

A higher reconstruction error may indicate anomalous activity. The detection threshold is determined during model validation.

---

## 10. Quick Revision

- Deep Learning is a subset of ML based on multilayer neural networks.
- ANN performs general pattern learning.
- CNN extracts spatial/local patterns.
- RNN handles sequential data.
- LSTM learns long-term dependencies using gates.
- Autoencoders reconstruct inputs and help detect anomalies.
- Deep learning-based IDS classifies network traffic and detects attacks.
- Major challenges include computation, memory, privacy, and adversarial attacks.
- Edge AI, quantization, and federated learning can help address deployment challenges.

# Unit 6.8 – Secure Edge Computing: Case Study

**(Final Topic – Internet of Things, Edge Computing, and Data-Driven Networks)**

## 1. What is Secure Edge Computing?

**Secure Edge Computing** is an approach in which data processing, storage, and computation happen close to IoT devices while applying security mechanisms to protect devices, networks, and data.

Instead of sending all data to a centralized cloud server, edge devices or gateways process data locally.

Security mechanisms are applied at both the IoT device and edge infrastructure.

**Example:** In a smart hospital, patient-monitoring sensors send data to a nearby edge server. The edge server analyzes the data locally and sends alerts to doctors without transmitting every reading to the cloud.

## 2. Why is Security Required at the Edge?

Edge computing introduces additional security challenges because computation is distributed across multiple locations.

Major challenges include:

1. **Physical attacks:** Edge devices may be installed in publicly accessible locations.
2. **Unauthorized access:** Attackers may attempt to access edge servers or gateways.
3. **Data interception:** Information transmitted between IoT devices and edge nodes may be intercepted.
4. **Malware attacks:** Compromised edge nodes can spread malicious activities.
5. **Data privacy:** Sensitive information may be exposed during processing or storage.
6. **Resource constraints:** Edge devices often have limited memory, processing power, and battery capacity.

## 3. Architecture of Secure Edge Computing

Consider the following architecture:

```
             IoT Devices
          (Sensors/Actuators)
                  |
                  | Secure Communication
                  |
             Edge Gateway
                  |
          Authentication &
            Encryption
                  |
             Edge Server
          /       |       \
         /        |        \
   Local AI    IDS/IPS   Secure Storage
         \        |        /
          \       |       /
             Cloud Server
                  |
          Central Monitoring
          and Long-term Storage
```

### Components

|Component|Function|
|---|---|
|IoT Devices|Generate data using sensors and actuators.|
|Edge Gateway|Connects IoT devices to edge infrastructure.|
|Authentication|Verifies device and user identities.|
|Encryption|Protects data during transmission and storage.|
|Edge Server|Processes data close to IoT devices.|
|IDS/IPS|Detects and prevents suspicious activities.|
|Cloud Server|Provides centralized storage and large-scale processing.|

## 4. Security Mechanisms Used in Edge Computing

### A. Authentication

Verifies the identity of IoT devices, users, and edge servers.

**Example:** A smart camera must authenticate itself before sending data to an edge gateway.

### B. Encryption

Protects information from unauthorized access.

- Symmetric encryption: AES.
- Asymmetric cryptography: RSA and ECC.
- Secure communication: TLS.

### C. Access Control

Determines which users and devices can access specific resources.

For example:

- Administrator → Full system access.
- Doctor → Patient monitoring information.
- Sensor → Permission to upload readings only.

### D. Intrusion Detection and Prevention

- IDS monitors network traffic and detects suspicious activity.
- IPS can block malicious traffic automatically.

Machine learning and deep learning can improve attack detection.

### E. Secure Boot

Ensures that a device starts using trusted and authenticated software.

It prevents unauthorized or modified firmware from executing during startup.

### F. Secure Firmware Updates

Devices must receive authenticated and integrity-verified firmware updates to fix vulnerabilities.

## 5. Role of Machine Learning in Secure Edge Computing

Machine learning helps identify threats by analyzing network traffic and device behaviour.

|Technique|Application|
|---|---|
|Decision Tree|Classifying normal and malicious traffic|
|Random Forest|Intrusion detection|
|K-means|Grouping device behaviour|
|Isolation Forest|Detecting anomalies|
|CNN|Extracting patterns from network traffic|
|LSTM|Detecting suspicious sequential behaviour|

**Example:** An edge server monitors traffic from smart cameras. An anomaly detection model identifies a sudden increase in outgoing traffic and flags it as a possible DDoS or malware-related activity.

## 6. Edge Security vs Cloud Security

|Parameter|Edge Security|Cloud Security|
|---|---|---|
|Processing location|Near IoT devices|Centralized cloud|
|Latency|Generally lower|Depends on network connectivity|
|Data transmission|Less data may need to be transmitted|More data may be transmitted|
|Physical exposure|Edge devices may be physically accessible|Cloud infrastructure is generally hosted in secured data centres|
|Resources|Often limited|Generally more computing resources|
|Main challenge|Distributed device security|Centralized infrastructure and data security|

**Important:** Edge security and cloud security are complementary. A secure IoT system generally requires both.

---

# 7. Case Study: Secure Edge Computing in a Smart Hospital

### Problem Statement

A smart hospital uses IoT devices to continuously monitor patients.

These devices include:

- Heart-rate sensors.
- Blood-pressure monitors.
- Oxygen-level sensors.
- Smart medical equipment.

Patient information is sensitive. Sending all sensor readings to a distant cloud server may increase latency and expose data during transmission.

### Proposed Solution

The hospital deploys a secure edge computing system.

### Architecture

```
     Patient Monitoring Sensors
                 |
                 |
          Secure Gateway
                 |
          Authentication
                 |
          Encrypted Data
                 |
           Edge Server
          /     |      \
         /      |       \
   Local AI    IDS    Secure DB
         \      |       /
          \     |      /
          Real-time Alerts
                 |
          Authorized Doctor
                 |
            Cloud Server
       (Long-term Data Storage)
```

### Working

**Step 1 – Data Collection**

Sensors continuously collect patient information, such as heart rate and oxygen saturation.

**Step 2 – Secure Transmission**

Sensor data is transmitted to the edge gateway through encrypted communication.

**Step 3 – Authentication**

The gateway verifies the identity of the connected devices.

**Step 4 – Local Processing**

The edge server processes patient readings locally.

**Step 5 – AI-Based Monitoring**

An ML model analyzes patient data and identifies abnormal readings.

**Step 6 – Intrusion Detection**

An IDS monitors network traffic and detects suspicious communication.

**Step 7 – Alert Generation**

If a patient's readings become abnormal, the system immediately alerts medical staff.

**Step 8 – Cloud Synchronization**

Necessary information is securely transmitted to the cloud for long-term storage and analysis.

### Benefits

1. Low latency due to local processing.
2. Improved patient-data privacy.
3. Reduced bandwidth consumption.
4. Faster detection of abnormal patient conditions.
5. Improved protection against unauthorized access.
6. Continued local operation during temporary cloud connectivity failures.

### Limitations

1. Edge devices require regular security updates.
2. Physical attacks on edge infrastructure remain possible.
3. Limited resources restrict complex AI models.
4. Distributed infrastructure makes security management difficult.
5. Compromised edge nodes may expose locally stored data.

---

## 8. Important Formulas

Secure edge computing is primarily conceptual, but numerical questions may involve latency, bandwidth, and encryption.

### A. End-to-End Latency

\[ L_{total}=L_{processing}+L_{transmission}+L_{queueing} \]

Where:

- \(L_{total}\) = Total latency.
- \(L_{processing}\) = Processing delay.
- \(L_{transmission}\) = Transmission delay.
- \(L_{queueing}\) = Queueing delay.

**Example:**

Suppose an edge system has:

- Processing delay = 5 ms.
- Transmission delay = 8 ms.
- Queueing delay = 2 ms.

\[ L_{total}=5+8+2 \]\[ \boxed{L_{total}=15\text{ ms}} \]

### B. Latency Reduction Percentage

\[ \text{Reduction}= \frac{L_{cloud}-L_{edge}}{L_{cloud}}\times100 \]

Where:

- \(L_{cloud}\) = Cloud processing latency.
- \(L_{edge}\) = Edge processing latency.

**Example:**

Cloud latency = 100 ms.

Edge latency = 20 ms.

\[ \text{Reduction}= \frac{100-20}{100}\times100 \]\[ \boxed{80\%} \]

Therefore, edge computing reduces latency by 80%.

### C. Bandwidth Savings

\[ \text{Bandwidth Savings}= \frac{B_{original}-B_{edge}}{B_{original}}\times100 \]

Where:

- \(B_{original}\) = Bandwidth required without edge processing.
- \(B_{edge}\) = Bandwidth required after edge processing.

**Example:**

Original bandwidth = 100 Mbps.

Bandwidth after edge processing = 30 Mbps.

\[ =\frac{100-30}{100}\times100 \]\[ \boxed{70\%} \]

The system saves 70% of bandwidth.

---

## 9. Quick Revision – Important Exam Points

- Secure edge computing processes data near IoT devices while applying security mechanisms.
- Major challenges include physical attacks, unauthorized access, malware, privacy, and limited resources.
- Authentication verifies identity.
- Encryption protects data.
- Access control restricts resource access.
- Secure boot verifies trusted software during startup.
- IDS detects attacks; IPS can prevent them.
- ML and DL help detect abnormal device behaviour.
- Edge computing reduces latency and bandwidth requirements.
- Smart hospitals, smart factories, and smart cities are important applications.
- Edge security and cloud security work together.