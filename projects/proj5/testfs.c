#include "image.h"
#include "block.h"
#include "testfs.h"
#include <stdio.h>


#ifdef CTEST_ENABLE

void test_image_open(){
    CTEST_ASSERT
}

void test_image_close(){
    CTEST_ASSERT
}

void test_block_bread(){
    CTEST_ASSERT
}

void test_block_bwrite(){
    CTEST_ASSERT
}

int main(){
    CTEST_VERBOSE(1);
    
    test_image_open();
    test_image_close();
    test_block_bread();
    test_block_bwrite();

    CTEST_RESULTS();
    CTEST_EXIT();
}

#else

int main(){
    
    // Test image open
    image_open("filesystem.img", 1);
    // Test image close
    image_close();
    
    unsigned char buffer[BLOCK_SIZE];
    // Test block bread
    bread(0, buffer);

    // Test block bwrite
    bwrite(0, buffer);

    // Print success message
    printf("Testfs is working\n");
    return 0;
}

#endif