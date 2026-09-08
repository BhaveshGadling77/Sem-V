# DBMS --- Chapter 1 & Chapter 6 Complete Study Summary

> **Source:** *Database System Concepts, 5th Edition* --- Silberschatz,
> Korth and Sudarshan\
> **Covered files:** Chapter 1 --- Introduction; Chapter 6 ---
> Entity-Relationship Model\
> **Purpose:** Detailed revision notes containing the concepts,
> definitions, examples, notation, constraints, and relational-schema
> conversion rules presented in the two PPTs.

------------------------------------------------------------------------

# Part I --- Chapter 1: Introduction

## 1. Database Management System (DBMS)

A **Database Management System (DBMS)** is a collection of software and
data-management facilities used to maintain and access a database.

A DBMS contains:

1.  **A collection of interrelated data**
    -   The database stores related pieces of information.
    -   Example: a university database can contain students, courses,
        registrations, grades, etc.
2.  **A set of programs to access the data**
    -   These programs allow users/applications to insert, retrieve,
        update, and manage information.
3.  **An environment that is convenient and efficient to use**
    -   The DBMS hides many low-level storage details and provides
        organized mechanisms for accessing information.

### Database applications

Databases are used in many areas:

-   **Banking:** transactions, accounts, customers.
-   **Airlines:** reservations and schedules.
-   **Universities:** registration and grades.
-   **Sales:** customers, products, purchases.
-   **Online retailers:** order tracking and customized recommendations.
-   **Manufacturing:** production, inventory, orders, supply chain.
-   **Human resources:** employee records, salaries, tax deductions.

**Key idea:** Databases are used in almost every aspect of modern
information systems.

------------------------------------------------------------------------

# 2. Purpose of Database Systems

In the early days, database applications were commonly built directly on
top of **file systems**.

File systems create several important problems.

## 2.1 Data redundancy and inconsistency

The same information may be stored in multiple files.

Example:

-   Customer information appears in `customers.txt`.
-   The same customer information also appears in `orders.txt`.

If the customer's address is updated in one file but not another, the
database becomes inconsistent.

Problems include:

-   Duplication of information.
-   Different file formats.
-   Multiple copies of the same data.
-   Different copies potentially containing different values.

------------------------------------------------------------------------

## 2.2 Difficulty in accessing data

With a file-system approach, every new type of task may require writing
a new program.

Example:

-   Program A finds all customers.
-   Program B finds customers from Pune.
-   Program C finds customers with orders above a certain amount.

A DBMS provides query facilities so users can request data without
writing a completely new program for every query.

------------------------------------------------------------------------

## 2.3 Data isolation

Data may be distributed across:

-   Multiple files.
-   Different file formats.
-   Different application programs.

This makes it difficult to combine and access related information.

------------------------------------------------------------------------

## 2.4 Integrity problems

An **integrity constraint** is a rule that the data must satisfy.

Example:

``` text
account balance > 0
```

In a file-system approach, such rules may become **buried inside
application-program code**.

Problems:

-   Difficult to add new constraints.
-   Difficult to change existing constraints.
-   Different programs may enforce the same rule differently.

A DBMS allows integrity constraints to be specified more systematically.

------------------------------------------------------------------------

## 2.5 Atomicity of updates

A database operation may consist of several changes that together form
one logical operation.

Example: transferring money from Account A to Account B.

Correct behavior:

``` text
Debit A
+
Credit B
```

must either:

-   **Both happen**, or
-   **Neither happens**.

If a failure occurs after debiting A but before crediting B, the
database becomes inconsistent.

A DBMS provides transaction-management mechanisms to handle this
problem.

------------------------------------------------------------------------

## 2.6 Concurrent access by multiple users

Multiple users often need to access the same data simultaneously.

Concurrency is useful for performance, but uncontrolled concurrent
access can cause incorrect results.

Example:

1.  User A reads account balance = ₹1000.
2.  User B also reads balance = ₹1000.
3.  Both update the balance independently.
4.  One update may overwrite the other.

A DBMS uses concurrency-control mechanisms to maintain consistency.

------------------------------------------------------------------------

## 2.7 Security problems

A file-system approach makes it difficult to give users access to
**some** data while restricting access to **other** data.

Example:

-   Employees may see their own records.
-   Managers may see employee salaries.
-   Ordinary users should not see salaries.

A DBMS provides authorization and access-control mechanisms.

------------------------------------------------------------------------

### Overall purpose

Database systems provide solutions for:

-   Data redundancy/inconsistency.
-   Difficulty accessing data.
-   Data isolation.
-   Integrity problems.
-   Atomicity.
-   Concurrent access.
-   Security.

------------------------------------------------------------------------

# 3. Levels of Abstraction

A DBMS hides unnecessary implementation details using different levels
of abstraction.

There are three major levels:

``` text
View Level
    ↓
Logical Level
    ↓
Physical Level
```

## 3.1 Physical level

The **physical level** describes how data is actually stored.

Example:

-   How a customer record is represented on storage.
-   File organization.
-   Storage structures.
-   Access methods.

The user generally does not need to know these details.

------------------------------------------------------------------------

## 3.2 Logical level

The **logical level** describes:

-   What data is stored.
-   Relationships among the stored data.

Example:

``` text
customer(
    customer_id,
    customer_name,
    street,
    customer_city
)
```

At this level we care about the database structure rather than exactly
where bytes are stored.

------------------------------------------------------------------------

## 3.3 View level

The **view level** provides a customized representation of the database.

It can hide:

1.  Details such as data types.
2.  Information that users should not see for security.

Example:

An employee-facing view may hide:

``` text
salary
```

while a manager's view may expose it.

### Remember

  Level      Main concern
  ---------- ---------------------------------------------
  Physical   How data is stored
  Logical    What data is stored and how data is related
  View       What a particular user/application sees

------------------------------------------------------------------------

# 4. View of Data

A database architecture separates the different abstraction levels.

The major purpose is to hide unnecessary details and provide controlled
interfaces between levels.

------------------------------------------------------------------------

# 5. Instances and Schemas

These concepts are similar to **types and variables in programming
languages**.

## 5.1 Schema

A **schema** is the logical structure/design of a database.

Example:

``` text
customer(customer_id, customer_name, city)
account(account_number, balance)
depositor(customer_id, account_number)
```

A schema describes the structure, not the current rows.

Types of schema mentioned:

-   **Physical schema:** database design at the physical level.
-   **Logical schema:** database design at the logical level.

------------------------------------------------------------------------

## 5.2 Instance

A database **instance** is the actual content of the database at a
particular point in time.

Programming analogy:

``` text
Schema ≈ type
Instance ≈ current value
```

Example:

Schema:

``` text
student(student_id, name)
```

Current instance:

``` text
101, Rahul
102, Priya
```

The schema usually changes less frequently, while the instance changes
whenever data is inserted, deleted, or updated.

------------------------------------------------------------------------

## 5.3 Physical data independence

**Physical data independence** is the ability to modify the physical
schema without changing the logical schema.

For example:

-   Change storage organization.
-   Add/change indexes.
-   Change physical storage techniques.

Applications should continue to work because they depend primarily on
the logical schema.

### General principle

Interfaces between levels/components should be well defined so that
changes in one part do not seriously affect other parts.

------------------------------------------------------------------------

# 6. Data Models

A **data model** is a collection of tools for describing:

-   Data.
-   Data relationships.
-   Data semantics.
-   Data constraints.

The PPT lists several data models.

## 6.1 Relational model

Represents data using relations/tables.

## 6.2 Entity-Relationship (E-R) data model

Primarily used for **database design**.

It models:

-   Entities.
-   Relationships among entities.
-   Attributes.

## 6.3 Object-based data models

Includes:

-   Object-oriented data models.
-   Object-relational data models.

## 6.4 Semistructured data model

Example:

-   XML.

## 6.5 Older models

-   Network model.
-   Hierarchical model.

------------------------------------------------------------------------

# 7. Data Manipulation Language (DML)

