# 🧮 CPP Client Database System

A C++ database-driven management system designed to streamline operations for a welding supply business. This application allows users to view, update, and manage records across four core entities: **Clients**, **Sales Representatives**, **Products**, and **Sales**.

> Developed as a capstone project for a Programming Fundamentals II course.

---

## 📂 Project Structure

├── client.cpp / client.h # Client module: add, delete, view, and edit client records ├── salesrep.cpp / salesrep.h # Sales Rep module: manage rep details ├── product.cpp / product.h # Product module: inventory management ├── sales.cpp / sales.h # Sales module: link reps, clients, and products ├── mainWeldingCentral.cpp # Main entry point and navigation ├── ClientsFile.txt # Preloaded data for Clients ├── SalesRepFile.txt # Preloaded data for Sales Representatives ├── productsFile.txt # Preloaded data for Products ├── salesFile.txt # Preloaded data for Sales

---

## 🛠️ Features

- **Interactive Menu System**  
  Navigate between clients, sales reps, products, and sales modules via a clear, console-based UI.

- **File-Based Data Management**  
  Each module reads and writes to its own text-based database file (e.g., `ClientsFile.txt`), allowing persistent storage across sessions.

- **CRUD Functionality for All Modules**  
  - Add new records  
  - Update existing data  
  - Delete records  
  - View listings in a clean tabular format

- **Relational Linking**  
  Sales entries connect clients, reps, and products into a unified transaction system.

---

## 🧑‍💻 Authors

- **Nolan Hardeman**  
  [GitHub](https://github.com/nhardemandata) | [LinkedIn](https://www.linkedin.com/in/datascientistnolan/)

- **Mary Huh**

---

## 🏁 Getting Started

### 🔧 Requirements
- C++ compiler (e.g., `g++`)
- Terminal or command prompt for execution

### 🚀 Build Instructions

```bash
g++ mainWeldingCentral.cpp client.cpp salesrep.cpp product.cpp sales.cpp -o WeldingCentral
./WeldingCentral
```

---
