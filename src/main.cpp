#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// ===================== T11: shared structs + helpers (splitCsv, binarySearchProduct, findProduct) =====================
// Owner: Nhan Ngoc Phuong Nhi | Flowcharts: docs/flowcharts/T11-*.drawio.png
// Every record type the team agreed on lives here, so all tasks use the same names.

struct Product {            // one line of products.csv
    string id, name, category, brand;
    long long price;        // money uses long long
    double rating;
};

struct Event {              // one line of customer_events.csv
    string sessionId, timestamp, event, productId;
};

struct Link {               // one line of identity_links.csv
    string sessionId, customerId, linkedAt, linkSource;
};

struct Transaction {        // one line of transactions.csv
    string id, customerId, productId;
    int quantity;
    long long totalAmount;
};

struct Preference {         // inferred preference of one session
    string category, brand;
    long long budget;
};

struct Recommendation {     // one scored product
    Product product;
    int score;
    string reasons;         // extension: "same category +3, ..."
};

// Split one CSV line by ',' into cols. Removes a trailing '\r' (Windows line ending).
void splitCsv(string line, vector<string>& cols) {
    cols.clear();
    if (line.size() > 0 && line[line.size() - 1] == '\r') {
        line.erase(line.size() - 1);
    }
    string cur = "";
    for (int i = 0; i < (int)line.size(); i++) {
        if (line[i] == ',') {
            cols.push_back(cur);
            cur = "";
        } else {
            cur = cur + line[i];
        }
    }
    cols.push_back(cur);
}

// Recursive binary search on products sorted by id (ascending).
// Returns the index of the product with this id, or -1 if not found.
int binarySearchProduct(const vector<Product>& products, const string& productId, int left, int right) {
    if (left > right) {
        return -1;                                   // base case: empty range
    }
    int mid = left + (right - left) / 2;         // same formula as Session 6 slides
    if (products[mid].id == productId) {
        return mid;
    }
    int result;
    if (productId < products[mid].id) {
        result = binarySearchProduct(products, productId, left, mid - 1);    // search left half
    } else {
        result = binarySearchProduct(products, productId, mid + 1, right);   // search right half
    }
    return result;
}

// Find a product by id. Precondition: products is sorted by id ascending.
int findProduct(const vector<Product>& products, const string& productId) {
    int result = binarySearchProduct(products, productId, 0, (int)products.size() - 1);
    return result;
}
// =================== end T11 ===================