A **DML** is a language for accessing and manipulating data organized
according to a data model.

DML is also called a **query language**.

There are two major classes.

## 7.1 Procedural DML

The user specifies:

1.  What data is required.
2.  How to obtain it.

So the user gives the retrieval procedure/steps.

## 7.2 Declarative (nonprocedural) DML

The user specifies:

-   What data is required.

The user does **not** specify exactly how the DBMS should obtain it.

### SQL

**SQL is the most widely used query language.**

------------------------------------------------------------------------

# 8. Data Definition Language (DDL)

A **DDL** is a specification notation used for defining the database
schema.

Example:

``` sql
CREATE TABLE account (
    account_number CHAR(10),
    balance INTEGER
);
```

The DDL compiler generates information that is stored in a **data
dictionary**.

------------------------------------------------------------------------

## 8.1 Data dictionary

A data dictionary contains **metadata**, meaning:

> Data about data.

It contains information such as:

-   Database schema.
-   Integrity constraints.
-   Authorization information.

### Integrity information can include

#### Domain constraints

Rules specifying permitted values for an attribute.

#### Referential integrity

Rules concerning references between relations/tables.

#### Assertions

Additional database-wide constraints.

### Authorization

Specifies who is allowed to access which data.

------------------------------------------------------------------------

# 9. Data Storage and Definition Language

This specifies:

-   Storage structure.
-   Access methods used by the database system.

It deals with lower-level storage decisions.

------------------------------------------------------------------------

# 10. Relational Databases

A **relational database** is based on the relational data model.

Its main characteristics:

-   Data is represented using a collection of tables.
-   Relationships among data are also represented through tables.
-   It includes DML and DDL facilities.
-   Most commercial relational database systems use SQL.

------------------------------------------------------------------------

# 11. Relational Model

The relational model represents information in tabular form.

Basic terminology:

-   **Relation** → table.
-   **Tuple** → row.
-   **Attribute** → column.

The PPT illustrates tabular relational data.

------------------------------------------------------------------------

# 12. SQL

SQL is a widely used **nonprocedural/declarative** language.

Example:

Find the name of customer whose ID is `192-83-7465`:

``` sql
SELECT customer.customer_name
FROM customer
WHERE customer.customer_id = '192-83-7465';
```

Example:

Find balances of all accounts held by that customer:

``` sql
SELECT account.balance
FROM depositor, account
WHERE depositor.customer_id = '192-83-7465'
  AND depositor.account_number = account.account_number;
```

Application programs can access databases through:

1.  Language extensions that support embedded SQL.
2.  Application Programming Interfaces such as ODBC/JDBC.

------------------------------------------------------------------------

# 13. Database Design

Database design means designing the general structure of the database.

There are two major design levels.

## 13.1 Logical design

Decide the database schema.

A good collection of relation schemas must be found.

This includes two kinds of decisions:

### Business decision

What attributes should be recorded?

### Computer Science decision

-   What relation schemas should exist?
-   How should attributes be distributed among those relation schemas?

------------------------------------------------------------------------

## 13.2 Physical design

Decide the physical layout of the database.

Examples include storage organization and access structures.

------------------------------------------------------------------------

# 14. Entity-Relationship Model

The **E-R model** models an enterprise as:

``` text
Entities + Relationships
```

## Entity

An entity is a "thing" or "object" in the enterprise that is
distinguishable from other objects.

Examples:

-   A particular person.
-   A company.
-   An event.
-   A plant.

Entities are described by **attributes**.

Example:

``` text
Person
    name
    address
```

## Relationship

A relationship is an **association among several entities**.

Example:

``` text
Customer ── Depositor ── Account
```

The E-R model is commonly represented using an **E-R diagram**.

------------------------------------------------------------------------

# 15. Object-Relational Data Models

Object-relational models extend relational models with:

-   Object-oriented features.
-   Constructs for additional data types.

They allow tuple attributes to have complex types, including non-atomic
values such as nested relations.

They preserve relational foundations, especially declarative access to
data.

They also provide upward compatibility with existing relational
languages.

------------------------------------------------------------------------

# 16. XML

**XML = Extensible Markup Language.**

Important points:

-   Defined by the World Wide Web Consortium (W3C).
-   Originally intended as a document markup language.
-   Its ability to specify new tags and nested structures made it useful
    for data exchange.
-   It became an important basis for data interchange formats.
-   Many tools exist for parsing, browsing, and querying XML data.

------------------------------------------------------------------------

# 17. Storage Management

The **storage manager** is a program module that provides an interface
between:

``` text
Low-level stored database data
        ↕
Applications and queries
```

Responsibilities include:

-   Interaction with the file manager.
-   Efficient storage of data.
-   Efficient retrieval of data.
-   Efficient updating of data.

Important issues:

-   Storage access.
-   File organization.
-   Indexing.
-   Hashing.

------------------------------------------------------------------------

# 18. Query Processing

The query-processing system performs three major steps:

``` text
1. Parsing and translation
          ↓
2. Optimization
          ↓
3. Evaluation
```

## 18.1 Parsing and translation

The query is parsed and translated into an internal representation.

## 18.2 Optimization

The system chooses an efficient way to execute the query.

## 18.3 Evaluation

The chosen execution strategy is executed.

------------------------------------------------------------------------

## Query optimization

The same query can often be evaluated in different ways.

There can be:

-   Equivalent expressions.
-   Different algorithms for individual operations.

The cost difference between a good and bad execution strategy can be
enormous.

Therefore, the DBMS needs to estimate operation costs.

Cost estimation depends critically on statistical information about
relations.

The database maintains statistics and may need to estimate statistics
for intermediate results when evaluating complex expressions.

------------------------------------------------------------------------

# 19. Transaction Management

A **transaction** is a collection of operations that performs a single
logical function in a database application.

Example:

``` text
Transfer money:
    debit account A
    credit account B
```

The transaction-management component ensures that the database remains
in a consistent/correct state despite:

-   System failures.
-   Power failures.
-   Operating-system crashes.
-   Transaction failures.

------------------------------------------------------------------------

## Concurrency-control manager

The concurrency-control manager controls interactions among concurrent
transactions.

Its goal is to maintain database consistency while allowing concurrent
execution.

------------------------------------------------------------------------

# 20. Database Architecture

Database-system architecture is influenced by the underlying computer
system.

The PPT lists:

1.  **Centralized**
2.  **Client-server**
3.  **Parallel (multi-processor)**
4.  **Distributed**

------------------------------------------------------------------------

# 21. Database Users

Users differ according to how they interact with the system.

## 21.1 Application programmers

Interact with the database through DML calls.

## 21.2 Sophisticated users

Form requests directly in a database query language.

## 21.3 Specialized users

Write specialized database applications that do not fit the traditional
data-processing framework.

## 21.4 Naïve users

Invoke permanent application programs that have already been written.

Examples:

-   People accessing databases over the web.
-   Bank tellers.
-   Clerical staff.

------------------------------------------------------------------------

# 22. Database Administrator (DBA)

The **database administrator** coordinates database-system activities.

The DBA needs a good understanding of:

-   The enterprise's information resources.
-   The enterprise's information needs.

## DBA duties

1.  Schema definition.
2.  Storage-structure and access-method definition.
3.  Schema and physical-organization modification.
4.  Granting users authority to access the database.
5.  Specifying integrity constraints.
6.  Acting as a liaison with users.
7.  Monitoring performance.
8.  Responding to changing requirements.

------------------------------------------------------------------------

# 23. Overall System Structure

The chapter includes the overall structure of a database system, showing
the interaction of major DBMS components such as query processing,
storage management, transaction management, and the database itself.

For revision, remember the major functional areas:

``` text
Users / Applications
        ↓
Query / Transaction facilities
        ↓
Storage management
        ↓
Stored database
```

------------------------------------------------------------------------

# 24. History of Database Systems

## 1950s and early 1960s

-   Data processing used magnetic tapes.
-   Tapes provided sequential access.
-   Punched cards were used for input.

