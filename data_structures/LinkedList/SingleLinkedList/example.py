import time
import random
from SingleLinkedList import SingleLinkedList


TIME_TO_WAIT = 12

new_linked_list = SingleLinkedList()

# Appending new values to the linked list
print("Appending new values...")

python_list = []
for i in range(0, 10):
	random_intger = random.randint(1, 101)
	python_list.append(random_intger)
	new_linked_list.append(random_intger)


# Getting all values
values_of_linked_list: list = new_linked_list.get_all_values()

print("Values of the linked list:")
print(values_of_linked_list)

# Finding the lenght of the linked list
print("Let's find the length of our linked list")
time.sleep(TIME_TO_WAIT)
print(new_linked_list.length())

# Getting value from linked list
print("Now let's find the value of node with index 4!")
time.sleep(TIME_TO_WAIT)
value = new_linked_list.get_value_by_index(4)
print(value)

# Finding index with value
print(f"Let's find out the index of {python_list[8]} in the linked list!")
time.sleep(TIME_TO_WAIT)
index = new_linked_list.find_index_with_value(python_list[8])
print(index)

time.sleep(TIME_TO_WAIT)
print("You also can get node object in memory using the method get_node_by_index")

# Erasing data from the linked list
time.sleep(TIME_TO_WAIT)
print("You can erase data from the linked list. There are two methods:\n\
1)erasing by index\n2)erasing by value.\nLet's try all of them!")

time.sleep(TIME_TO_WAIT)

# Erasing by index
print(f"Let's erase {new_linked_list.get_value_by_index(0)} using index 0")
print(new_linked_list.get_all_values())
new_linked_list.erase_by_index(0)
print(new_linked_list.get_all_values())
print("Done")

time.sleep(TIME_TO_WAIT)

print()
# Erasing by value of node
index_six_data = new_linked_list.get_node_by_index(6).data
print(f"Right now we'll use the value of node to erase the node, let's take {index_six_data}")

print(new_linked_list.get_all_values())
new_linked_list.erase_by_value_of_node(index_six_data)
print(new_linked_list.get_all_values())
print("Done")

time.sleep(TIME_TO_WAIT)

print("Now let's display our linked list with full information!")
time.sleep(TIME_TO_WAIT)

print()

new_linked_list.display()
