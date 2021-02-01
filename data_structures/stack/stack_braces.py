class Stack:

	def __init__(self):
		self.stack = []
	
	def append(self, item):
		self.stack.append(item)

	def pop(self):
		return self.stack.pop(len(self.stack) - 1)
	
	def is_empty(self):
		return (len(self.stack) == 0)


def brace_checker(brace_open: str, brace_close: str):
	if brace_open == "(" and brace_close == ")":
		return True
	if brace_open == "[" and brace_close == "]":
		return True
	if brace_open == "{" and brace_close == "}":
		return True
	return False


def is_balanced(string_to_check: str):
	index = 0
	is_balanced = True
	stack = Stack()
	
	while index < len(string_to_check) and is_balanced:
		brace = string_to_check[index]
		
		if brace in "({[":
			stack.append(brace)
		else:
			if stack.is_empty():
				is_balanced = False
			else:
				open_brace = stack.pop()
				brace_to_check = brace_checker(open_brace, brace)
				
				if not brace_to_check:
					is_balanced = False
		index += 1
	
	if is_balanced and stack.is_empty():
		return True
	return False

print(is_balanced("((((((((((([])))))))))))[]()])("))
	