Online Store Management System

Project Overview

This project is a console-based || Online Store Management System ||  developed using C++ and built using || Object-Oriented Programming (OOP) ||  principles.
The system is designed to manage store functionalities through two main user roles: Admin and Customer.
Each role has its own set of features and is protected through an authentication system to ensure authorized access.

The project is ideal for practicing real-world software design using core OOP concepts such as classes and objects, inheritance,polymorphism,encapsulation, and file handling.

---

User Roles

1. Admin
Admins have complete control over the store. Admin features include:
- Logging in through a secure username/password system
- Adding new products to the inventory
- Updating or deleting existing products
- Viewing the list of all available products
- Managing customer data (optional, if implemented)

2. Customer
Customers can interact with the store in a more limited but user-friendly way:
- Creating an account or logging in with credentials
- Browsing available products
- Searching for specific products
- Adding items to their cart
- Placing orders
- Viewing order history (if implemented)

Each user must authenticate themselves to gain access to their respective dashboard.

--Authentication System

The authentication mechanism ensures that:
- Only authorized admins can manage the store
- Customers can only access their own data and place orders after logging in
- User data is stored securely (usually using basic file handling for beginners)

---

--GUI Version (Qt Creator)

In addition to the console-based version, a Graphical User Interface (GUI) for the Online Store System has been developed using Qt Creator. The GUI provides a more user-friendly experience, though it is currently in its early stage of development.

--Current Features:

Basic GUI layout for login and role selection
Simple Admin and Customer dashboards
Product listing interface

--Features Under Development / Planned:
Full integration of Admin and Customer features into the GUI
Data synchronization between GUI and file system
Improved UI/UX design with better input validation and feedback
Real-time product updates and order placement via GUI

--Note:
The GUI version is currently a work in progress, and contributions or suggestions for improvement are welcome. The console version remains fully functional and complete, while the GUI version aims to enhance usability and modernize the interface.

/ConsoleVersion
    - main.cpp
    - Admin.h/.cpp
/GUIVersion
    - mainwindow.ui
    - mainwindow.cpp
    - OnlineStore.pro

 
OOP Concepts Used
This project was designed as a demonstration of Object-Oriented Programming (OOP) in C++. The following principles and features are implemented:

- **Classes and Objects:** Core building blocks for Admin, Customer, Product, Order, etc.
- **Inheritance:** Used to create a shared hierarchy between common user functionality (e.g., base `User` class).
- **Encapsulation:** Data members are kept private and accessed through public methods.
- **Polymorphism:** Virtual functions may be used where appropriate to handle dynamic behavior (e.g., displaying dashboards or menus).
- **Constructors/Destructors:** Used for object initialization and cleanup.
- **File Handling:** Data persistence is handled via reading/writing to files for user login, product lists, and order history.

---

Project Structure (Example)

- `main.cpp` – Entry point, menu, and user interface handling
- `User.h/.cpp` – Base class for Admin and Customer
- `Admin.h/.cpp` – Admin-specific functions and logic
- `Customer.h/.cpp` – Customer functionality
- `Product.h/.cpp` – Product data and actions
- `Authentication.h/.cpp` – Login and signup mechanisms`

