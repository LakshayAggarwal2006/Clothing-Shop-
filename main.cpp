#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Clothing
{
protected:
    int id;
    string name;
    string brand;
    string size;
    string color;
    double price;
    int stock;

public:
    Clothing()
    {
        id = 0;
        name = "";
        brand = "";
        size = "";
        color = "";
        price = 0;
        stock = 0;
    }

    Clothing(int i, string n, string b, string s, string c, double p, int st)
    {
        id = i;
        name = n;
        brand = b;
        size = s;
        color = c;
        price = p;
        stock = st;
    }

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Brand: " << brand << endl;
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Stock: " << stock << endl;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }

    int getStock()
    {
        return stock;
    }

    void setStock(int s)
    {
        stock = s;
    }

    void setPrice(double p)
    {
        price = p;
    }

    virtual string getCategory()
    {
        return "Clothing";
    }

    virtual ~Clothing()
    {
    }
};

class MenClothing : public Clothing
{
public:
    MenClothing(int i, string n, string b, string s, string c, double p, int st)
        : Clothing(i, n, b, s, c, p, st)
    {
    }

    void display() override
    {
        cout << "Category: Men" << endl;
        Clothing::display();
    }

    string getCategory() override
    {
        return "Men";
    }
};

class WomenClothing : public Clothing
{
public:
    WomenClothing(int i, string n, string b, string s, string c, double p, int st)
        : Clothing(i, n, b, s, c, p, st)
    {
    }

    void display() override
    {
        cout << "Category: Women" << endl;
        Clothing::display();
    }

    string getCategory() override
    {
        return "Women";
    }
};

class KidsClothing : public Clothing
{
public:
    KidsClothing(int i, string n, string b, string s, string c, double p, int st)
        : Clothing(i, n, b, s, c, p, st)
    {
    }

    void display() override
    {
        cout << "Category: Kids" << endl;
        Clothing::display();
    }

    string getCategory() override
    {
        return "Kids";
    }
};

class Customer
{
private:
    int customerId;
    string name;
    string phone;

public:
    Customer()
    {
        customerId = 0;
        name = "";
        phone = "";
    }

    Customer(int id, string n, string p)
    {
        customerId = id;
        name = n;
        phone = p;
    }

    void display()
    {
        cout << "Customer ID: " << customerId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }

    int getId()
    {
        return customerId;
    }

    string getName()
    {
        return name;
    }
};

class Bill
{
private:
    int billNumber;
    string customerName;
    double total;
    double discount;
    double finalAmount;

public:
    Bill(int number, string name, double amount)
    {
        billNumber = number;
        customerName = name;
        total = amount;
        discount = 0;
        finalAmount = amount;
    }

    void calculateBill()
    {
        if (total >= 10000)
        {
            discount = total * 0.20;
        }
        else if (total >= 5000)
        {
            discount = total * 0.10;
        }
        else if (total >= 2000)
        {
            discount = total * 0.05;
        }
        else
        {
            discount = 0;
        }

        finalAmount = total - discount;
    }

    void displayBill()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "          URBAN THREADS STORE           " << endl;
        cout << "========================================" << endl;
        cout << "Bill Number: " << billNumber << endl;
        cout << "Customer: " << customerName << endl;
        cout << "----------------------------------------" << endl;
        cout << "Total Amount: Rs. " << total << endl;
        cout << "Discount: Rs. " << discount << endl;
        cout << "Final Amount: Rs. " << finalAmount << endl;
        cout << "========================================" << endl;
        cout << "       Thank You For Shopping!          " << endl;
        cout << "========================================" << endl;
    }
};

class ClothingShop
{
private:
    vector<Clothing*> clothes;
    vector<Customer> customers;

    int clothingId;
    int customerId;
    int billNumber;

public:
    ClothingShop()
    {
        clothingId = 101;
        customerId = 1;
        billNumber = 1001;
    }

    ~ClothingShop()
    {
        for (int i = 0; i < clothes.size(); i++)
        {
            delete clothes[i];
        }
    }

    void addSampleProducts()
    {
        clothes.push_back(new MenClothing(
            clothingId++,
            "Cotton T-Shirt",
            "Nike",
            "L",
            "Black",
            1499,
            20
        ));

        clothes.push_back(new MenClothing(
            clothingId++,
            "Slim Fit Jeans",
            "Levis",
            "32",
            "Blue",
            2999,
            15
        ));

        clothes.push_back(new MenClothing(
            clothingId++,
            "Casual Shirt",
            "Adidas",
            "M",
            "White",
            1999,
            8
        ));

        clothes.push_back(new WomenClothing(
            clothingId++,
            "Summer Dress",
            "Zara",
            "M",
            "Red",
            2499,
            12
        ));

        clothes.push_back(new WomenClothing(
            clothingId++,
            "Denim Jacket",
            "H&M",
            "M",
            "Blue",
            3499,
            10
        ));

        clothes.push_back(new WomenClothing(
            clothingId++,
            "Cotton Top",
            "Westside",
            "S",
            "Pink",
            1299,
            6
        ));

        clothes.push_back(new KidsClothing(
            clothingId++,
            "Kids T-Shirt",
            "Puma",
            "S",
            "Yellow",
            999,
            20
        ));

        clothes.push_back(new KidsClothing(
            clothingId++,
            "Kids Jeans",
            "Levis",
            "28",
            "Black",
            1799,
            14
        ));
    }

