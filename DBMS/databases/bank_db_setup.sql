CREATE DATABASE bank_db;

USE bank_db;

CREATE TABLE branch (
    branch_name VARCHAR(30) PRIMARY KEY,
    branch_city VARCHAR(30),
    assets DECIMAL(15,2)
);

CREATE TABLE customer (
    customer_name VARCHAR(30) PRIMARY KEY,
    customer_street VARCHAR(50),
    customer_city VARCHAR(30)
);

CREATE TABLE account (
    account_number VARCHAR(20) PRIMARY KEY,
    branch_name VARCHAR(30),
    balance DECIMAL(15,2),
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE depositor (
    customer_name VARCHAR(30),
    account_number VARCHAR(20),
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (account_number) REFERENCES account(account_number)
);

CREATE TABLE loan (
    loan_number VARCHAR(20) PRIMARY KEY,
    branch_name VARCHAR(30),
    amount DECIMAL(15,2),
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE borrower (
    customer_name VARCHAR(30),
    loan_number VARCHAR(20),
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

INSERT INTO branch (branch_name, branch_city, assets) VALUES
('Perryridge', 'Brooklyn', 500000),
('Downtown', 'Brooklyn', 900000),
('Mianus', 'Horseneck', 400000),
('North Town', 'Rye', 370000),
('Brighton', 'Brooklyn', 710000),
('Redwood', 'Palo Alto', 300000),
('Round Hill', 'Horseneck', 800000);

INSERT INTO customer (customer_name, customer_street, customer_city) VALUES
('Adams', 'Spring', 'Pittsfield'),
('Brooks', 'Senator', 'Brooklyn'),
('Curry', 'North', 'Rye'),
('Davis', 'Sand Hill', 'Palo Alto'),
('Edwards', 'Main', 'Stamford'),
('Green', 'Walnut', 'Stamford'),
('Hayes', 'Main', 'Harrison'),
('Johnson', 'Alma', 'Palo Alto'),
('Jones', 'Main', 'Harrison'),
('Lindsay', 'Park', 'Pittsfield'),
('Smith', 'North', 'Rye'),
('Turner', 'Putnam', 'Stamford'),
('Williams', 'Nassau', 'Princeton'),
('Brown', 'Oak', 'Brooklyn');

INSERT INTO account (account_number, branch_name, balance) VALUES
('A-101', 'Downtown', 500),
('A-102', 'Mianus', 700),
('A-201', 'Perryridge', 900),
('A-215', 'Mianus', 700),
('A-217', 'Brighton', 750),
('A-222', 'Redwood', 700),
('A-305', 'Round Hill', 350),
('A-333', 'Brighton', 850),
('A-444', 'Perryridge', 625),
('A-555', 'Downtown', 1000),
('A-666', 'North Town', 1200);

INSERT INTO depositor (customer_name, account_number) VALUES
('Adams', 'A-101'),
('Brooks', 'A-102'),
('Curry', 'A-201'),
('Davis', 'A-215'),
('Edwards', 'A-217'),
('Green', 'A-222'),
('Hayes', 'A-305'),
('Johnson', 'A-333'),
('Jones', 'A-444'),
('Lindsay', 'A-555'),
('Smith', 'A-666'),
('Turner', 'A-101'),
('Brown', 'A-201');

INSERT INTO loan (loan_number, branch_name, amount) VALUES
('L-11', 'Round Hill', 900),
('L-14', 'Downtown', 1500),
('L-15', 'Perryridge', 1500),
('L-16', 'Perryridge', 1300),
('L-17', 'Downtown', 1000),
('L-23', 'Redwood', 2000),
('L-93', 'Mianus', 500);

INSERT INTO borrower (customer_name, loan_number) VALUES
('Adams', 'L-11'),
('Brooks', 'L-14'),
('Curry', 'L-15'),
('Davis', 'L-16'),
('Edwards', 'L-17'),
('Green', 'L-23'),
('Hayes', 'L-93');

-- Check the tables
SELECT * FROM branch;
SELECT * FROM customer;
SELECT * FROM account;
SELECT * FROM depositor;
SELECT * FROM loan;
SELECT * FROM borrower;