## Late 1960s and 1970s

-   Hard disks enabled direct access to data.
-   Network and hierarchical data models became widespread.
-   Ted Codd defined the relational data model.
-   Ted Codd later received the ACM Turing Award for this work.
-   IBM Research began the System R prototype.
-   UC Berkeley began the Ingres prototype.
-   High-performance transaction processing developed.

## 1980s

-   Research relational prototypes evolved into commercial systems.
-   SQL became an industrial standard.
-   Parallel database systems developed.
-   Distributed database systems developed.
-   Object-oriented database systems developed.

## 1990s

-   Large decision-support applications.
-   Data-mining applications.
-   Large multi-terabyte data warehouses.
-   Emergence of Web commerce.

## 2000s

-   XML and XQuery standards.
-   Automated database administration.

------------------------------------------------------------------------

# Part II --- Chapter 6: Entity-Relationship Model

# 25. Chapter Overview

The E-R chapter covers:

-   Design process.
-   Modeling.
-   Constraints.
-   E-R diagrams.
-   Design issues.
-   Weak entity sets.
-   Extended E-R features.
-   Design of a banking database.
-   Reduction to relation schemas.
-   Database design.
-   UML.

------------------------------------------------------------------------

# 26. Modeling

A database can be modeled as:

``` text
Collection of entities
+
Relationships among entities
```

## Entity

An entity is an object that exists and is distinguishable from other
objects.

Examples:

-   Specific person.
-   Company.
-   Event.
-   Plant.

## Entity attributes

Entities have attributes.

Example:

``` text
Person
    name
    address
```

## Entity set

An **entity set** is a set of entities of the same type that share the
same properties.

Examples:

-   Set of all persons.
-   Set of all companies.
-   Set of all trees.
-   Set of all holidays.

------------------------------------------------------------------------

# 27. Relationship Sets

A **relationship** is an association among several entities.

Example:

``` text
Hayes ── depositor ── A-102
```

where:

-   Hayes is a customer entity.
-   A-102 is an account entity.
-   `depositor` is the relationship.

A **relationship set** is a mathematical relation among `n ≥ 2`
entities, each taken from an entity set.

Formally:

``` text
{(e1, e2, ..., en) |
 e1 ∈ E1,
 e2 ∈ E2,
 ...
 en ∈ En}
```

A tuple such as:

``` text
(Hayes, A-102)
```

can belong to the `depositor` relationship set.

------------------------------------------------------------------------

# 28. Attributes of Relationship Sets

An attribute can be a property of a **relationship set**, not just an
entity set.

Example:

``` text
Customer ── Depositor ── Account
                 |
             access-date
```

`access-date` describes the relationship between a customer and an
account.

It does not necessarily describe only the customer or only the account.

------------------------------------------------------------------------

# 29. Degree of a Relationship Set

The **degree** of a relationship set is the number of entity sets
participating in it.

## Binary relationship

Involves two entity sets.

``` text
Customer ── Depositor ── Account
```

Degree = 2.

Binary relationships are the most common.

## Ternary relationship

Involves three entity sets.

Example:

``` text
Employee
   \
    WORKS_ON
   /       \
Job       Branch
```

The bank example has:

``` text
Employee + Job + Branch
```

because an employee can have different jobs at different branches.

Degree = 3.

Relationships involving more than two entity sets are relatively rare.

------------------------------------------------------------------------

# 30. Attributes

An entity is represented by a set of attributes.

Attributes are descriptive properties possessed by all members of an
entity set.

## Domain

The **domain** of an attribute is the set of permitted values for that
attribute.

Example:

``` text
age → {0, 1, 2, ...}
```

subject to the chosen domain definition.

------------------------------------------------------------------------

# 31. Attribute Types

The chapter identifies:

1.  Simple attributes.
2.  Composite attributes.
3.  Single-valued attributes.
4.  Multivalued attributes.
5.  Derived attributes.

------------------------------------------------------------------------

## 31.1 Simple attribute

Cannot be meaningfully divided into smaller components in the model.

Example:

``` text
age
```

------------------------------------------------------------------------

## 31.2 Composite attribute

Can be divided into component attributes.

Example:

``` text
Name
├── first_name
└── last_name
```

Address may similarly have components such as:

``` text
street
city
state
zip
```

------------------------------------------------------------------------

## 31.3 Single-valued attribute

Has one value for a particular entity.

Example:

``` text
student_id = 101
```

------------------------------------------------------------------------

## 31.4 Multivalued attribute

Can have multiple values for one entity.

Example:

``` text
phone_numbers = {
    9876543210,
    9123456789
}
```

The PPT specifically gives `phone_numbers` as an example.

In an E-R diagram, a multivalued attribute is represented using a
**double ellipse**.

------------------------------------------------------------------------

## 31.5 Derived attribute

Can be computed from another attribute.

Example:

``` text
date_of_birth → age
```

`age` is derived from `date_of_birth`.

In an E-R diagram, a derived attribute is represented using a **dashed
ellipse**.

------------------------------------------------------------------------

# 32. Example Entity Schemas

Example:

``` text
customer =
(
    customer_id,
    customer_name,
    customer_street,
    customer_city
)

loan =
(
    loan_number,
    amount
)
```

------------------------------------------------------------------------

# 33. Mapping Cardinality Constraints

A mapping cardinality constraint specifies the number of entities to
which another entity can be associated through a relationship set.

It is particularly useful for binary relationships.

The four possible types are:

1.  One-to-one.
2.  One-to-many.
3.  Many-to-one.
4.  Many-to-many.

------------------------------------------------------------------------

# 34. One-to-One Relationship

``` text
A ── R ── B
```

Each entity in A is associated with **at most one** entity in B.

Each entity in B is associated with **at most one** entity in A.

Example:

``` text
Person ── has ── Passport
```

under a one-to-one assumption.

Important: Some entities on either side may not participate in any
relationship unless participation is separately constrained.

------------------------------------------------------------------------

# 35. One-to-Many Relationship

Example:

``` text
Customer ── Borrower ── Loan
```

Suppose one customer can have several loans, while each loan is
associated with at most one customer.

Then:

``` text
One Customer → many Loans
One Loan     → at most one Customer
```

The PPT notes that the customer may be associated with several loans,
including zero.

------------------------------------------------------------------------

# 36. Many-to-One Relationship

This is the reverse direction of one-to-many.

Example:

``` text
Loan ── Borrower ── Customer
```

If many loans can belong to one customer:

``` text
Many Loans → one Customer
```

A customer is associated with at most one loan under the particular
orientation shown in the PPT's example.

------------------------------------------------------------------------

# 37. Many-to-Many Relationship

Both sides may be associated with multiple entities.

Example:

``` text
Customer ↔ Borrower ↔ Loan
```

A customer can be associated with several loans, possibly zero.

A loan can be associated with several customers, possibly zero.

------------------------------------------------------------------------

# 38. Participation of an Entity Set in a Relationship

Participation tells us whether entities **must** participate in a
relationship.

## 38.1 Total participation

Represented by a **double line** in an E-R diagram.

Meaning:

> Every entity in the entity set participates in at least one
> relationship in that relationship set.

Example:

``` text
Loan == Borrower == Customer
```

If loan has total participation in `borrower`:

> Every loan must have a customer associated with it through `borrower`.

------------------------------------------------------------------------

## 38.2 Partial participation

Represented by a **single line**.

Meaning:

> Some entities may not participate in any relationship.

Example:

> A customer may have no loan.

Therefore customer participation in `borrower` can be partial.

------------------------------------------------------------------------

# 39. Cardinality Limits

Cardinality constraints can also be represented using cardinality
limits.

The chapter presents both:

-   Directed/undirected line notation.
-   Alternative cardinality-limit notation.

In the arrow notation:

-   Directed line `→` means **one**.
-   Undirected line `—` means **many**.

------------------------------------------------------------------------

# 40. E-R Diagram Symbols

