## 5.1 – IoT Data Lifecycle

### 1. Meaning

The **IoT Data Lifecycle** describes the different stages through which data passes, from collection by sensors to processing, analysis, storage and final action.

In simple words: **Collect → Process → Analyze → Store → Act.**

### 2. Stages of IoT Data Lifecycle

```
       Data Collection
             |
        Transmission
             |
       Data Preprocessing
             |
        Data Storage
             |
       Data Analysis
             |
        Decision Making
             |
          Action
```

| Stage            | Explanation                       | Example                 |
| ---------------- | --------------------------------- | ----------------------- |
| 1. Collection    | Sensors collect raw data          | Temperature readings    |
| 2. Transmission  | Data is sent to gateway/cloud     | MQTT communication      |
| 3. Preprocessing | Removes errors and missing values | Remove invalid readings |
| 4. Storage       | Stores collected data             | Cloud database          |
| 5. Analysis      | Finds patterns using ML           | Detect overheating      |
| 6. Decision      | System decides what to do         | Generate an alert       |
| 7. Action        | Executes the decision             | Turn on cooling system  |

### 3. Role of Machine Learning

Machine Learning helps IoT systems learn patterns from collected data and make predictions or decisions.

**Example – Predictive Maintenance:**

1. Sensors collect machine temperature and vibration.
2. Data is transmitted to a server.
3. ML model analyzes historical readings.
4. Model detects abnormal patterns.
5. System predicts possible machine failure.
6. Maintenance alert is generated.

### 4. Types of IoT Data

| Type             | Example                         |
| ---------------- | ------------------------------- |
| Sensor Data      | Temperature, humidity, pressure |
| Location Data    | GPS coordinates                 |
| Image Data       | CCTV footage                    |
| Audio Data       | Machine sound                   |
| Time-Series Data | Electricity usage every minute  |

### 5. Importance of IoT Data Lifecycle

- Organizes data processing.
- Improves data quality.
- Helps identify useful patterns.
- Supports real-time decision-making.
- Enables predictive maintenance.
- Improves operational efficiency.

### 6. Case Study – Smart Healthcare Monitoring

**Problem:** A hospital wants to continuously monitor patients' heart rate and body temperature.

**Solution:**

1. Wearable sensors collect patient data.
2. Data is transmitted to a gateway.
3. Invalid readings are filtered.
4. Data is stored and analyzed using ML.
5. Abnormal readings trigger alerts.
6. Doctors receive notifications for timely intervention.

**Result:** Continuous monitoring and faster identification of potential health problems.

---
### 1. Data Preprocessing – Meaning

**Data preprocessing** is the process of cleaning and transforming raw IoT data into a usable format before feeding it into a Machine Learning model.

IoT sensors may produce missing, incorrect, duplicated or noisy readings. Preprocessing improves data quality.

### 2. Important Preprocessing Techniques

| Technique              | Meaning                                       | Example                                  |
| ---------------------- | --------------------------------------------- | ---------------------------------------- |
| Missing Value Handling | Fills or removes missing data                 | Replace missing temperature with average |
| Noise Removal          | Removes unwanted variations                   | Filter abnormal sensor readings          |
| Data Normalization     | Scales values to a common range               | Convert values between 0 and 1           |
| Data Standardization   | Scales data using mean and standard deviation | Standardize temperature readings         |
| Data Deduplication     | Removes duplicate records                     | Remove repeated sensor readings          |
| Data Encoding          | Converts categories into numerical values     | Normal = 0, High = 1                     |

**Normalization vs Standardization**

- Normalization usually scales values between 0 and 1.
- Standardization transforms values to have mean 0 and standard deviation 1.

### 3. Feature Engineering – Meaning

**Feature engineering** is the process of selecting, creating or transforming useful input variables (features) to improve Machine Learning model performance.

**Example:**

An IoT machine produces temperature readings every minute.

Raw data:

```
Temperature: 65, 68, 72, 80, 95
```

Possible engineered features:

- Average temperature.
- Maximum temperature.
- Rate of temperature increase.
- Temperature variation.

These features help an ML model identify machine overheating.

### 4. Common Feature Engineering Techniques

| Technique                | Explanation                              | Example                                  |
| ------------------------ | ---------------------------------------- | ---------------------------------------- |
| Feature Selection        | Selects relevant features                | Choose temperature and vibration         |
| Feature Extraction       | Creates useful information from raw data | Extract frequency from vibration signals |
| Aggregation              | Summarizes multiple readings             | Average hourly temperature               |
| Time-based Features      | Extracts time-related information        | Hour, day, weekday                       |
| Dimensionality Reduction | Reduces the number of features           | PCA(Principal Component Analysis)        |

### 5. Preprocessing vs Feature Engineering

|Data Preprocessing|Feature Engineering|
|---|---|
|Cleans raw data|Creates useful features|
|Handles missing values|Extracts patterns|
|Removes noise|Selects important variables|
|Improves data quality|Improves model input|

### 6. Working Pipeline

