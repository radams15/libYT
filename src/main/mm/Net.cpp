//
// Created by Rhys on 18/02/2022.
//

#include <Net.h>

mm::Net::Net(struct ::Net* ptr) {
    this->ptr = ptr;
}

struct ::Net *mm::Net::cptr() {
    return ptr;
}