Basic E-R notation:

  Symbol                 Meaning
  ---------------------- --------------------------------------------
  Rectangle              Entity set
  Diamond                Relationship set
  Line                   Connects attributes/entities/relationships
  Ellipse                Attribute
  Double ellipse         Multivalued attribute
  Dashed ellipse         Derived attribute
  Underlined attribute   Primary key

------------------------------------------------------------------------

# 41. Roles

Entity sets in a relationship do not need to be distinct.

An entity set can participate multiple times in the same relationship.

Example:

``` text
EMPLOYEE ── WORKS_FOR ── EMPLOYEE
```

One employee can be the manager and another can be the worker.

The labels:

``` text
manager
worker
```

are called **roles**.

Roles specify how entities participate in the relationship.

In E-R diagrams:

-   Roles are indicated by labels on the lines connecting the
    relationship diamond to the entity rectangle.
-   Role labels are optional.
-   They are useful when they clarify the semantics.

------------------------------------------------------------------------

# 42. Cardinality Constraints Using Lines

The chapter uses:

``` text
→  one
—  many
```

between a relationship and an entity set.

### One-to-one

Both sides have a "one" constraint.

### One-to-many

One side has one; the other has many.

### Many-to-one

Reverse of one-to-many.

### Many-to-many

Both sides are many.

------------------------------------------------------------------------

# 43. Ternary Relationships

A ternary relationship involves three entity sets.

Example:

``` text
Employee
   \
    WORKS_ON
   /       \
 Job       Branch
```

The meaning is not merely a collection of independent binary
relationships.

It represents one combined fact:

> An employee works on a particular job at a particular branch.

------------------------------------------------------------------------

# 44. Cardinality Constraints on Ternary Relationships

For ternary or higher-degree relationships, the chapter allows **at most
one arrow** to indicate a cardinality constraint.

Example:

> An arrow from `works_on` to `job` indicates that each employee works
> on at most one job at any branch.

The chapter explains why more than one arrow is avoided.

If a ternary relationship `R` among `A`, `B`, and `C` has arrows to B
and C, different formalisms can interpret it differently.

Possible interpretations include:

1.  Each A entity is associated with a unique entity from B and C.
2.  Each pair `(A, B)` is associated with a unique C, and each pair
    `(A, C)` is associated with a unique B.

Because different interpretations exist, the chapter avoids ambiguity by
outlawing more than one arrow in this notation.

------------------------------------------------------------------------

# 45. E-R Design Issues

Important design decisions include:

1.  **Entity sets vs attributes**

    -   Depends on the structure of the enterprise and the semantics of
        the concept.

2.  **Entity sets vs relationship sets**

    -   A possible guideline is to use a relationship set to describe an
        action occurring between entities.

3.  **Binary vs n-ary relationships**

    -   Although nonbinary relationships can sometimes be replaced by
        multiple binary relationships, an n-ary relationship can more
        clearly express that several entities participate in one
        relationship.

4.  **Placement of relationship attributes**

5.  **Strong vs weak entity sets**

6.  **Specialization/generalization**

    -   Helps modularity in the design.

7.  **Aggregation**

    -   Allows an aggregate to be treated as a single unit without
        worrying about its internal structure.

------------------------------------------------------------------------

# 46. Binary vs Non-Binary Relationships

Some relationships that look non-binary are better represented with
binary relationships.

## Example: Parents

A ternary `parents` relationship involving:

``` text
Child
Father
Mother
```

can be replaced by two binary relationships:

``` text
Child ── Father ── Person
Child ── Mother ── Person
```

Why?

It allows partial information.

For example:

> We know the mother but do not know the father.

Two binary relationships can represent this naturally.

------------------------------------------------------------------------

## But some relationships are naturally non-binary

Example:

``` text
WORKS_ON(Employee, Job, Branch)
```

is naturally ternary because the meaning depends on the complete
combination.

------------------------------------------------------------------------

# 47. Converting a Non-Binary Relationship to Binary Relationships

In general, any non-binary relationship can be represented using binary
relationships by creating an **artificial entity set**.

Suppose relationship:

``` text
R(A, B, C)
```

Create artificial entity set:

``` text
E
```

and three binary relationships:

``` text
RA(E, A)
RB(E, B)
RC(E, C)
```

## Procedure

1.  Create special identifying attribute for E.
2.  Add any attributes of R to E.
3.  For every relationship tuple `(ai, bi, ci)` in R:
    -   Create a new entity `ei` in E.
    -   Add `(ei, ai)` to RA.
    -   Add `(ei, bi)` to RB.
    -   Add `(ei, ci)` to RC.

------------------------------------------------------------------------

## Important issue: constraints

Simply converting the relationship does not automatically preserve all
original constraints.

There may be instances in the translated schema that do not correspond
to any valid instance of the original relationship.

The relationships `RA`, `RB`, and `RC` need appropriate constraints so
that each newly created entity corresponds to exactly one entity in each
of A, B, and C.

An identifying attribute can sometimes be avoided by making E a **weak
entity set**, identified by the three relationship sets.

------------------------------------------------------------------------

# 48. Mapping Cardinalities Can Affect ER Design

Sometimes an attribute can be placed differently depending on
relationship cardinality.

Example:

Suppose `access-date` is associated with a customer-account
relationship.

If each account can have only one customer, then the relationship is
many-to-one from account to customer.

In that case, `access-date` could potentially be stored as an attribute
of `account` instead of as a relationship attribute.

------------------------------------------------------------------------

# 49. Weak Entity Sets

This is a major topic.

## 49.1 What is a weak entity set?

An entity set that **does not have a primary key of its own** is called
a **weak entity set**.

Its existence depends on another entity set called the **identifying
entity set** (strong entity set).

Think:

``` text
Strong Entity
     ↓ identifies
Weak Entity
```

------------------------------------------------------------------------

# 50. Existence Dependency

A weak entity cannot exist meaningfully without its associated strong
entity.

The weak entity must relate to the identifying entity through a **total,
one-to-many identifying relationship** from the identifying entity to
the weak entity.

The identifying relationship is represented by a **double diamond**.

------------------------------------------------------------------------

# 51. Discriminator / Partial Key

A weak entity has a **discriminator**, also called a **partial key**.

It is the set of attributes that distinguishes among the weak entities
belonging to the same strong entity.

Important:

> The discriminator may not uniquely identify the weak entity globally.

It identifies it only relative to its owner/strong entity.

------------------------------------------------------------------------

# 52. Primary Key of a Weak Entity

The primary key is formed as:

``` text
Primary key of strong entity
+
Discriminator of weak entity
```

Example:

``` text
Loan
loan_number = primary key

Payment
payment_number = discriminator
```

Then:

``` text
Payment PK = (loan_number, payment_number)
```

------------------------------------------------------------------------

# 53. Weak Entity Diagram Notation

Weak entity set:

``` text
Double rectangle
```

Identifying relationship:

``` text
Double diamond
```

Discriminator:

``` text
Dashed underline
```

Example:

``` text
LOAN
  ║
  ◇◇  identifying relationship
  ║
PAYMENT
```

`payment_number` is the discriminator.

Primary key:

``` text
(loan_number, payment_number)
```

------------------------------------------------------------------------

# 54. Why Isn't the Strong Entity's Primary Key Explicitly Stored in the Weak Entity in the E-R Diagram?

The chapter notes that the primary key of the strong entity is not
explicitly stored with the weak entity because it is **implicit in the
identifying relationship**.

For example:

``` text
Loan ── identifies ── Payment
```

The payment's identity already depends on its loan.

If `loan_number` were explicitly stored as an ordinary attribute,
payment could instead be modeled as a strong entity.

Then the relationship between payment and loan would effectively be
duplicated:

1.  Explicitly through `loan_number`.
2.  Implicitly through the identifying relationship.

------------------------------------------------------------------------

# 55. Weak Entity Example: Course Offering

In a university:

``` text
COURSE
    ↓
COURSE_OFFERING
```

A course can be strong.