```
       Raw IoT Sensor Data
                 |
                 v
          Data Cleaning
                 |
                 v
         Noise Removal
                 |
                 v
       Normalization / Scaling
                 |
                 v
        Feature Engineering
                 |
                 v
          ML Model Input
                 |
                 v
            Prediction
```

### 7. Case Study – Predictive Maintenance

**Problem:** A factory wants to predict machine failure using temperature and vibration sensors.

**Solution:**

1. Sensors collect temperature and vibration readings.
2. Missing and duplicate readings are handled.
3. Noisy sensor values are filtered.
4. Data is normalized.
5. Features such as average vibration and maximum temperature are created.
6. ML model uses these features to predict possible machine failure.

**Result:** Early detection of faults and reduced machine downtime.

# Unit 5.3 – Machine Learning Algorithms in IoT

Machine Learning algorithms help IoT systems analyze sensor data, identify patterns and make predictions.

Three important types are:

1. Regression
2. Classification
3. Clustering

## 1. Regression

**Meaning:** Regression is a supervised learning technique used to predict continuous numerical values.

**Example:** Predicting tomorrow's temperature using historical temperature data.

**IoT Applications:**

- Predicting energy consumption.
- Forecasting temperature.
- Estimating machine lifespan.
- Predicting water usage.

**Common algorithms:** Linear Regression, Decision Tree Regression, Random Forest Regression.

## 2. Classification

**Meaning:** Classification is a supervised learning technique used to assign data to predefined categories or classes.

**Example:** Classifying a machine as:

- Normal
- Overheating
- Faulty

**IoT Applications:**

- Detecting abnormal sensor readings.
- Identifying faulty machines.
- Classifying network attacks.
- Identifying healthy/unhealthy conditions.

**Common algorithms:** Logistic Regression, Decision Tree, Random Forest, Support Vector Machine (SVM).

## 3. Clustering

**Meaning:** Clustering is an unsupervised learning technique that groups similar data points without predefined labels.

**Example:** Grouping smart electricity consumers based on their energy consumption patterns.

**IoT Applications:**

- Grouping sensors with similar readings.
- Identifying user behaviour patterns.
- Grouping machines based on performance.
- Detecting unusual data patterns.

**Common algorithms:** K-Means, DBSCAN, Hierarchical Clustering.

---

## 4. Comparison

|Feature|Regression|Classification|Clustering|
|---|---|---|---|
|Learning|Supervised|Supervised|Unsupervised|
|Output|Continuous value|Category/class|Groups/clusters|
|Labels required?|Yes|Yes|No|
|Example|Predict temperature|Detect machine fault|Group consumers|
|Algorithm|Linear Regression|Decision Tree|K-Means|

### Easy way to remember

- **Regression:** How much? → Predict a number.
- **Classification:** Which category? → Predict a class.
- **Clustering:** Which group? → Discover similar groups.

## 5. Case Study – Smart Manufacturing

A factory uses IoT sensors to monitor machines.

|Requirement|Algorithm|Output|
|---|---|---|
|Predict machine temperature|Regression|85°C|
|Detect machine condition|Classification|Faulty|
|Group machines by behaviour|Clustering|Group A, B, C|

**Result:** Better machine monitoring, early fault detection and improved maintenance planning.

---
# 1. Linear Regression

Used to predict continuous values such as temperature, energy consumption and machine performance.

### Formula 1: Simple Linear Regression
$$\boxed{y=mx+c}
$$


| Symbol | Meaning                                   |
| ------ | ----------------------------------------- |
| \(y\)  | Predicted output                          |
| \(x\)  | Input variable                            |
| \(m\)  | Slope of the regression line              |
| \(c\)  | Y-intercept (value of \(y\) when \(x=0\)) |

**Example:**

A model predicts machine temperature:

\[ y=5x+30 \]

If operating hours \(x=6\):

$$ y=5(6)+30=\boxed{60^\circ C}$$

### Formula 2: Slope and Intercept

$$\boxed{m=\frac{n\sum xy-\sum x\sum y} {n\sum x^2-(\sum x)^2}} = \boxed{c=\bar y-m\bar x} $$

| Symbol       | Meaning                                  |
| ------------ | ---------------------------------------- |
| \(n\)        | Number of observations                   |
| \(\sum x\)   | Sum of all input values                  |
| \(\sum y\)   | Sum of all actual output values          |
| \(\sum xy\)  | Sum of products of corresponding x and y |
| \(\sum x^2\) | Sum of squared input values              |
| \(\bar x\)   | Mean of input values                     |
| \(\bar y\)   | Mean of output values                    |

These formulas calculate the best-fit regression line using the least-squares method.

---

# 2. Regression Evaluation Metrics

These formulas measure how accurate a regression model's predictions are.

### Formula 3: Mean Absolute Error (MAE)
$$
 \boxed{MAE=\frac{1}{n}\sum_{i=1}^{n}|y_i-\hat y_i|}
$$

