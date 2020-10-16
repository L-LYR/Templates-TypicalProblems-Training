#include <limits.h>  // INT_MAX INT_MIN
#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc() free()
#include <string.h>  // memset()

#define BASE 10          // radix
#define INT_DEC_BITS 10  // max digit of a 32-bits decimal number
// static linked list teminated by -1
struct node {
    int digits[INT_DEC_BITS];
    int num;
    int next;
};
/*
    int_to_digits:
        transform an integer into digits.
*/
void int_to_digits(int x, int digits[]) {
    int i;

    i = 0;
    while (x > 0) {
        digits[i++] = x % BASE;
        x /= BASE;
    }
}
/*
    arr_to_node_list:
        transform an integer array to a static linked list.
*/
struct node* arr_to_node_list(int arr[], int n) {
    struct node* res;
    int i;

    res = malloc(sizeof(*res) * n);
    if (res == NULL) {  // handle memory allocation failure
        fprintf(stderr, "%s:%d:malloc() failed!", __FILE__, __LINE__);
        exit(0);
    }
    memset(res, 0, sizeof(*res) * n);  // initialize to 0

    // transform
    for (i = 0; i < n; i++) {
        int_to_digits(arr[i], res[i].digits);
        res[i].num = arr[i];
        res[i].next = i + 1;
    }
    res[n - 1].next = -1;  // tail node

    return res;
}
/*
    node_list_to_arr:
        transform a static linked list to an array.
*/
int* node_list_to_arr(struct node* list, int begin, int n) {
    int i, *res, j;

    res = malloc(sizeof(*res) * n);
    for (j = 0, i = begin; i != -1; i = list[i].next, j++) {
        res[j] = list[i].num;
    }
    return res;
}
/*
    sort_by_digit:
        sort the list once by the i-th digit
        return the index of head node
*/
int sort_by_digit(struct node* list, int begin, int i) {
    int head[BASE], tail[BASE];
    int j, k, end;

    // sort by i-th digit
    memset(head, -1, sizeof(head));
    for (j = begin; j != -1; j = list[j].next) {
        k = list[j].digits[i];
        if (head[k] == -1) {  // If empty, insert at head.
            head[k] = j;
        } else {  // If not, insert at tail.
            list[tail[k]].next = j;
        }
        tail[k] = j;  // point to tail node
    }

    // reconnect
    begin = -1;
    for (j = 0; j < BASE; j++) {
        if (head[j] == -1) continue;
        if (begin == -1)  // set new head
            begin = head[j];
        else  // connect
            list[end].next = head[j];
        for (k = head[j]; k != tail[j]; k = list[k].next)
            ;
        end = k;  // set new tail
    }
    list[end].next = -1;

    return begin;
}
/*
    radix_sort:
        use radix sort on an n-size integer array.
*/
int* radix_sort(int arr[], int n) {
    struct node* num_list;
    int begin, i, *res;

    // initialize
    num_list = arr_to_node_list(arr, n);
    begin = 0;

    // sort by each digit
    for (i = 0; i < BASE; i++)
        begin = sort_by_digit(num_list, begin, i);

    res = node_list_to_arr(num_list, begin, n);
    free(num_list);
    return res;
}
int main(void) {
    int arr[] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    int n = sizeof(arr) / sizeof(*arr);
    int* res = radix_sort(arr, n);
    int i;

    for (i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }

    for (i = 0; i < n; i++) {
        printf("%d%c", res[i], " \n"[i == n - 1]);
    }
    free(res);

    return 0;
}