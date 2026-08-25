# Clothing-Shop-Urban Threads Clothing Shop Management System

Project Description

Urban Threads Clothing Shop Management System is a console-based C++ project developed using Object-Oriented Programming concepts.

The project is designed to manage products, customers, stock and purchases in a clothing shop. The system provides a simple menu through which the shop owner can perform different operations.

The project focuses on implementing important OOP concepts in a practical real-world application.

Features

- Display all clothing products
- Add new clothing products
- Search products using product ID
- Search products by category
- Update product stock
- Update product price
- Delete products
- Add customers
- Display customer details
- Purchase clothing products
- Generate bills
- Calculate discounts
- Reduce stock automatically after purchase
- Display low-stock products
- Support for Men, Women and Kids clothing

Technologies Used

- C++
- Object-Oriented Programming
- C++ Standard Library
- Vector
- Console / Terminal

OOP Concepts Used

Classes and Objects

The project contains different classes to represent different parts of the clothing shop.

Main classes are:

- Clothing
- MenClothing
- WomenClothing
- KidsClothing
- Customer
- Bill
- ClothingShop

Objects are created from these classes to perform different operations.

Encapsulation

Data members are kept inside classes using "private" and "protected" access specifiers.

Getter and setter functions are used to access and modify required information.

Inheritance

The MenClothing, WomenClothing and KidsClothing classes inherit properties and functions from the Clothing class.

                    Clothing
                       |
          -----------------------------
          |             |             |
       MenClothing  WomenClothing  KidsClothing

Polymorphism

The "display()" and "getCategory()" functions are virtual functions in the base class.

The derived classes provide their own versions of these functions.

Constructors

Constructors are used to initialize objects when they are created.

Abstraction

The user can perform operations using simple menu options without needing to understand the internal working of the classes.

Clothing Categories

The system supports three categories:

- Men
- Women
- Kids

Product Management

The shop owner can:

1. Add a new product
2. Display products
3. Search for a product
4. Search products by category
5. Update stock
6. Update price
7. Delete a product

Each product contains:

- Product ID
- Name
- Brand
- Size
- Color
- Price
- Stock
- Category

Customer Management

Customers can be registered in the system.

Each customer contains:

- Customer ID
- Customer name
- Phone number

The customer list can also be displayed.

Purchase and Billing

A customer can purchase multiple clothing products in one transaction.

The program:

1. Takes the customer's name
2. Finds the customer
3. Displays available products
4. Takes the product ID
5. Takes the quantity
6. Checks the available stock
7. Calculates the product amount
8. Updates the stock
9. Calculates the total amount
10. Applies the discount
11. Generates the final bill

Discount System

The following discount system is used:

Purchase Amount| Discount
Below Rs. 2000| No discount
Rs. 2000 or more| 5%
Rs. 5000 or more| 10%
Rs. 10000 or more| 20%

Low Stock System

The system checks products whose stock is 5 or less.

These products are displayed under the Low Stock Products option.

Main Menu

1. Display All Products
2. Add Clothing
3. Search Product
4. Search By Category
5. Update Stock
6. Update Price
7. Delete Product
8. Add Customer
9. Display Customers
10. Purchase Product
11. Show Low Stock
12. Exit

Sample Products

The program starts with some sample products:

Men

- Cotton T-Shirt
- Slim Fit Jeans
- Casual Shirt

Women

- Summer Dress
- Denim Jacket
- Cotton Top

Kids

- Kids T-Shirt
- Kids Jeans

These products can be modified or new products can be added using the menu.

How to Run

Using Visual Studio Code

1. Install a C++ compiler such as MinGW.
2. Open the project folder in Visual Studio Code.
3. Create or open "main.cpp".
4. Paste the project code into the file.
5. Open the terminal.
6. Compile the program:

g++ main.cpp -o clothing_shop

7. Run the program:

clothing_shop

Using Code::Blocks

1. Open Code::Blocks.
2. Create a new C++ console project.
3. Open the main source file.
4. Add the project code.
5. Build the project.
6. Run the program.

Project Structure

Urban-Threads-Clothing-Shop
│
├── main.cpp
├── README.md
└── screenshots
    ├── main-menu.png
    ├── products.png
    ├── customers.png
    ├── purchase.png
    └── bill.png

Future Improvements

The project can be further improved by adding:

- File handling
- Database connectivity
- Login system
- Product images
- Customer purchase history
- Order history
- Online payment
- GUI interface
- Online shopping functionality
- Admin and customer login
- Product sorting
- Product filtering

Conclusion

The Urban Threads Clothing Shop Management System demonstrates how Object-Oriented Programming can be used to solve a real-world problem.

The project implements classes, objects, encapsulation, inheritance, polymorphism, constructors and abstraction while providing useful clothing shop management features.