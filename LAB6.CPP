// Aim of the program : Write a program in c++ to find the maximum profit nearest to but not exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
// Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order, according to their profit /weight.
// Input:
// Enter the number of items: 3
// Enter the profit and weight of item no 1: 27  16
// Enter the profit and weight of item no 2: 14  12
// Enter the profit and weight of item no 3: 26  13
// Enter the capacity of knapsack:18
// Output:
// Item No     profit      Weight        Amount to be taken
// 3              26.000000   13.000000    1.000000
// 1       27.000000     16.000000       0.312500
// 2              14.000000     12.000000       0.000000
// Maximum profit: 34.437500

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct ITEM {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};
double fractionalKnapsack(vector<ITEM>& items, double capacity) {
    double maxProfit = 0.0;
    for (int i = 0; i < items.size(); ++i) {
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }
    make_heap(items.begin(), items.end(), [](const ITEM& a, const ITEM& b) {
        return a.profit_weight_ratio < b.profit_weight_ratio;
    });
    while (!items.empty() && capacity > 0) {
        pop_heap(items.begin(), items.end(), [](const ITEM& a, const ITEM& b) {
            return a.profit_weight_ratio < b.profit_weight_ratio;
        });
        
        ITEM currentItem = items.back();
        items.pop_back();

        double weightTaken = min(currentItem.item_weight, capacity);
        double profitToAdd = weightTaken * currentItem.profit_weight_ratio;

        cout << "Item No " << currentItem.item_id << "\t"
             << fixed << setprecision(6) << currentItem.item_profit << "\t"
             << fixed << setprecision(6) << currentItem.item_weight << "\t"
             << fixed << setprecision(6) << weightTaken << endl;

        maxProfit += profitToAdd;
        capacity -= weightTaken;
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<ITEM> items(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter the profit and weight of item no " << i + 1 << ": ";
        cin >> items[i].item_profit >> items[i].item_weight;
        items[i].item_id = i + 1;
    }

    double capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(items, capacity);

    cout << "Maximum profit: " << fixed << setprecision(6) << maxProfit << endl;

    return 0;
}



// 6.2

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;


// struct SYMBOL {
//     char alphabet;
//     int frequency;
//     SYMBOL* left;
//     SYMBOL* right;

//     SYMBOL(char alpha, int freq) : alphabet(alpha), frequency(freq), left(nullptr), right(nullptr) {}
// };


// struct CompareSymbols {
//     bool operator()(SYMBOL* left, SYMBOL* right) {
//         return left->frequency > right->frequency;
//     }
// };

// SYMBOL* buildHuffmanTree(vector<SYMBOL*>& symbols) {
//     priority_queue<SYMBOL*, vector<SYMBOL*>, CompareSymbols> pq;

    
//     for (SYMBOL* symbol : symbols) {
//         pq.push(symbol);
//     }

//     while (pq.size() > 1) {
//         SYMBOL* left = pq.top();
//         pq.pop();
//         SYMBOL* right = pq.top();
//         pq.pop();

//         SYMBOL* mergedSymbol = new SYMBOL(',', left->frequency + right->frequency);

        
//         mergedSymbol->left = left;
//         mergedSymbol->right = right;

//         pq.push(mergedSymbol);
//     }

//     return pq.top(); 
// }

// void inOrderTraversal(SYMBOL* root) {
//     if (!root) {
//         return;
//     }

//     inOrderTraversal(root->left);
//     cout << root->alphabet << " ";
//     inOrderTraversal(root->right);
// }

// int main() {
//     int n;
//     cout << "Enter the number of distinct alphabets: ";
//     cin >> n;

//     vector<SYMBOL*> symbols;
//     cout << "Enter the alphabets: ";
//     for (int i = 0; i < n; i++) {
//         char alpha;
//         cin >> alpha;
//         symbols.push_back(new SYMBOL(alpha, 0));
//     }

//     cout << "Enter its frequencies: ";
//     for (int i = 0; i < n; i++) {
//         cin >> symbols[i]->frequency;
//     }

//     SYMBOL* root = buildHuffmanTree(symbols);

//     cout << "In-order traversal of the tree (Huffman): ";
//     inOrderTraversal(root);

//     return 0;
// }