    void displayProducts()
    {
        if (clothes.empty())
        {
            cout << endl;
            cout << "No products available." << endl;
            return;
        }

        cout << endl;
        cout << "========== ALL PRODUCTS ==========" << endl;

        for (int i = 0; i < clothes.size(); i++)
        {
            cout << endl;
            cout << "Product " << i + 1 << endl;
            cout << "------------------------" << endl;

            clothes[i]->display();
        }
    }

    void addClothing()
    {
        int choice;

        cout << endl;
        cout << "Select Category" << endl;
        cout << "1. Men" << endl;
        cout << "2. Women" << endl;
        cout << "3. Kids" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice < 1 || choice > 3)
        {
            cout << "Invalid category." << endl;
            return;
        }

        string name;
        string brand;
        string size;
        string color;
        double price;
        int stock;

        cin.ignore();

        cout << "Enter clothing name: ";
        getline(cin, name);

        cout << "Enter brand: ";
        getline(cin, brand);

        cout << "Enter size: ";
        getline(cin, size);

        cout << "Enter color: ";
        getline(cin, color);

        cout << "Enter price: ";
        cin >> price;

        if (price <= 0)
        {
            cout << "Invalid price." << endl;
            return;
        }

        cout << "Enter stock: ";
        cin >> stock;

        if (stock < 0)
        {
            cout << "Invalid stock." << endl;
            return;
        }

        if (choice == 1)
        {
            clothes.push_back(new MenClothing(
                clothingId,
                name,
                brand,
                size,
                color,
                price,
                stock
            ));
        }
        else if (choice == 2)
        {
            clothes.push_back(new WomenClothing(
                clothingId,
                name,
                brand,
                size,
                color,
                price,
                stock
            ));
        }
        else
        {
            clothes.push_back(new KidsClothing(
                clothingId,
                name,
                brand,
                size,
                color,
                price,
                stock
            ));
        }

        cout << endl;
        cout << "Product added successfully." << endl;
        cout << "Product ID: " << clothingId << endl;

