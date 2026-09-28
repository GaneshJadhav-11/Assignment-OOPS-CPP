#include <iostream>
#include <string>
using namespace std;

// Function Template
template <class T>
T maximum(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

template <class T>
class Inventory
{
private:
    int productID;
    string productName;
    T price;

public:

    void getdata()
    {
        try
        {
            cout << "Enter Product ID: ";
            cin >> productID;

            if (productID <= 0)
                throw productID;

            cin.ignore();

            cout << "Enter Product Name: ";
            getline(cin, productName);

            if (productName.empty())
                throw string("Product name cannot be empty.");

            cout << "Enter Product Price: ";
            cin >> price;

            if (price < 0)
                throw price;
        }
        catch (int)
        {
            cout << "Exception: Product ID must be positive." << endl;
            productID = 0;
        }
        catch (string msg)
        {
            cout << "Exception: " << msg << endl;
        }
        catch (T)
        {
            cout << "Exception: Product price cannot be negative." << endl;
            price = 0;
        }
    }

    void display()
    {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Product Price: " << price << endl;
    }

    T getPrice()
    {
        return price;
    }
};

int main()
{
    const int n = 3;

    Inventory<double> products[n];

    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Product " << i + 1 << ":" << endl;
        products[i].getdata();
    }

    cout << "\n===== PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << ":" << endl;
        products[i].display();
    }

    double maxPrice = products[0].getPrice();

    for (int i = 1; i < n; i++)
    {
        maxPrice = maximum(maxPrice, products[i].getPrice());
    }

    cout << "\nMaximum Product Price: " << maxPrice << endl;

    return 0;
}