A particular course offering can be modeled as weak.

Example:

``` text
Course:
course_number = CS101

Course offering:
semester = Fall 2026
section_number = 1
```

The discriminator can be:

``` text
(semester, section_number)
```

If `course_offering` were made strong, `course_number` would need to be
included to identify which course it belongs to.

But then the relationship with `course` becomes implicit in the shared
`course_number`.

------------------------------------------------------------------------

# 56. Specialization

**Specialization** is an Extended E-R feature.

It is a **top-down design process**.

Start with a general entity set and identify distinctive subgroups.

Example:

``` text
              PERSON
                |
               ISA
              /   \
         CUSTOMER EMPLOYEE
```

The lower-level entity sets are specialized forms of the higher-level
entity set.

------------------------------------------------------------------------

# 57. Why Specialization?

Suppose:

``` text
PERSON
    name
    address
```

Some persons are customers and have:

``` text
credit_rating
```

Some persons are employees and have:

``` text
salary
```

Putting all attributes into PERSON would create unnecessary attributes
for people who do not belong to those subgroups.

Specialization allows us to represent:

``` text
PERSON
   |
   ISA
 /     \
CUSTOMER EMPLOYEE
```

where each lower-level set can have its own attributes and
relationships.

------------------------------------------------------------------------

# 58. ISA

The specialization connection is represented by a triangle labeled:

``` text
ISA
```

ISA means:

> "is a"

Example:

``` text
CUSTOMER ISA PERSON
```

means:

> A customer is a person.

The ISA relationship is also called a:

> **Superclass-subclass relationship**

------------------------------------------------------------------------

# 59. Attribute Inheritance

A lower-level entity set inherits:

1.  All attributes of the higher-level entity set.
2.  All relationship participation of the higher-level entity set.

Example:

``` text
PERSON
----------------
name
street
city
```

and:

``` text
CUSTOMER
----------------
credit_rating
```

Conceptually CUSTOMER has:

``` text
name
street
city
credit_rating
```

The first three are inherited.

------------------------------------------------------------------------

# 60. Relationship Inheritance

If:

``` text
PERSON ── LIVES_IN ── CITY
```

and:

``` text
CUSTOMER ISA PERSON
```

then customers also inherit participation in the `LIVES_IN`
relationship.

The lower-level entity receives the relationship participation of its
superclass.

------------------------------------------------------------------------

# 61. Generalization

**Generalization** is the reverse/inverse direction of specialization.

It is a **bottom-up design process**.

Start with multiple entity sets that share features and combine them
into a higher-level entity set.

Example:

``` text
CUSTOMER     EMPLOYEE
     \         /
       PERSON
```

Specialization and generalization are inversions of each other.

They are represented in the same way in an E-R diagram.

The terms may be used interchangeably depending on the context.

------------------------------------------------------------------------

# 62. Multiple Specializations

An entity set can have multiple specializations based on different
characteristics.

Example:

``` text
EMPLOYEE
   |
   +---- permanent_employee
   |
   +---- temporary_employee
```

and independently:

``` text
EMPLOYEE
   |
   +---- officer
   +---- secretary
   +---- teller
```

A particular employee can therefore belong to:

-   One of `permanent_employee` or `temporary_employee`.
-   At the same time, one of `officer`, `secretary`, or `teller`.

These are separate specialization dimensions.

------------------------------------------------------------------------

# 63. Specialization Design Constraints

There are several important constraints.

They answer different questions.

------------------------------------------------------------------------

## 63.1 Membership constraint

Question:

> How is it determined whether an entity belongs to a lower-level entity
> set?

Two possibilities:

### Condition-defined

Membership is determined using a condition.

Example:

``` text
All customers with age > 65
        ↓
SENIOR_CITIZEN
```

So:

``` text
senior_citizen ISA person
```

and the membership condition is based on age.

### User-defined

Membership is determined explicitly by the user/application rather than
automatically by a condition.

------------------------------------------------------------------------

# 64. Disjoint Constraint

Question:

> Can an entity belong to more than one lower-level entity set within
> one specialization?

### Disjoint

An entity can belong to **only one** lower-level entity set.

Example:

``` text
              PERSON
                |
             disjoint
                ISA
              /     \
         STUDENT   EMPLOYEE
```

A person cannot be both under this specialization.

Notation:

> Write `disjoint` next to the ISA triangle.

------------------------------------------------------------------------

# 65. Overlapping Constraint

An entity can belong to **more than one** lower-level entity set.

Example:

``` text
PERSON
  |
 ISA
 /   \
STUDENT EMPLOYEE
```

A person may simultaneously be:

``` text
STUDENT + EMPLOYEE
```

So:

``` text
Disjoint → at most one subclass
Overlapping → multiple subclasses allowed
```

------------------------------------------------------------------------

# 66. Completeness Constraint

This asks:

> Must every entity in the higher-level entity set belong to at least
> one lower-level entity set?

Two possibilities:

## Total

Every entity in the higher-level set must belong to at least one
lower-level set.

Example:

``` text
PERSON
  |
 ISA
 /   \
CUSTOMER EMPLOYEE
```

Under total specialization:

``` text
Every PERSON
    ↓
CUSTOMER or EMPLOYEE
```

No person can exist only in PERSON without belonging to at least one
subclass.

------------------------------------------------------------------------

## Partial

An entity in the higher-level set **does not have to** belong to a
lower-level set.

Example:

``` text
Person A → Customer
Person B → Employee
Person C → neither
```

is allowed under partial specialization.

------------------------------------------------------------------------

# 67. Disjoint vs Total --- Do Not Confuse Them

These are independent constraints.

### Disjoint asks:

> Can one entity belong to multiple subclasses?

``` text
No → Disjoint
Yes → Overlapping
```

### Completeness asks:

> Must every superclass entity belong to at least one subclass?

``` text
Yes → Total
No → Partial
```

Therefore possible combinations include:

-   Disjoint + Total.
-   Disjoint + Partial.
-   Overlapping + Total.
-   Overlapping + Partial.

------------------------------------------------------------------------

# 68. Aggregation

Aggregation is another Extended E-R feature.

It is useful when a relationship itself needs to participate in another
relationship.

The key idea:

> **Treat a relationship as an abstract entity.**

This allows:

> Relationships between relationships.

------------------------------------------------------------------------

# 69. Aggregation Example

Consider the ternary relationship:

``` text
WORKS_ON(Employee, Job, Branch)
```

Meaning:

> An employee works on a particular job at a particular branch.

Suppose we also want to record a manager for a particular work
assignment.

We want:

``` text
Manager
   |
 MANAGES
   |
[Employee works on Job at Branch]
```

The manager is not simply managing the employee, job, or branch
individually.

The manager is associated with the **whole work assignment**.

------------------------------------------------------------------------

# 70. Why Simple Relationships Create Redundancy

Suppose we have:

``` text
WORKS_ON(Employee, Job, Branch)
```

and:

``` text
MANAGES(Employee, Job, Branch, Manager)
```

Every `MANAGES` relationship corresponds to a `WORKS_ON` relationship.

But the reverse is not necessarily true.

Example:

``` text
Rahul works on Database at Pune
```

may have no manager.

Therefore:

``` text
WORKS_ON
```

contains information that cannot be discarded simply because `MANAGES`
exists.

------------------------------------------------------------------------

# 71. Aggregation Solves the Problem

Aggregation treats the `WORKS_ON` relationship as an abstract
higher-level object.

Conceptually:

``` text
Employee ── WORKS_ON ── Job
               |
             Branch
               |
        [one work assignment]
               ↑
               |
            MANAGES
               |
             Manager
```

The entire work assignment is what the `MANAGES` relationship refers to.

------------------------------------------------------------------------

# 72. How to Think About Aggregation

Imagine placing a box around the relationship:

``` text
┌──────────────────────────────┐
│ Employee ─ WORKS_ON ─ Job   │
│             |                │
│           Branch             │
└──────────────────────────────┘
              ↑
              |
           MANAGES
              |
           Manager
```

