#include "bigint.hpp"

bigint::bigint() {
    digits = '0';
}

bigint::bigint(unsigned int n) {
    digits.clear();
    if (n == 0) {
        digits = '0';
    } else {
        while (n > 0) {
            digits += n % 10;
            n /= 10;
        }
    }
}

bigint::bigint(bigint& b) {
    this->digits = b.digits;
}
