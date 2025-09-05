// #include "searchable_tree_bag.hpp"
#include <cstdlib>

// bool searchable_tree_bag::has(int value) const {
//     node* current = tree;
//     while (current != NULL) {
//         if (value == current->value)
//             return true;
//         else if (value < current->value)
//             current = current->l;
//         else
//             current = current->r;
//     }
//     return false;
// }

#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const {
    node *nod = tree;
    while (nod != NULL) {
        if (nod->value > n) {
            nod = nod->r;
        } else if (nod->value < n) {
            nod = nod->l;
        } else {
            return true;
        }
    }
    return false;
}