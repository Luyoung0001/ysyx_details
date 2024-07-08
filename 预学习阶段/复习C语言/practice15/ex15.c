#include <stdio.h>

int main(int argc, char* argv[]) {
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char* names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int* cur_age = ages;
    char** cur_name = names;

    // second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for (
        cur_name = names, cur_age = ages;
        (cur_age - ages) <
        count;  // 指针之间可以进行减法运算，这种操作在 C
                // 语言中是合法且常见的。当你对两个指向同一数组的指针进行减法运算时，
        //结果是这两个指针之间的元素数量。这是因为指针减法的结果是两个指针地址之差除以指向的数据类型的大小。
        cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
