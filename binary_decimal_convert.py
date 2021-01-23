def from_decimal_to_binary(val: int):
	bin_res = []
	res = val // 2
	binary = (not(val % 2 == 0))
	bin_res.append(str(int(binary)))
	while res:
		binary = (not(res % 2 == 0))
		bin_res.append(str(int(binary)))
		res = res // 2
	
	final_res: list = bin_res[::-1]
	
	return "".join(final_res)
		

def from_binary_to_decimal(val: str):
	values_to_sum = []
	
	degree = 0
	for i in val[::-1]:
		values_to_sum.append(int(i) * (2 ** degree))
		degree += 1
	
	return sum(values_to_sum)
	


print(from_decimal_to_binary(165))
print(from_binary_to_decimal("10100101"))