The box represents the abstraction.

The important point:

> `MANAGES` connects to the **aggregated relationship as a whole**, not
> separately to Employee, Job, and Branch.

------------------------------------------------------------------------

# 73. Aggregation and Redundancy

Aggregation allows us to express:

1.  An employee works on a particular job at a particular branch.
2.  That employee-job-branch combination may have an associated manager.

Without aggregation, the same combination may need to be repeated in
another relationship.

Aggregation captures the existing relationship as one abstract unit.

------------------------------------------------------------------------

# 74. E-R Design Decision for Aggregation

Aggregation is useful because:

> The aggregate entity set can be treated as a single unit without
> concern for the details of its internal structure.

This provides abstraction.

------------------------------------------------------------------------

# 75. Reduction of E-R Model to Relational Schemas

After designing an E-R model, we often need to convert it into
relational tables.

The chapter explains rules for this conversion.

Important principle:

> Primary keys allow entity sets and relationship sets to be represented
> uniformly as relation schemas.

A database corresponding to an E-R diagram can be represented by a
collection of schemas.

For each entity set and relationship set, a schema can be assigned the
corresponding name.

Each schema contains columns corresponding generally to attributes.

------------------------------------------------------------------------

# 76. Strong Entity Set → Relation

A strong entity set becomes a relation/schema with the same attributes.

Example:

``` text
EMPLOYEE
(employee_id, name, salary)
```

The primary key of the entity becomes the primary key of the relation.

------------------------------------------------------------------------

# 77. Weak Entity Set → Relation

A weak entity set becomes a table that includes the primary key of its
identifying strong entity set.

Example:

``` text
payment
(
    loan_number,
    payment_number,
    payment_date,
    payment_amount
)
```

Here:

``` text
loan_number + payment_number
```

identifies a payment.

------------------------------------------------------------------------

# 78. Relationship Sets → Relations

A many-to-many relationship set is represented as a schema containing:

1.  Primary key of first participating entity set.
2.  Primary key of second participating entity set.
3.  Any descriptive attributes of the relationship.

Example:

``` text
borrower
(
    customer_id,
    loan_number
)
```

For a many-to-many relationship:

``` text
CUSTOMER ── BORROWER ── LOAN
```

the relation stores which customer borrows which loan.

------------------------------------------------------------------------

# 79. Key of a Relationship Set

The combination of primary keys of participating entity sets forms a
**super key** of a relationship set.

Example:

``` text
depositor(customer_id, account_number)
```

Then:

``` text
(customer_id, account_number)
```

is a super key.

This means a pair of entity instances can have at most one relationship
in that particular relationship set.

------------------------------------------------------------------------

# 80. Candidate Keys of Relationship Sets

When determining candidate keys, consider:

-   Mapping cardinality.
-   Semantics of the relationship.

The combination of all participating primary keys is a super key, but a
smaller candidate key may exist depending on the relationship's
cardinality.

If there are multiple candidate keys, the semantics of the relationship
should guide the choice of primary key.

------------------------------------------------------------------------

# 81. Redundancy in Relationship Schemas

Some relationship schemas can be eliminated when the same information
can be represented in an entity relation.

------------------------------------------------------------------------

## 81.1 Many-to-one / one-to-many

A many-to-one or one-to-many relationship that is **total on the many
side** can be represented by adding an extra attribute to the many-side
relation.

That attribute contains the primary key of the one-side entity.

Example:

Instead of:

``` text
account_branch(account_number, branch_name)
```

we can put:

``` text
branch_name
```

directly into:

``` text
account(...)
```

if every account must belong to a branch.

------------------------------------------------------------------------

# 82. One-to-One Relationship Redundancy

For a one-to-one relationship:

> Either side can be chosen to act as the "many" side.

Therefore, the primary key of one entity can be added as an extra
attribute to the other entity's relation.

Choice depends on the design.

------------------------------------------------------------------------

# 83. Partial Participation and NULLs

If participation is partial on the side where the foreign key is stored,
replacing the relationship schema with an attribute may produce **NULL
values**.

Example:

Some accounts may not have an associated entity yet.

Then the added foreign-key attribute may be NULL.

So eliminating the relationship table can trade a separate relation for
possible NULL values.

------------------------------------------------------------------------

# 84. Weak-Entity Identifying Relationship Redundancy

The relationship between a weak entity and its identifying strong entity
is redundant in the relational representation.

Example:

``` text
payment
(
    loan_number,
    payment_number,
    ...
)
```

already contains:

``` text
loan_number
payment_number
```

Therefore a separate:

``` text
loan_payment
```

relation would repeat information already present in `payment`.

------------------------------------------------------------------------

# 85. Composite Attributes → Relations

Composite attributes are **flattened** when converting to relations.

Example:

``` text
Customer
    Name
      ├── first_name
      └── last_name
```

The resulting relation can have:

``` text
name.first_name
name.last_name
```

rather than one nested `Name` attribute.

------------------------------------------------------------------------

# 86. Multivalued Attributes

A multivalued attribute must be represented using a **separate
schema/relation**.

Suppose:

``` text
EMPLOYEE
    employee_id
    dependent_names
```

where:

``` text
dependent_names = {Jack, Jane}
```

Create:

``` text
employee_dependent_names
(
    employee_id,
    dname
)
```

The new schema contains:

1.  The primary key of the original entity.
2.  An attribute representing the multivalued attribute.

------------------------------------------------------------------------

# 87. Why a Separate Table for a Multivalued Attribute?

A relational table should not store multiple independent values inside
one ordinary cell.

Instead of:

``` text
employee_id | dependent_names
123         | Jack, Jane
```

we use:

``` text
employee_id | dname
123         | Jack
123         | Jane
```

Each value of the multivalued attribute becomes a separate tuple/row.

------------------------------------------------------------------------

# 88. Example: Multivalued Attribute

Suppose:

``` text
Employee PK = 123-45-6789

dependent_names = {
    Jack,
    Jane
}
```

The separate relation becomes:

``` text
employee_dependent_names
--------------------------------
employee_id     | dname
123-45-6789     | Jack
123-45-6789     | Jane
```

Thus:

``` text
One entity
    ↓
multiple values
    ↓
multiple rows
```

The natural key for the table is generally the combination:

``` text
(employee_id, dname)
```

when the same dependent name is not repeated for the same employee.

`employee_id` also references the original employee.

------------------------------------------------------------------------

# 89. Method 1 for Representing Specialization as Schemas

Suppose:

``` text
PERSON
    name
    street
    city

CUSTOMER
    credit_rating

EMPLOYEE
    salary
```

Method 1:

### Step 1 --- Create schema for higher-level entity

``` text
PERSON
(
    person_id,
    name,
    street,
    city
)
```

### Step 2 --- Create schema for each lower-level entity

Include:

-   Primary key of higher-level entity.
-   Local attributes of the subclass.

So:

``` text
CUSTOMER
(
    person_id,
    credit_rating
)
```

and:

``` text
EMPLOYEE
(
    person_id,
    salary
)
```

Here `person_id` is both:

-   Primary key of the subclass relation.
-   Foreign key referencing PERSON.

------------------------------------------------------------------------

# 90. Method 1 --- Main Idea

The inherited/common attributes remain in the superclass relation.

``` text
PERSON
-----------------------
person_id
name
street
city

CUSTOMER
-----------------------
person_id
credit_rating

EMPLOYEE
-----------------------
person_id
salary
```

To get the complete employee:

``` text
PERSON
   JOIN
EMPLOYEE
```

------------------------------------------------------------------------

# 91. Method 1 --- Advantage

Common/inherited attributes are not duplicated.

For example:

``` text
name
street
city
```

are stored only once in PERSON.

This reduces redundancy.

------------------------------------------------------------------------

# 92. Method 1 --- Drawback

To obtain complete information about an employee, two relations must be
accessed:

``` text
PERSON
+
EMPLOYEE
```

For example:

``` text
Employee 101
```

