
// сортировка пузырьком
//for (int i = 0; i < n; i++) {
//	int unordered = 1;
//	for (int j = 0; j < n - 1 - i; j++) {
//		if (arr[j] > arr[j + 1]) {
//			swap(&arr[j], &arr[j + 1]);
//			unordered = 0;
//		}
//	}
//	if (unordered) break;
//}
//for (int i = 0; i < n; i++)
//	printf("%d ", arr[i]);

	// сортировка вставками
	//start = clock();
	//for (int i = 0; i < n - 1; i++) {
	//	int key = arr [i + 1];
	//	for (int j = i; j >= 0; j--) {
	//		if (key < arr[j])
	//			swap(&arr[j], &arr[j + 1]);
	//		else break;
	//	}
	//}
	//stop = clock();
	///*for (int i = 0; i < n; i++) {
	//	printf("%d ", arr[i]);
	//}*/
	//printf("\n");
	//double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
	//printf("%lf seconds\n", time);