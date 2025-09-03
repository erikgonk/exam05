// #include "searchable_array_bag.hpp"

// bool searchable_array_bag::has(int value) const {
//     for (int i = 0; i < size; i++){
//         if (data[i] == value)
//             return true;
//     }
//     return false;
// }

#include "searchable_array_bag.hpp"

bool    searchable_array_bag::has(int n) const {
  for (int i = 0; i < size; i++) {
    if (data[i] == n) {
        return true;
    }
  }
  return false;
}
