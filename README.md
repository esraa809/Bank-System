# 🏦 Bank System Project 

> **A simple  implementing object-oriented programming principles for efficient banking operations.**

---

## 🌟 Project Overview

This C++ Bank Management System provides a structured way to manage client ,Employee and Admin  and handle financial transactions. The project utilizes object-oriented programming (OOP)and DataStructur, basic data encryption, and file-based storage for secure and persistent data management.

---

## ✨ Features

### 📋 Object-Oriented Design
- Encapsulation of client,Employee and Admin data.
- Modular project structure with segmented functionality.

### 🔒 Security & Data Management
- **Vector**: Fixed access time.
- **File-Based Database**: Uses text files to store client,employee and Admin .

### 👥 Client Management
- ➕ **Deposit**
- 💸 **Withdraw**
- 🗂 **Check Balance**
- 🔄 **Transfer To**
- 🗂 **Update Password**

 ### 👥 Employee Management
- 🔄 **Display My Info**
- ➕ **Add New Client**
- 🗒️ **List All Clients**
- 🔍 **Search For Client**
- 🗂 **Edit Client Info**

### 🤝 Admin Management
- 🔄 **Display My Info**
- ➕ **Add New Employee**
- 🗒️ **List All Employees**
- 🔍 **Search For Employee**
- 🗂 **Edit Employee Info**
- 🔐 **Client Management Menu**

### 🛡️ Permission Management
- **Role-based Access Control**
- Restrict functionalities based on user roles.

---

## 🛠️ Code Structure

### Classes
- **Admin**: Represents the bank Admin with all related data and operations.
- **Client**: Represents the bank client with all related data and operations.
- **Employee**: Represents the bank Employee with all related data and operations.
- **Admin Manager**: This represents the Admin data that will appear on the screen.
- **Client Manager**: This represents the Client data that will appear on the screen.
- **Employee Manager**: This represents the Employee data that will appear on the screen.
- **Validation**: Is the data verification process sound or not? If not, I won't let the customer proceed.
- **EntryData**: The data is entered into a loop based on data validation, and data replication is preferred.
- **Screens**: Responsible for displaying data on the console screen and its design
- **Person**: In all shared data, so that it is not repeated more than once.
- **Parser**: The person responsible for segmenting the data entered by the customer, such as name, password, balance, or salary, then compiling the segments to form an object.
- **FilesHelper**: Handling filesز
- - **Files Manager**: implementayion to function in DataSourceInterface.
- **DataSourceInterface**: Virtual Pure Function works to force anyone using them to implemention.



---

## 📚 Screens Implemented
- 🔐 Login Screen as client or employee or admin /Log Out 
- 📋 Main Menu Screen For any choice
- 💸 Transaction Screen For any choice
- 📅 Client & employee &admin Management Screens

---

## 🔧 How It Works

1. **User Authentication**
   - Secure login/logout process.
   - Permission-based access to features.

2. **Client & User Management**
   
3. **Financial Transactions**
   
4. **File Handling**
   - Uses `Clients.txt` and `clientlastid.txt` for persistent data storage.
   - Uses `Employee.txt` and `Employeelastid.txt` for persistent data storage.
   - Uses `Admin.txt` and `Adminlastid.txt` for persistent data storage.

---

## ⚙️ Technologies Used
- **Language**: C++
- **Programming Paradigm**: Object-Oriented Programming (OOP) and datastructure
- **File Handling**: Text-based persistent storage

---

## 📚 License
This project is open-source. Feel free to use and modify it! 🎉

---

## 🤝 Contributions
Contributions are welcome! Submit a pull request with your improvements.

---

## 🏁 Getting Started

### ⚡ How to Run
1. **Clone the Repository** to your local machine.
2. **Compile** the C++ code using your preferred compiler (e.g., `g++`).
3. **Run** the executable and start managing banking operations!

---