- \(n\) = Number of observations.
- \(y_i\) = Actual value of observation \(i\).
- \(\hat y_i\) = Predicted value of observation \(i\).
- \(|\ |\) = Absolute value (ignores negative signs).
- \(\sum\) = Sum of all errors.

**Example:**

|Actual|Predicted|Absolute Error|
|--:|--:|--:|
|50|52|2|
|60|58|2|
|70|74|4|

\[ MAE=\frac{2+2+4}{3} \]\[ \boxed{MAE=2.67} \]

### Formula 4: Mean Squared Error (MSE)

$$ \boxed{MSE=\frac{1}{n}\sum_{i=1}^{n}(y_i-\hat y_i)^2} $$

The error is squared before calculating the average.

Using the same example:
$$
 MSE=\frac{(50-52)^2+(60-58)^2+(70-74)^2}{3}  =\frac{4+4+16}{3}  =\boxed{MSE=8}
$$
### Formula 5: Root Mean Squared Error (RMSE)

\[ \boxed{RMSE=\sqrt{MSE}} \]

Using the previous result:
$$
 RMSE=\sqrt{MSE}  
 $$
**Important:** Lower MAE, MSE and RMSE generally indicate better prediction accuracy.

### Formula 6: Coefficient of Determination (\(R^2\))
$$
\boxed{R^2=1-\frac{SS_{res}}{SS_{tot}}}
$$
Where:

$$ SS_{res}=\sum(y_i-\hat y_i)^2 , SS_{tot}=\sum(y_i-\bar y)^2 $$

|Symbol|Meaning|
|---|---|
|\(SS_{res}\)|Sum of squared prediction errors|
|\(SS_{tot}\)|Total variation in actual values|
|\(\bar y\)|Mean of actual values|

**Interpretation:**

- \(R^2=1\): Perfect fit.
- \(R^2=0\): No improvement over predicting the mean.
- \(R^2<0\): Model performs worse than predicting the mean.

---

# 3. Logistic Regression – Classification

Used to predict probabilities and classify observations into categories.

### Formula 7: Sigmoid Function

$$\boxed{P(y=1|x)=\frac{1}{1+e^{-z}}} 
$$
Where:
$$
\boxed{z=w_1x_1+w_2x_2+\cdots+w_nx_n+b} 
$$

| Symbol  | Meaning                              |
| ------- | ------------------------------------ |
| (P(y=1  | x))                                  |
| \(e\)   | Euler's number (approximately 2.718) |
| \(z\)   | Weighted sum of input features       |
| \(w_i\) | Weight assigned to feature \(i\)     |
| \(x_i\) | Input feature \(i\)                  |
| \(b\)   | Bias/intercept                       |
| \(n\)   | Number of features                   |

**Example:**

Suppose a model predicts a machine failure probability of:

\[ P=0.85 \]

Using a classification threshold of 0.5:

\[ 0.85>0.5 \]

Prediction = **Machine Failure**.

If probability is below 0.5, prediction = Normal.

### Formula 8: Accuracy

$$\boxed{Accuracy=\frac{TP+TN}{TP+TN+FP+FN}} $$

### Formula 9: Precision

$$\boxed{Precision=\frac{TP}{TP+FP}} $$

### Formula 10: Recall

$$ \boxed{Recall=\frac{TP}{TP+FN}}
$$
### Formula 11: F1-Score

$$\boxed{F1=2\times\frac{Precision\times Recall} {Precision+Recall}}$$

**Understand these symbols:**

|Symbol|Meaning|
|---|---|
|TP|True Positive: Fault correctly detected|
|TN|True Negative: Normal condition correctly detected|
|FP|False Positive: Normal condition incorrectly identified as faulty|
|FN|False Negative: Fault incorrectly identified as normal|

**Example:**

A machine failure detection model produces:

- TP = 40
- TN = 50
- FP = 5
- FN = 5

Accuracy:

$$ Accuracy =\frac{40+50}{40+50+5+5}  =\boxed{90\%}$$

Precision:

$$ =\frac{40}{40+5}=\boxed{88.89\%} $$

Recall:

$$=frac{40}{40+5}=\boxed{88.89\%}
$$
F1-score:

$$ =\boxed{88.89\%}$$

---

# 4. K-Means Clustering

K-Means is an unsupervised learning algorithm that groups similar data points into \(K\) clusters.

### Formula 12: Euclidean Distance
$$
\boxed{d(x,y)=\sqrt{\sum_{i=1}^{n}(x_i-y_i)^2}} $$

|Symbol|Meaning|
|---|---|
|\(d\)|Distance between two points|
|\(x_i\)|Coordinate of first point|
|\(y_i\)|Coordinate of second point|
|\(n\)|Number of dimensions|
|\(\sum\)|Sum of squared differences|

**Example:**

Sensor A = (2, 3)

Sensor B = (5, 7)

$$ d=\sqrt{(5-2)^2+(7-3)^2}  =\sqrt{9+16}=\boxed{5} $$

### Formula 13: Centroid Calculation

