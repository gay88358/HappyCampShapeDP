#ifndef UTFILE_H
#define UTFILE_H

#include "./include/file.h"

TEST(file, getName) {
    // create
    File *f = new File();
    // invoke
    string name = f->getName();
    // verify
    ASSERT_EQ("file", name);
}

#endif