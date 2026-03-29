# Inventory Management System (IMS) - ElectroShock Pro

A comprehensive command-line based Inventory Management System designed to streamline business operations through efficient tracking of products, suppliers, customers, and transactions.

## 🎯 Overview

The Inventory Management System is a robust C-based application that enables businesses to manage their inventory operations with precision. Built with a focus on reliability and efficiency, it provides real-time inventory tracking, transaction logging, and comprehensive reporting capabilities.

## ✨ Key Features

### 📦 Inventory Management
- **Create & Manage Items** - Add products to the inventory system with detailed specifications
- **Real-time Quantity Tracking** - Automatic stock level updates based on transactions
- **Price & Reorder Management** - Track item prices and reorder quantities
- **Inventory Reports** - Generate detailed reports on current inventory status

### 🏢 Supplier Management
- **Supplier Registry** - Maintain a comprehensive supplier database with contact information
- **Address & Contact Details** - Store complete supplier details including state, PIN, and phone
- **Supplier Transactions** - Track purchases from suppliers
- **Supplier Reports** - Generate supplier-specific reports

### 👥 Customer Management
- **Customer Database** - Manage customer information and profiles
- **Sales Tracking** - Record and monitor customer transactions
- **Customer Details** - Store comprehensive contact and address information
- **Customer Reports** - Generate transaction history and customer analytics

### 📊 Transaction Management
- **Purchase Transactions** - Log and track all procurement activities
- **Sale Transactions** - Record customer sales with automatic inventory updates
- **Transaction History** - Complete audit trail of all business activities
- **Transaction Reporting** - Detailed transaction logs and analysis

### 🗑️ Data Management
- **Delete Functionality** - Remove outdated or erroneous records with audit trails
- **Data Archival** - Maintain deleted records for compliance and audit purposes
- **File-based Persistence** - Secure data storage using binary files

## 🛠️ Tech Stack

- **Language:** C (ANSI C Standard)
- **Data Storage:** Binary files (`.dat`) and Text files (`.txt`)
- **Compilation:** Standard C compiler (GCC/MSVC)
- **Architecture:** File-based persistence with in-memory processing

## 📋 Prerequisites

- **GCC Compiler** or any ANSI C compiler
- **Windows/Linux/macOS** - Platform independent
- **2 MB** of free disk space for data files
- **Terminal/Command Prompt** access

## 🚀 Installation & Setup

### Step 1: Clone or Extract the Repository
```bash
# Navigate to the project directory
cd "C-PROGRAMMING"
```

### Step 2: Compile the Program
```bash
# Using GCC
gcc -o prac2 IMS_Final.c

# Or using MSVC (Visual Studio)
cl IMS_Final.c
```

### Step 3: Run the Application
```bash
# On Windows
prac2.exe

# On Linux/macOS
./prac2
```

## 💻 Usage Guide

### Main Menu Navigation

Upon launching the application, you'll encounter three main options:

```
1. **D - Display Information**
   - View current inventory
   - Display supplier database
   - Show customer records
   - Review purchase transactions
   - Review sale transactions

2. **A - Perform Action**
   - Enter new items in inventory
   - Customize existing items
   - Create new suppliers
   - Update supplier details
   - Add new customers
   - Modify customer information
   - Record purchase transactions
   - Record sale transactions

3. **X - Delete Records**
   - Remove items from inventory
   - Delete supplier records
   - Remove customer profiles
   - Delete transaction records
```

### Example Workflow

**Creating a New Product:**
1. Select "A" (Perform Action)
2. Choose "1" (Enter New Item)
3. Enter item code, description, quantity, price, and reorder quantity
4. Record is automatically added to the database

**Recording a Sale:**
1. Select "A" (Perform Action)
2. Choose "8" (Record Sale Transaction)
3. Enter item code, quantity, and customer details
4. Inventory is automatically updated

## 📊 Project Structure

```
├── IMS_Final.c                 # Main application source code
├── item_master.dat             # Binary file - Item inventory data
├── supplier_master.dat         # Binary file - Supplier information
├── customer_master.dat         # Binary file - Customer database
├── Purchasetransaction_log.dat # Binary file - Purchase history
├── item_master.txt             # Text log - Item records
├── supplier.txt                # Text log - Supplier records
├── customer.txt                # Text log - Customer records
├── PurchaseTransaction.txt     # Text log - Purchase transactions
├── deleted_items.txt           # Archive - Deleted items
├── deleted_suppliers.txt       # Archive - Deleted suppliers
├── deleted_customers.txt       # Archive - Deleted customers
└── README.md                   # Documentation
```

### Data Storage Architecture

- **Binary Files (`.dat`)**: Fast, indexed access for operational data
- **Text Files (`.txt`)**: Human-readable logs and reports
- **Archive Files**: Maintain records of deleted entries for audit trails

## 🔧 Core Functionalities

### Item Management Module
- Item creation with unique codes
- Dynamic quantity adjustment during transactions
- Automatic reorder alert tracking
- Price management and updates

### Transaction Processing
- Real-time inventory updates
- Transaction type differentiation (Purchase/Sale)
- Automatic quantity adjustments
- Cost calculation and tracking

### Data Integrity
- Duplicate item code prevention
- Transaction validation
- Data consistency checks
- Audit trail maintenance

## 📈 System Capabilities

| Feature | Capability |
|---------|-----------|
| Max Items | Limited by disk space |
| Max Suppliers | Limited by disk space |
| Max Customers | Limited by disk space |
| Data Types | Integer, Float, String (up to 100 chars) |
| File Format | Binary (.dat) and Text (.txt) |
| Reporting | Real-time report generation |

## 🎓 Educational Value

This project demonstrates:
- File I/O operations in C
- Struct-based data organization
- CRUD operations (Create, Read, Update, Delete)
- Menu-driven application design
- Data persistence and management
- Business logic implementation

## 🔐 Data Management

The system maintains multiple data files for redundancy and audit purposes:
- **Active Records**: Stored in `.dat` files for fast access
- **Transaction Logs**: Maintained in `.txt` files for audit trails
- **Deleted Records**: Archived in separate files for compliance
- **Backup Compatibility**: Text exports for data recovery

## 🐛 Troubleshooting

**Common Issues:**

1. **Compilation Errors**
   - Ensure all header files are included
   - Use ANSI C compatible compiler

2. **File Access Issues**
   - Check directory permissions
   - Ensure write access to application directory

3. **Data Display Problems**
   - Verify data files exist
   - Check file format consistency

## 📄 License

This project is provided as-is for educational purposes. Modify and distribute freely with appropriate attribution.

## 📞 Support & Feedback

For issues or suggestions regarding this project:
- Review the source code documentation in `IMS_Final.c`
- Check the generated `.txt` log files for transaction history
- Examine data file structures for debugging

---

**Last Updated:** March 2026  
**Version:** 1.0 Final
