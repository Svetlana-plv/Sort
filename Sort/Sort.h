#pragma once
void bubble_sort(arr, n, comp);
void insert_sort(arr, n, comp);
void select_sort(arr, n, comp);
void merge_sort(arr, left, right);
void merge_array(arr, left, mid, right);// ��������������� ������� ���������������� ������ �������
void merge_sort_2(arr, tmp, left, right);
void merge_array_2(arr, tmp, left, mid, right);// ��������������� ������ ���������� � �������
void quick_sort(arr, left, right);
int partition(arr, left, right);
int max_num(arr, n);
void radix_sort(arr, tmp, n);
void counting(arr, tmp, n, p);