$$ \boxed{C_j=\frac{1}{N_j}\sum_{i=1}^{N_j}X_i} 
$$

|Symbol|Meaning|
|---|---|
|\(C_j\)|Centroid of cluster \(j\)|
|\(N_j\)|Number of points in cluster \(j\)|
|\(X_i\)|Data point belonging to the cluster|
|\(\sum\)|Sum of all points|

**Example:**

Three sensors have temperature readings:

\[ 20,\ 25,\ 30 \]

Their cluster centroid is:

$$C=\frac{20+25+30}{3} , \boxed{C=25}$$

### Formula 14: K-Means Objective Function (WCSS)
$$
 \boxed{J=\sum_{j=1}^{K}\sum_{i=1}^{N_j} \|X_i-C_j\|^2}
$$

| Symbol       | Meaning                             |
| ------------ | ----------------------------------- |
| \(J\)        | Total within-cluster sum of squares |
| \(K\)        | Number of clusters                  |
| \(N_j\)      | Number of points in cluster \(j\)   |
| \(X_i\)      | Data point                          |
| \(C_j\)      | Centroid of cluster \(j\)           |
| \(\|\ \|^2\) | Squared Euclidean distance          |

**Purpose:** K-Means tries to minimize the total squared distance between data points and their assigned cluster centroids.

---

# 5. Quick Formula Revision Sheet