requires finding:

``` text
PERSON(101)
+
EMPLOYEE(101)
```

and joining the information.

------------------------------------------------------------------------

# 93. Method 2 for Representing Specialization as Schemas

Method 2 says:

> Form a schema for **each entity set** containing all local and
> inherited attributes.

So:

### PERSON

``` text
PERSON
(
    person_id,
    name,
    street,
    city
)
```

### CUSTOMER

``` text
CUSTOMER
(
    person_id,
    name,
    street,
    city,
    credit_rating
)
```

### EMPLOYEE

``` text
EMPLOYEE
(
    person_id,
    name,
    street,
    city,
    salary
)
```

------------------------------------------------------------------------

# 94. Method 2 --- Advantage

To obtain complete employee information, only the employee relation
needs to be accessed:

``` text
EMPLOYEE
```

No join with PERSON is necessary.

------------------------------------------------------------------------

# 95. Method 2 --- Drawback

Inherited attributes can be duplicated.

Suppose one person is both:

``` text
CUSTOMER
+
EMPLOYEE
```

Then:

``` text
name
street
city
```

may be stored in both relations.

This creates redundancy.

------------------------------------------------------------------------

# 96. Method 1 vs Method 2

  Feature                                Method 1        Method 2
  -------------------------------------- --------------- ----------------------
  Superclass relation                    Yes             Yes
  Subclass stores inherited attributes   No              Yes
  Redundancy                             Lower           Potentially higher
  Complete subclass information          Requires join   Usually one relation
  Common attributes stored once          Yes             Not necessarily

### Memory trick

``` text
Method 1:
Common data stays UP.
Subclass stores only local data.

Method 2:
Common data is COPIED DOWN.
Subclass stores inherited + local data.
```

------------------------------------------------------------------------

# 97. Total Specialization and Method 2

If specialization is **total**, every entity in the superclass must
appear in at least one subclass.

Therefore, the superclass relation may not need to physically store the
information.

The generalized entity set can be represented as a **view** containing
the union of specialization relations.

Conceptually:

``` text
PERSON = CUSTOMER UNION EMPLOYEE
```

However, an explicit PERSON schema may still be needed for purposes such
as foreign-key constraints.

------------------------------------------------------------------------

# 98. Method 2 and Overlapping Specialization

If specialization is overlapping, a person may occur in more than one
subclass.

For example:

``` text
PERSON 101
    ↓
CUSTOMER
    +
EMPLOYEE
```

Then inherited attributes such as:

``` text
street
city
```

can appear redundantly in both tables.

This is the main drawback highlighted in the PPT.

------------------------------------------------------------------------

# 99. Schemas Corresponding to Aggregation

To represent aggregation, create a schema containing:

1.  **Primary key of the aggregated relationship.**
2.  **Primary key of the associated entity set.**
3.  **Any descriptive attributes.**

------------------------------------------------------------------------

# 100. Aggregation Schema Example

Suppose:

``` text
WORKS_ON(Employee, Branch, Job)
```

and a manager is associated with the work assignment.

The aggregated relationship's identifying information is:

``` text
(employee_id, branch_name, title)
```

The associated entity contributes:

``` text
manager_name
```

Therefore:

``` text
MANAGES
(
    employee_id,
    branch_name,
    title,
    manager_name
)
```

This relation means:

> Employee `employee_id` works on job `title` at branch `branch_name`,
> and the associated manager is `manager_name`.

------------------------------------------------------------------------

# 101. Why WORKS_ON Can Sometimes Be Redundant

If:

``` text
MANAGES
(
    employee_id,
    branch_name,
    title,
    manager_name
)
```

contains every `WORKS_ON` combination, then the first three attributes
already tell us the work assignment.

For example:

  employee_id   branch_name   title   manager_name
  ------------- ------------- ------- --------------
  101           Pune          DB      Amit
  102           Mumbai        AI      Rahul
  103           Pune          Web     NULL

From this, we can derive:

``` text
WORKS_ON
(employee_id, branch_name, title)
```

by projecting the first three columns.

Therefore, `WORKS_ON` can be redundant **if we are willing to store NULL
in `manager_name`** when an assignment has no manager.

------------------------------------------------------------------------

# 102. Important NULL Trade-off

Suppose:

``` text
Employee 103 works on Web at Pune
```

but no manager exists.

Then:

``` text
manager_name = NULL
```

The row still represents the `WORKS_ON` fact.

This eliminates a separate WORKS_ON relation, but introduces NULL
values.

So the design choice is:

``` text
Separate WORKS_ON table
        vs
Combined MANAGES table with possible NULLs
```

------------------------------------------------------------------------

# 103. Complete E-R-to-Relational Mapping Checklist

When converting an E-R model to relations, remember:

## Strong entity

``` text
Entity → relation with its attributes
```

## Weak entity

``` text
Weak entity → relation containing:
    strong entity PK
    discriminator
    other weak attributes
```

## Many-to-many relationship

``` text
Relationship → separate relation containing:
    PK of entity 1
    PK of entity 2
    relationship attributes
```

## Many-to-one / one-to-many

If total on the many side:

``` text
Add PK of one side to many-side relation
```

This can eliminate the separate relationship relation.

## One-to-one

Choose either side to hold the other's PK.

## Composite attribute

Flatten it into its component attributes.

## Multivalued attribute

Create a separate relation:

``` text
(original PK, multivalued attribute)
```

Each value becomes a separate tuple.

## Specialization --- Method 1

``` text
Superclass relation
+
one relation per subclass with:
    superclass PK + local attributes
```

## Specialization --- Method 2

``` text
One relation for each entity set
with:
    inherited + local attributes
```

## Aggregation

Create a relation containing:

``` text
PK of aggregated relationship
+
PK of associated entity
+
descriptive attributes
```

------------------------------------------------------------------------

# 104. High-Value Definitions for Exams

### DBMS

A collection of interrelated data, programs for accessing the data, and
an environment that is convenient and efficient to use.

### Schema

The logical structure/design of a database.

### Instance

The actual contents of a database at a particular point in time.

### Data model

A collection of tools for describing data, relationships, semantics, and
constraints.

### Entity

A distinguishable object in the enterprise.

### Entity set

A set of entities of the same type sharing the same properties.

### Relationship

An association among entities.

### Relationship set

A mathematical relation among entities from participating entity sets.

### Degree of relationship

The number of entity sets participating in a relationship set.

### Weak entity set

An entity set without a primary key whose existence depends on an
identifying entity set.

### Discriminator

The partial key that distinguishes weak entities belonging to the same
owner.

### Specialization

A top-down process of creating lower-level entity sets from a
higher-level entity set.

### Generalization

A bottom-up process of combining similar entity sets into a higher-level
entity set.

### Attribute inheritance

A subclass inherits all attributes and relationship participation of its
superclass.

### Aggregation

An E-R abstraction that treats a relationship set as a higher-level
entity so that it can participate in another relationship.

------------------------------------------------------------------------

# 105. Exam-Focused Comparison Tables

## Simple vs Composite vs Multivalued vs Derived

  -----------------------------------------------------------------------
  Type              Meaning           Example           Diagram
  ----------------- ----------------- ----------------- -----------------
  Simple            Cannot be         age               Single ellipse
                    meaningfully                        
                    divided                             

  Composite         Has components    name → first/last Attribute with
                                                        subattributes

  Single-valued     One value per     date_of_birth     Single ellipse
                    entity                              

  Multivalued       Multiple values   phone_numbers     Double ellipse
                    per entity                          

  Derived           Computed from     age from DOB      Dashed ellipse
                    other data                          
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Strong vs Weak Entity

  -----------------------------------------------------------------------
  Feature                 Strong                  Weak
  ----------------------- ----------------------- -----------------------
  Own primary key         Yes                     No

  Existence dependency    No                      Yes

  Identifying             Normal relationship     Identifying
  relationship                                    relationship

  Diagram                 Single rectangle        Double rectangle

  Partial                 Not applicable          Yes
  key/discriminator                               

  Final PK                Own PK                  Owner PK +
                                                  discriminator
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Total vs Partial Participation

  -----------------------------------------------------------------------
  Type                                Meaning
  ----------------------------------- -----------------------------------
  Total participation                 Every entity must participate in at
                                      least one relationship

  Partial participation               Some entities may participate in
                                      none

  Diagram                             Double line for total; single line
                                      for partial
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Disjoint vs Overlapping

  Type          Meaning
  ------------- ------------------------------------------
  Disjoint      Entity can belong to only one subclass
  Overlapping   Entity can belong to multiple subclasses

