def bubble_sort(list):
	num_of_elements = len(list)
	
	for i in range(num_of_elements - 1):
		for j in range(num_of_elements - i - 1):
			if list[j] > list[j+1]:
				list[j], list[j+1] = list[j+1], list[j]
	return list

print(bubble_sort([9,3,1,2,6,5,7,8,4,10]))