        clothingId++;
    }

    void searchProduct()
    {
        int id;

        cout << endl;
        cout << "Enter product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1)
        {
            cout << "Product not found." << endl;
            return;
        }

        cout << endl;
        cout << "========== PRODUCT FOUND ==========" << endl;
        clothes[index]->display();
    }

    void searchByCategory()
    {
        int choice;

        cout << endl;
        cout << "Select Category" << endl;
        cout << "1. Men" << endl;
        cout << "2. Women" << endl;
        cout << "3. Kids" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        string category;

        if (choice == 1)
        {
            category = "Men";
        }
        else if (choice == 2)
        {
            category = "Women";
        }
        else if (choice == 3)
        {
            category = "Kids";
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        bool found = false;

        cout << endl;
        cout << "========== " << category << " CLOTHING ==========" << endl;

        for (int i = 0; i < clothes.size(); i++)
        {
            if (clothes[i]->getCategory() == category)
            {
                cout << endl;
                clothes[i]->display();
                cout << "------------------------" << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "No products found." << endl;
        }
    }

    void updateStock()
    {
        int id;

        cout << endl;
        cout << "Enter product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1)
        {
            cout << "Product not found." << endl;
            return;
        }

        int stock;

        cout << "Product: " << clothes[index]->getName() << endl;
        cout << "Current Stock: " << clothes[index]->getStock() << endl;

        cout << "Enter new stock: ";
        cin >> stock;

        if (stock < 0)
        {
            cout << "Invalid stock." << endl;
            return;
        }

        clothes[index]->setStock(stock);

        cout << "Stock updated successfully." << endl;
    }

    void updatePrice()
    {
        int id;

        cout << endl;
        cout << "Enter product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1)
        {
            cout << "Product not found." << endl;
            return;
        }

        double price;

        cout << "Product: " << clothes[index]->getName() << endl;
        cout << "Current Price: Rs. "
             << clothes[index]->getPrice() << endl;

        cout << "Enter new price: ";
        cin >> price;

        if (price <= 0)
        {
            cout << "Invalid price." << endl;
            return;
        }

        clothes[index]->setPrice(price);

        cout << "Price updated successfully." << endl;
    }

    void deleteProduct()
    {
        int id;

        cout << endl;
        cout << "Enter product ID: ";
        cin >> id;

        int index = findProduct(id);

        if (index == -1)
        {
            cout << "Product not found." << endl;
            return;
        }

        cout << "Product: " << clothes[index]->getName() << endl;

        delete clothes[index];

        clothes.erase(clothes.begin() + index);

        cout << "Product deleted successfully." << endl;
    }

    void addCustomer()
    {
        string name;
        string phone;

        cin.ignore();

        cout << endl;
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        Customer customer(customerId, name, phone);

        customers.push_back(customer);

        cout << endl;
        cout << "Customer added successfully." << endl;
        cout << "Customer ID: " << customerId << endl;

        customerId++;
    }

    void displayCustomers()
    {
        if (customers.empty())
        {
            cout << endl;
            cout << "No customers available." << endl;
            return;
        }

        cout << endl;
        cout << "========== CUSTOMERS ==========" << endl;

        for (int i = 0; i < customers.size(); i++)
        {
            cout << endl;
            customers[i].display();
            cout << "------------------------" << endl;
        }
    }

    int findCustomer(string name)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getName() == name)
            {
                return i;
            }
        }

        return -1;
    }

    int findProduct(int id)
    {
        for (int i = 0; i < clothes.size(); i++)
        {
            if (clothes[i]->getId() == id)
            {
                return i;
            }
        }

        return -1;
    }

    void purchaseProduct()
    {
        if (customers.empty())
        {
            cout << endl;
            cout << "No customers available." << endl;
            cout << "Please add a customer first." << endl;
            return;
        }

        string customerName;

        cin.ignore();

        cout << endl;
        cout << "Enter customer name: ";
        getline(cin, customerName);

        int customerIndex = findCustomer(customerName);

        if (customerIndex == -1)
        {
            cout << "Customer not found." << endl;
            return;
        }

        double total = 0;
        char choice = 'y';

        while (choice == 'y' || choice == 'Y')
        {
            displayProducts();

            int productId;
            int quantity;

            cout << endl;
            cout << "Enter product ID: ";
            cin >> productId;

            int productIndex = findProduct(productId);

            if (productIndex == -1)
            {
                cout << "Product not found." << endl;
            }
            else
            {
                cout << "Product: "
                     << clothes[productIndex]->getName() << endl;

                cout << "Price: Rs. "
                     << clothes[productIndex]->getPrice() << endl;

                cout << "Available Stock: "
                     << clothes[productIndex]->getStock() << endl;

                cout << "Enter quantity: ";
                cin >> quantity;

                if (quantity <= 0)
                {
                    cout << "Invalid quantity." << endl;
                }
                else if (quantity > clothes[productIndex]->getStock())
                {
                    cout << "Not enough stock available." << endl;
                }
                else
                {
                    double amount;

                    amount = clothes[productIndex]->getPrice() * quantity;

                    total = total + amount;

                    int newStock;

                    newStock = clothes[productIndex]->getStock() - quantity;

                    clothes[productIndex]->setStock(newStock);

                    cout << endl;
                    cout << "Product added to purchase." << endl;
                    cout << "Amount: Rs. " << amount << endl;
                }
            }

            cout << endl;
            cout << "Do you want to buy another product? (y/n): ";
            cin >> choice;
        }

        if (total > 0)
        {
            Bill bill(billNumber, customerName, total);

            bill.calculateBill();
            bill.displayBill();

            billNumber++;
        }
        else
        {
            cout << endl;
            cout << "No purchase was made." << endl;
        }
    }

    void showLowStock()
    {
        bool found = false;

        cout << endl;
        cout << "========== LOW STOCK PRODUCTS ==========" << endl;

        for (int i = 0; i < clothes.size(); i++)
        {
            if (clothes[i]->getStock() <= 5)
            {
                cout << endl;
                clothes[i]->display();
                cout << "------------------------" << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "No low stock products." << endl;
        }
    }

    void showMenu()
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "        URBAN THREADS CLOTHING          " << endl;
        cout << "          SHOP MANAGEMENT SYSTEM        " << endl;
        cout << "========================================" << endl;
        cout << "1. Display All Products" << endl;
        cout << "2. Add Clothing" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Search By Category" << endl;
        cout << "5. Update Stock" << endl;
        cout << "6. Update Price" << endl;
        cout << "7. Delete Product" << endl;
        cout << "8. Add Customer" << endl;
        cout << "9. Display Customers" << endl;
        cout << "10. Purchase Product" << endl;
        cout << "11. Show Low Stock" << endl;
        cout << "12. Exit" << endl;
        cout << "========================================" << endl;
    }

    void start()
    {
        addSampleProducts();

        int choice;

        do
        {
            showMenu();

            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                displayProducts();
            }
            else if (choice == 2)
            {
                addClothing();
            }
            else if (choice == 3)
            {
                searchProduct();
            }
            else if (choice == 4)
            {
                searchByCategory();
            }
            else if (choice == 5)
            {
                updateStock();
            }
            else if (choice == 6)
            {
                updatePrice();
            }
            else if (choice == 7)
            {
                deleteProduct();
            }
            else if (choice == 8)
            {
                addCustomer();
            }
            else if (choice == 9)
            {
                displayCustomers();
            }
            else if (choice == 10)
            {
                purchaseProduct();
            }
            else if (choice == 11)
            {
                showLowStock();
            }
            else if (choice == 12)
            {
                cout << endl;
                cout << "Thank you for using Urban Threads Clothing." << endl;
            