------------------------------------------------------------------------

## Total vs Partial Specialization

  -----------------------------------------------------------------------
  Type                                Meaning
  ----------------------------------- -----------------------------------
  Total specialization                Every superclass entity must belong
                                      to at least one subclass

  Partial specialization              A superclass entity may belong to
                                      no subclass
  -----------------------------------------------------------------------

------------------------------------------------------------------------

## Method 1 vs Method 2

  -----------------------------------------------------------------------
  Method            Subclass contents Main advantage    Main drawback
  ----------------- ----------------- ----------------- -----------------
  Method 1          Superclass PK +   Less redundancy   Joins needed
                    local attributes                    

  Method 2          Inherited + local Easier direct     Redundancy
                    attributes        access            
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# 106. Common Confusions to Avoid

## Confusion 1: Disjoint vs Total

They are NOT the same.

``` text
Disjoint:
Can one entity belong to two subclasses?
→ No.

Total:
Must every superclass entity belong to a subclass?
→ Yes.
```

------------------------------------------------------------------------

## Confusion 2: Total participation vs Total specialization

They refer to different things.

### Total participation

Concerns:

``` text
Entity set ↔ Relationship set
```

It asks whether every entity participates in a relationship.

### Total specialization

Concerns:

``` text
Superclass ↔ Subclasses
```

It asks whether every superclass entity belongs to at least one
subclass.

------------------------------------------------------------------------

## Confusion 3: Multivalued attribute vs composite attribute

### Multivalued

One attribute has multiple values:

``` text
Phone = {P1, P2, P3}
```

### Composite

One attribute has multiple components:

``` text
Name = FirstName + LastName
```

------------------------------------------------------------------------

## Confusion 4: Weak entity's partial key vs primary key

For:

``` text
PAYMENT
payment_number
```

`payment_number` alone is only the **discriminator/partial key**.

The final primary key is:

``` text
(loan_number, payment_number)
```

------------------------------------------------------------------------

## Confusion 5: Aggregation

Aggregation does NOT mean simply creating another ordinary entity.

It means:

> Treating an existing relationship and its participating entities as an
> abstract unit so another relationship can be associated with that
> unit.

------------------------------------------------------------------------

# 107. Quick Visual Symbol Sheet

``` text
ENTITY SET
┌──────────────┐
│   EMPLOYEE   │
└──────────────┘

WEAK ENTITY SET
╔══════════════╗
║   PAYMENT    ║
╚══════════════╝

RELATIONSHIP
      ◇
   WORKS_ON

IDENTIFYING RELATIONSHIP
     ◇◇
   IDENTIFIES

ATTRIBUTE
    (name)

MULTIVALUED ATTRIBUTE
   ((phone))

DERIVED ATTRIBUTE
   (- - age - -)

PRIMARY KEY
    __name__

ISA / SPECIALIZATION
       PERSON
          |
         ISA
        /   \
   CUSTOMER EMPLOYEE
```

------------------------------------------------------------------------

# 108. Master Mental Model

The entire Chapter 6 can be remembered as a progression:

``` text
REAL WORLD
    ↓
Entities
    ↓
Entity Sets
    ↓
Attributes
    ↓
Relationships
    ↓
Constraints
    ↓
E-R Diagram
    ↓
Advanced E-R concepts
    ├── Weak Entity
    ├── Specialization
    ├── Generalization
    └── Aggregation
    ↓
Reduction to Relations
    ↓
Relational Schemas / Tables
```

------------------------------------------------------------------------

# 109. Ultra-Short Revision Map

``` text
DBMS
├── Purpose
│   ├── Avoid redundancy/inconsistency
│   ├── Easier data access
│   ├── Avoid data isolation
│   ├── Integrity
│   ├── Atomicity
│   ├── Concurrency
│   └── Security
│
├── Abstraction
│   ├── Physical
│   ├── Logical
│   └── View
│
├── Schema vs Instance
│
├── Data Models
│   ├── Relational
│   ├── E-R
│   ├── Object-based
│   ├── Semistructured
│   ├── Network
│   └── Hierarchical
│
├── DML
│   ├── Procedural
│   └── Declarative
│
├── DDL
│   └── Schema + metadata + constraints + authorization
│
├── Query Processing
│   ├── Parse/translate
│   ├── Optimize
│   └── Evaluate
│
├── Transactions
│   └── Concurrency control
│
└── DBA
    ├── Schema
    ├── Storage
    ├── Authorization
    ├── Constraints
    └── Performance


E-R MODEL
├── Entity
├── Entity Set
├── Relationship
├── Relationship Set
├── Relationship Attributes
├── Degree
│   ├── Binary
│   └── Ternary
├── Attributes
│   ├── Simple
│   ├── Composite
│   ├── Single-valued
│   ├── Multivalued
│   └── Derived
├── Cardinality
│   ├── 1:1
│   ├── 1:N
│   ├── N:1
│   └── M:N
├── Participation
│   ├── Total
│   └── Partial
├── Keys
├── Roles
├── Weak Entity
│   ├── No own PK
│   ├── Existence dependent
│   ├── Discriminator
│   └── Owner PK + discriminator
├── Specialization
│   ├── ISA
│   ├── Inheritance
│   ├── Condition-defined/User-defined
│   ├── Disjoint/Overlapping
│   └── Total/Partial
├── Generalization
├── Aggregation
└── Reduction to Relations
    ├── Strong entity
    ├── Weak entity
    ├── Relationship
    ├── Redundancy elimination
    ├── Composite attributes
    ├── Multivalued attributes
    ├── Specialization Method 1
    ├── Specialization Method 2
    └── Aggregation schema
```

------------------------------------------------------------------------

# 110. Final Memory Rules

If you remember only the following rules before an exam, you can
reconstruct most of the chapter:

1.  **Entity = object.**
2.  **Entity set = collection of similar entities.**
3.  **Relationship = association between entities.**
4.  **Relationship set = collection of such associations.**
5.  **Degree = number of participating entity sets.**
6.  **1:1, 1:N, N:1, M:N = mapping cardinalities.**
7.  **Total participation = every entity participates.**
8.  **Partial participation = some may not participate.**
9.  **Weak entity = no independent primary key + existence depends on
    owner.**
10. **Weak entity PK = owner PK + discriminator.**
11. **Specialization = top-down.**
12. **Generalization = bottom-up.**
13. **ISA = "is a".**
14. **Subclass inherits attributes and relationship participation.**
15. **Disjoint = at most one subclass.**
16. **Overlapping = multiple subclasses allowed.**
17. **Total specialization = every superclass entity belongs to at least
    one subclass.**
18. **Partial specialization = some superclass entities may belong to
    none.**
19. **Aggregation = treat a relationship as an abstract entity so
    another relationship can relate to it.**
20. **Multivalued attribute = separate relation, one row per value.**
21. **Composite attribute = flatten into component attributes.**
22. **M:N relationship = normally separate relation containing
    participating PKs.**
23. **1:N relationship with total participation on many side = can often
    store one-side PK on many side.**
24. **Method 1 specialization = common attributes stay in superclass.**
25. **Method 2 specialization = inherited attributes are copied into
    subclass relations.**
26. **Method 1 → less redundancy, more joins.**
27. **Method 2 → fewer joins, possible redundancy.**
28. **Aggregation relation = aggregated relationship PK + associated
    entity PK + descriptive attributes.**
