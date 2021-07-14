class Node:

	def __init__(self, data=None):
		self.data = data
		self.next = None
		self.is_head = False
	
	def __str__(self):
		return f"{self.data}"
	

class SingleLinkedList:

	def __init__(self):
		self.head = Node()

	def append(self, data) -> None:
		new_node = Node(data)
		cur_node = self.head
		
		while cur_node.next != None:
			cur_node = cur_node.next
		cur_node.next = new_node
	
	def display(self, display_type="Vertical"):
		values: list = self.get_all_values()
		
		if len(values) == 0:
			return "Linked list is empty"

		is_arrow = True
		for itter_num, value in enumerate(values):
			if itter_num == len(values) - 1:
				is_arrow = False
			
			node_msg_initial = f"VALUE OF NODE: {value}, NODE INDEX: {itter_num}, "
			next_node = f"NEXT NODE INDEX: {itter_num + 1}"
			
			if is_arrow:
				node_msg = "[" + node_msg_initial + next_node + "]"
			else:
				node_msg = "[" + node_msg_initial + "NEXT NODE INDEX: None" + "]"

			if display_type == "Horizontal":
				print(node_msg, end="")
				
				if is_arrow:
					print("-->", end="")
			else:
				print(node_msg)
				
				if is_arrow:
					print("|".rjust(len(node_msg) // 2))
					print("|".rjust(len(node_msg) // 2))
					print("V".rjust(len(node_msg) // 2))

	def length(self):
		total = 0
		cur_node = self.head
		cur_node.is_head = True
		
		while True:
			if cur_node.data:
				total += 1

			if cur_node.next == None:
				break
			cur_node = cur_node.next
		
		return total
	
	def get_all_values(self) -> list:
		values = []
		
		if self.length() == 0:
			return values

		cur_node = self.head
		cur_node.is_head = True
		
		while True:
			if not cur_node.is_head:
				values.append(cur_node.data)
				
				if cur_node.next == None:
					break
			cur_node = cur_node.next

		return values
		
	def get_value_by_index(self, user_index:int):
		if (not (user_index >= 0 and user_index < self.length())):
			raise IndexError("Index out of range")
		
		if self.length() == 0:
			raise Exception("Eror: linked list is empty, there's nothing to get")

		cur_node = self.head
		inner_index = 0
		
		result = None
		while True:
			if cur_node.next == None:
				break
			cur_node = cur_node.next
			if inner_index == user_index and cur_node.data:
				result = cur_node.data
				break
			
			inner_index += 1
		return result
	
	
	def find_index_with_value(self, user_value):
		if user_value not in self.get_all_values():
			raise Exception("Value is not in the linked list")
	
		cur_node = self.head
		inner_index = 0

		while True:
			if cur_node.next == None:
				break
			cur_node = cur_node.next

			if user_value == cur_node.data:
				return inner_index
			
			inner_index += 1
	
	def get_node_by_index(self, user_index):
		if (not (user_index >= 0 and user_index < self.length())):
			raise IndexError("Index out of range")
		
		if self.length() == 0:
			raise Exception("Eror: linked list is empty, there's nothing to get")

		cur_node = self.head
		inner_index = 0
		
		result = None
		while True:
			if cur_node.next == None:
				break
			cur_node = cur_node.next
			if inner_index == user_index and cur_node.data:
				result = cur_node
				break
			
			inner_index += 1
		return result
	
	def erase_by_index(self, user_index):
		if (not (user_index >= 0 and user_index < self.length())):
			raise IndexError("Index out of range")
		
		if self.length() == 0:
			raise Exception("Error: the linked list is empty, nothing to erase")
	
		cur_node = self.head
		cur_node.is_head = True
		inner_index = 0

		
		while True:
			if inner_index == user_index:

				cur_node = self.get_node_by_index(inner_index)
				if cur_node.next == None and inner_index == 0:
					self.head.next = None

				elif cur_node.next == None and self.length() - 1 == inner_index:
					prev_node = self.get_node_by_index(inner_index-1)
					prev_node.next = None
				
				elif cur_node.next != None and inner_index != 0:
					prev_node = self.get_node_by_index(inner_index - 1)
					next_node = self.get_node_by_index(inner_index + 1)
					
					prev_node.next = next_node
				
				elif cur_node.next != None and inner_index == 0:
					self.head.next = self.get_node_by_index(inner_index + 1)
				break	
			inner_index += 1

	def erase_by_value_of_node(self, user_value):
		if user_value not in self.get_all_values():
			raise Exception("Value is not in the linked list")

		inner_index = 0
		cur_node = self.head
		cur_node.is_head = True
		while True:
			cur_node = self.get_node_by_index(inner_index)
			if cur_node.data == user_value:

				if cur_node.next == None and inner_index == 0:
					self.head.next = None

				elif cur_node.next == None and self.length() - 1 == inner_index:
					prev_node = self.get_node_by_index(inner_index-1)
					prev_node.next = None
				
				elif cur_node.next != None and inner_index !=0:
					prev_node = self.get_node_by_index(inner_index - 1)
					next_node = self.get_node_by_index(inner_index + 1)
					
					prev_node.next = next_node
				elif cur_node.next != None and inner_index == 0:
					self.head.next = self.get_node_by_index(inner_index + 1)
				break	
			inner_index += 1