| No. | Formula                                | Purpose                      |     |
| --- | -------------------------------------- | ---------------------------- | --- |
| 1   | \(y=mx+c\)                             | Linear regression            |     |
| 2   | Slope formula                          | Calculate regression slope   |     |
| 3   | \(c=\bar y-m\bar x\)                   | Calculate intercept          |     |
| 4   | (MAE=\frac{\sum                        | y_i-\hat y_i                 |     |
| 5   | \(MSE=\frac{\sum(y_i-\hat y_i)^2}{n}\) | Average squared error        |     |
| 6   | \(RMSE=\sqrt{MSE}\)                    | Root mean squared error      |     |
| 7   | \(R^2=1-\frac{SS_{res}}{SS_{tot}}\)    | Regression goodness of fit   |     |
| 8   | \(\frac{1}{1+e^{-z}}\)                 | Logistic regression          |     |
| 9   | \(\frac{TP+TN}{TP+TN+FP+FN}\)          | Accuracy                     |     |
| 10  | \(\frac{TP}{TP+FP}\)                   | Precision                    |     |
| 11  | \(\frac{TP}{TP+FN}\)                   | Recall                       |     |
| 12  | \(2\frac{PR}{P+R}\)                    | F1-score                     |     |
| 13  | Euclidean distance                     | Distance between data points |     |
| 14  | \(C_j=\frac{\sum X_i}{N_j}\)           | Cluster centroid             | $$  |
|15|WCSS objective|K-Means clustering|
---

# Unit 5.4 – Edge AI vs Cloud AI

## 1. What is Edge AI?

**Edge AI** means running AI/ML models directly on devices or nearby edge systems instead of sending all data to a distant cloud server.

Examples:

- A CCTV camera detecting suspicious activity locally.
- A smart vehicle detecting pedestrians.
- A wearable device detecting an abnormal heart rate.

**Working:**

1. Sensors collect data.
2. The edge device processes the data.
3. A trained AI model makes predictions locally.
4. The device takes immediate action.
5. Only important results may be sent to the cloud.

**Architecture:**

`Sensors → Edge Device (AI Model) → Decision/Action`

The cloud may still be used to store data and update models.

## 2. What is Cloud AI?

**Cloud AI** means sending collected data to remote cloud servers, where powerful computing resources run AI/ML models and return predictions.

Examples:

- Uploading medical scans to a cloud AI service for analysis.
- Analysing data from thousands of industrial machines.
- Training large AI models using historical IoT data.

**Working:**

1. Sensors collect data.
2. Data is transmitted through a network.
3. Cloud servers process the data using AI models.
4. Results are sent back to the device or user.
5. Data is stored for further analysis and model improvement.

**Architecture:**

`Sensors → Gateway/Internet → Cloud (AI Model) → Result → Device/User`

## 3. Edge AI vs Cloud AI

|Parameter|Edge AI|Cloud AI|
|---|---|---|
|Processing|Near the data source|Remote cloud servers|
|Latency|Low|Depends on network|
|Internet|Can work offline or with limited connectivity|Usually requires connectivity|
|Computing power|Limited|High|
|Storage|Limited|Large|
|Privacy|Data can remain local|Data may need to be transmitted|
|Bandwidth|Lower network usage|May require high bandwidth|
|Model complexity|Usually smaller models|Can support large models|
|Best suited for|Real-time decisions|Large-scale analysis and training|

**Important:** Edge AI is not necessarily more accurate or more secure than Cloud AI. Performance depends on the model, hardware, network and implementation.

## 4. Edge AI and Cloud AI Together

In practical IoT systems, both are often used together.

**Architecture:**

`IoT Sensors → Edge AI → Cloud AI → Dashboard`

- **Edge AI:** Performs immediate detection and decisions.
- **Cloud AI:** Performs large-scale analysis, model training and long-term storage.

For example, in a smart factory:

- Edge AI detects abnormal machine vibration and stops the machine.
- Cloud AI analyses vibration data from multiple factories to improve predictive maintenance models.

This is called **Edge-Cloud Collaboration**.

## 5. Advantages and Limitations

### Edge AI

**Advantages:**

- Low latency and faster decisions.
- Reduced bandwidth consumption.
- Better control over locally stored data.
- Can operate with limited internet connectivity.

**Limitations:**

- Limited processing power and memory.
- Difficulties updating models across many devices.
- Smaller models may have lower accuracy on complex tasks.
- Hardware constraints increase deployment complexity.

### Cloud AI

**Advantages:**

- High computing and storage capacity.
- Supports complex AI models.
- Easier centralized model management.
- Can analyse data from many devices together.

**Limitations:**

- Network dependency.
- Higher communication latency.
- Bandwidth consumption.
- Data transmission creates privacy and security concerns.

## 6. Numerical Example: Latency Comparison

Suppose an IoT camera needs to detect a pedestrian.

**Cloud AI:**

- Data transmission to cloud = 80 ms
- Cloud processing = 30 ms
- Result transmission back = 80 ms

Total latency:

$$ L_{cloud}=80+30+80=190\text{ ms} $$

**Edge AI:**

- Local processing = 15 ms

$\[ L_{edge}=15\text{ ms} \]$

Therefore, edge AI reduces latency by:

$$\[ \text{Reduction}= \frac{L_{cloud}-L_{edge}}{L_{cloud}}\times100 \]\[ =\frac{190-15}{190}\times100 =92.1\% \]$$

**Symbols:**

- \(L_{cloud}\) = total cloud processing latency.
- \(L_{edge}\) = total edge processing latency.

Edge AI provides approximately **92.1% lower latency** in this example.

## 7. Case Study: Smart Traffic Management

Consider a smart city using AI-enabled cameras to manage traffic.

**Using Edge AI:**

1. Cameras capture vehicle movement.
2. Edge devices detect vehicles and estimate traffic density.
3. Traffic signals are adjusted immediately.
4. Only summarized traffic information is sent to the cloud.

**Using Cloud AI:**

1. Traffic information from multiple locations is collected.
2. Cloud AI analyses city-wide traffic patterns.
3. It predicts congestion during peak hours.
4. Authorities use the predictions for long-term traffic planning.

**Conclusion:** Edge AI handles immediate traffic signal decisions, while Cloud AI handles city-wide analysis and prediction.

---

## 8. Important Exam Points

- Edge AI = AI processing near the data source.
- Cloud AI = AI processing on remote cloud servers.
- Edge AI is preferred for low-latency, real-time applications.
- Cloud AI is preferred for complex computation and large-scale analysis.
- Edge-Cloud Collaboration combines the advantages of both.
- Applications include autonomous vehicles, smart healthcare, industrial automation and smart cities.


# Unit 5.5 – Real-Time Analytics in IoT

## 1. What is Real-Time Analytics?

**Real-time analytics** is the process of collecting, processing and analysing data immediately as it is generated, so that decisions can be made with minimal delay.

In IoT, sensors continuously generate data. Real-time analytics helps systems respond to changing conditions without waiting for all the data to be stored and analysed later.

**Examples:**

- A heart-rate monitor detecting an abnormal heartbeat.
- A smart traffic system adjusting signals based on vehicle density.
- An industrial system detecting machine overheating.
- A security camera identifying suspicious activity.

## 2. Architecture of Real-Time IoT Analytics

`Sensors → Gateway → Stream Processing → Analytics/ML → Decision → Action`

|Component|Function|
|---|---|
|Sensors|Generate real-time data|
|IoT Gateway|Collects and forwards sensor data|
|Stream Processing|Processes incoming data continuously|
|Analytics/ML Engine|Detects patterns, anomalies or predicts outcomes|
|Decision System|Determines what action is required|
|Actuator/Dashboard|Executes an action or displays results|

**Example:** In a smart factory, a temperature sensor continuously sends readings. If the temperature crosses a threshold, the analytics system triggers an alert or activates a cooling system.

## 3. Types of Data Processing

### A. Batch Processing

Data is collected over a period and processed together at a later time.

Example: Analysing a factory's electricity consumption at the end of every day.

**Characteristics:**

- Processes large amounts of stored data.
- Higher processing delay.
- Suitable for historical analysis and reports.

### B. Stream Processing

Data is processed continuously as it arrives.

Example: Detecting abnormal machine vibration immediately.

**Characteristics:**

- Low processing delay.
- Handles continuous data streams.
- Suitable for real-time monitoring and alerts.

|Parameter|Batch Processing|Stream Processing|
|---|---|---|
|Processing|At intervals|Continuously|
|Latency|Higher|Low|
|Data|Stored datasets|Incoming streams|
|Application|Daily reports|Real-time alerts|
|Example|Monthly energy analysis|Live power monitoring|

## 4. Techniques Used in Real-Time Analytics

1. **Threshold-based detection:** Triggers an alert when a reading crosses a predefined limit.  
    Example: Temperature > 80°C triggers an overheating alert.
    
2. **Moving average:** Calculates the average of recent readings to reduce the effect of temporary fluctuations.
    
3. **Anomaly detection:** Identifies unusual patterns that differ from normal behaviour.
    
4. **Predictive analytics:** Uses historical and current data to predict future conditions.
    
5. **Stream processing:** Processes continuous incoming data without waiting for a complete dataset.
    

## 5. Important Formulas

### A. Moving Average

Used to smooth sensor readings and reduce noise.

$$MA=\frac{x_1+x_2+\cdots+x_n}{n} $$

Where:

- \(MA\) = Moving average.
- \(x_i\) = Individual sensor reading.
- \(n\) = Number of readings.

**Example:**

Sensor readings: 20, 22, 24, 26, 28.

\[ MA=\frac{20+22+24+26+28}{5} \]\[ \boxed{MA=24} \]

### B. Data Processing Latency

Measures the time taken to process data and produce a result.

$$L=T_{output}-T_{input}
$$
Where:

- \(L\) = Processing latency.
- \(T_{output}\) = Time when the result is generated.
- \(T_{input}\) = Time when data is received.

Example: Data arrives at 10:00:00.000 and the result is generated at 10:00:00.050.

\[ L=50\text{ ms} \]

### C. Throughput

Measures how much data a system processes per unit of time.

$$Throughput=\frac{\text{Total data processed}}{\text{Time taken}} 
$$
Example: A system processes 10,000 sensor records in 5 seconds.

\[ Throughput=\frac{10000}{5} \]\[ \boxed{2000\text{ records/second}} \]

## 6. Technologies Used

Some commonly used technologies for real-time IoT analytics include:

- **Apache Kafka:** Handles continuous data streams and message distribution.
- **Apache Flink:** Performs stateful stream processing and real-time analytics.
- **Apache Spark Streaming / Structured Streaming:** Processes streaming data using Spark.
- **MQTT:** Lightweight messaging protocol used to transmit IoT data.
- **Redis:** Supports fast in-memory data access and processing.

Remember: MQTT is primarily a communication protocol, whereas Kafka, Flink and Spark provide data-streaming or processing capabilities.

## 7. Case Study: Smart Healthcare Monitoring

Consider a patient wearing a smartwatch that continuously monitors heart rate.

**Working:**

1. Sensors measure heart rate continuously.
2. Data is transmitted to an edge gateway.
3. Real-time analytics examines incoming readings.
4. If the heart rate crosses a defined threshold, the system generates an alert.
5. The alert is sent to the patient or healthcare professional.

**Benefits:**

- Early detection of abnormal conditions.
- Faster medical response.
- Continuous patient monitoring.
- Reduced need for manual monitoring.

---

## 8. Important Exam Points

- Real-time analytics processes data as it arrives.
- Stream processing is suitable for continuous IoT data.
- Batch processing is suitable for historical analysis.
- Moving average reduces fluctuations in sensor readings.
- Latency measures processing delay.
- Throughput measures the amount of data processed per unit time.
- Real-time analytics is used in healthcare, manufacturing, smart cities and transportation.

# Unit 5.6 – Predictive Maintenance in IoT

## 1. What is Predictive Maintenance?

**Predictive Maintenance (PdM)** is a maintenance approach that uses sensor data, machine learning and data analytics to predict when equipment is likely to fail.

Instead of repairing machines only after failure or following a fixed maintenance schedule, predictive maintenance identifies potential problems early.

**Example:** An industrial motor produces unusual vibration and temperature readings. An ML model analyses these readings and predicts that the motor may fail soon.

## 2. Types of Maintenance

|Type|Meaning|Example|
|---|---|---|
|Reactive Maintenance|Repair after failure|Repairing a motor after it stops|
|Preventive Maintenance|Maintenance at fixed intervals|Servicing a motor every 3 months|
|Predictive Maintenance|Maintenance based on predicted failure|Servicing a motor when sensor data indicates possible failure|

**Remember:**

- Reactive = Repair after failure.
- Preventive = Repair at scheduled intervals.
- Predictive = Repair based on condition and prediction.

## 3. Architecture of Predictive Maintenance

`Machine → IoT Sensors → Gateway → Data Processing → ML Model → Prediction → Maintenance Alert`

### Components

1. **Machine:** Industrial equipment being monitored.
2. **Sensors:** Collect machine parameters.
3. **IoT Gateway:** Transfers sensor data to processing systems.
4. **Data Processing:** Cleans data and extracts useful features.
5. **ML Model:** Analyses patterns and predicts failures.
6. **Alert System:** Notifies maintenance engineers.
7. **Maintenance Team:** Inspects and repairs equipment before failure.

## 4. Sensors Used

|Sensor|Purpose|
|---|---|
|Vibration Sensor|Detects abnormal vibration in motors|
|Temperature Sensor|Identifies overheating|
|Pressure Sensor|Monitors pressure variations|
|Acoustic Sensor|Detects unusual machine sounds|
|Current Sensor|Monitors electrical consumption|

Combining multiple sensor readings often provides a better understanding of machine health than using only one sensor.

## 5. Role of Machine Learning

Machine learning helps identify patterns that indicate possible equipment failure.

|ML Technique|Application|
|---|---|
|Classification|Predicts whether a machine is healthy or faulty|
|Regression|Estimates remaining useful life (RUL)|
|Clustering|Groups machines based on operating behaviour|
|Anomaly Detection|Identifies unusual machine behaviour|

### Remaining Useful Life (RUL)

**RUL** is the estimated time remaining before a machine or component is expected to fail or reach the end of its useful life.

For example, if an ML model predicts that a motor has an RUL of 20 days, maintenance can be scheduled before the expected failure.

## 6. Important Formulas

### A. Failure Rate

Failure rate measures how frequently failures occur over a period.

$$\[ Failure\ Rate=\frac{\text{Number of failures}}{\text{Total operating time}} \]$$

**Example:**

A machine experiences 4 failures in 2,000 operating hours.
$$
\[ Failure\ Rate=\frac{4}{2000} = \boxed{0.002\text{ failures/hour}} \]$$

### B. Mean Time Between Failures (MTBF)

MTBF measures the average operating time between failures of a repairable system.

$$\[ MTBF=\frac{\text{Total operating time}}{\text{Number of failures}} \]$$

**Example:**

A machine operates for 2,000 hours and experiences 4 failures.

\[ MTBF=\frac{2000}{4} \]\[ \boxed{500\text{ hours}} \]

### C. Mean Time To Repair (MTTR)

MTTR measures the average time required to repair equipment after a failure.

$$\[ MTTR=\frac{\text{Total repair time}}{\text{Number of repairs}} \]$$

**Example:**

A machine requires 20 hours of total repair time across 4 repairs.

$$\[ MTTR=\frac{20}{4} \]\[ \boxed{5\text{ hours}} \]$$

### D. Equipment Availability

Availability measures the percentage of time equipment is operational.

$$\[ Availability=\frac{MTBF}{MTBF+MTTR}\times100 \]$$

**Example:**

Given:

- MTBF = 500 hours
- MTTR = 5 hours

$$\[ Availability=\frac{500}{500+5}\times100 \]\[ \boxed{99.01\%} \]$$

**Symbols:**

- MTBF = Mean Time Between Failures.
- MTTR = Mean Time To Repair.

### E. Prediction Accuracy

Measures the proportion of correct predictions made by a model.

$\[ Accuracy=\frac{\text{Correct Predictions}}{\text{Total Predictions}}\times100 \]$

**Example:**

An ML model correctly predicts 90 out of 100 machine conditions.

$$\[ Accuracy=\frac{90}{100}\times100 \]\[ \boxed{90\%} \]$$

**Exam note:** In predictive maintenance, accuracy alone may be misleading because machine failures can be rare. Recall is especially important when missing a failure is costly.

## 7. Case Study: Predictive Maintenance in a Smart Factory

Consider a factory that operates hundreds of industrial motors.

**Traditional approach:** The factory services every motor after a fixed interval, even if some motors are functioning perfectly.

**Predictive maintenance approach:**

1. Vibration and temperature sensors continuously monitor motors.
2. Sensor readings are sent to an IoT gateway.
3. Data preprocessing removes noise and extracts features.
4. An ML model analyses the readings.
5. The model detects abnormal vibration and predicts possible failure.
6. A maintenance alert is generated.
7. Engineers inspect and repair the motor before it fails.

**Benefits:**

- Reduces unexpected breakdowns.
- Minimizes maintenance costs.
- Improves equipment availability.
- Increases machine lifespan.
- Reduces production downtime.

## 8. Predictive Maintenance vs Traditional Maintenance

|Parameter|Traditional Maintenance|Predictive Maintenance|
|---|---|---|
|Basis|Fixed schedule or failure|Sensor data and predictions|
|Data usage|Limited|Continuous monitoring|
|Failure detection|Often after failure or at inspection|Before expected failure|
|Cost|Can involve unnecessary servicing|Maintenance can be better targeted|
|Technology|Manual inspection and schedules|IoT, ML and analytics|

---

## 9. Important Exam Points

- Predictive maintenance predicts equipment failure before it occurs.
- IoT sensors collect machine condition data.
- ML models identify abnormal patterns and predict failures.
- RUL estimates remaining useful machine life.
- MTBF measures average operating time between failures.
- MTTR measures average repair time.
- Availability measures the percentage of time equipment remains operational.
- Applications include manufacturing, aviation, power plants and transportation.


# Unit 5 – Self-Study: TinyML and Embedded AI

## 1. What is TinyML?

**TinyML (Tiny Machine Learning)** is the implementation of machine learning models on small, resource-constrained devices such as microcontrollers and embedded systems.

These devices have limited:

- Memory (RAM and Flash).
- Processing power.
- Battery capacity.
- Storage.

TinyML allows devices to perform AI predictions locally without continuously depending on cloud servers.

**Examples:**

- A smartwatch detecting abnormal heart rates.
- A smart microphone detecting a wake word such as "Hey Google".
- A sensor detecting unusual machine vibrations.

## 2. What is Embedded AI?

**Embedded AI** refers to integrating AI capabilities directly into embedded devices or hardware systems.

Examples include:

- AI-powered cameras.
- Smart medical devices.
- Autonomous robots.
- Industrial monitoring systems.

**Relationship:** TinyML is a specialized approach within Embedded AI that focuses on running ML models on highly resource-constrained devices.

## 3. TinyML Architecture

`Sensors → Microcontroller → TinyML Model → Prediction → Action`

### Components

|Component|Function|
|---|---|
|Sensors|Collect real-world data|
|Microcontroller|Processes sensor data|
|TinyML Model|Performs local inference|
|Actuator|Performs an action based on prediction|
|Communication Module|Sends selected data to other systems|

A microcontroller such as an Arduino-compatible board or ESP32 can run a small ML model.

## 4. How TinyML Works

TinyML generally involves two stages:

### A. Model Training

1. Collect sensor data.
2. Clean and preprocess the data.
3. Train an ML model using a computer or cloud platform.
4. Optimize and convert the model for embedded hardware.

### B. Model Deployment and Inference

1. Load the optimized model onto a microcontroller.
2. Collect new sensor readings.
3. Run inference locally.
4. Generate a prediction.
5. Trigger an action if required.

**Important distinction:**

- Training = Learning patterns from data.
- Inference = Using a trained model to make predictions.

TinyML devices generally perform inference locally. Training is often performed on more powerful computers, although some constrained-device learning is possible.

## 5. Techniques Used in TinyML

|Technique|Purpose|
|---|---|
|Quantization|Reduces model size and computational requirements by using lower-precision numbers|
|Pruning|Removes less important model connections or parameters|
|Knowledge Distillation|Transfers knowledge from a large model to a smaller model|
|Model Compression|Reduces storage and memory requirements|
|Feature Extraction|Converts raw sensor data into useful information|

### Example: Quantization

A model may originally use 32-bit floating-point numbers.

Quantization can convert many model weights to 8-bit integers.

This reduces memory requirements and can improve inference efficiency on supported hardware.

## 6. TinyML vs Cloud AI vs Embedded AI

|Parameter|TinyML|Cloud AI|Embedded AI|
|---|---|---|---|
|Processing|Tiny devices|Remote servers|Embedded hardware|
|Resources|Very limited|High|Varies|
|Internet|Not necessarily required|Usually required|Not necessarily required|
|Latency|Usually low|Network-dependent|Depends on hardware|
|Model size|Very small|Can be very large|Varies|
|Example|Smart sensor|Cloud-based image analysis|AI-powered robot|

## 7. Advantages and Limitations

### Advantages

- Low latency due to local inference.
- Reduced internet dependency.
- Lower bandwidth consumption.
- Improved privacy because raw data can remain on the device.
- Suitable for battery-powered IoT devices.

### Limitations

- Limited memory and processing power.
- Supports relatively small models.
- Model updates can be difficult across many devices.
- Hardware compatibility can be challenging.
- Complex model training is generally performed externally.

## 8. Tools and Frameworks

Some commonly used TinyML tools include:

- **TensorFlow Lite for Microcontrollers:** Runs optimized ML models on microcontrollers.
- **Edge Impulse:** Platform for developing and deploying embedded ML applications.
- **Arduino:** Popular embedded development platform.
- **ESP32:** Microcontroller family used in IoT and embedded AI projects.

## 9. Case Study: Smart Agriculture Using TinyML

Consider a smart irrigation system that uses a soil moisture sensor.

**Working:**

1. A soil moisture sensor collects readings.
2. An ESP32 microcontroller receives the readings.
3. A TinyML model analyses soil moisture and environmental conditions.
4. The model predicts whether irrigation is required.
5. The microcontroller activates the water pump.
6. Selected readings can be sent to the cloud for monitoring.

**Benefits:**

- Reduces water wastage.
- Provides faster local decisions.
- Reduces dependence on internet connectivity.
- Supports low-cost agricultural automation.

## 10. Important Exam Points

- TinyML runs ML models on resource-constrained devices.
- Embedded AI integrates AI into embedded hardware.
- TinyML is a subset or specialized area of Embedded AI.
- Inference means making predictions using a trained model.
- Quantization reduces numerical precision and model size.
- Pruning removes less important model parameters.
- TinyML is useful in wearables, agriculture, healthcare and industrial IoT.
