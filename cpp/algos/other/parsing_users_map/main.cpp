#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

bool is_number(char target) {
	return target >= 48 /*0*/ && target <= 57 /*9*/;
}

std::pair<int, int> collect_number_from_initial_char(
	char initial_char, int current_i, std::string target_string) {
	
	std::string number_raw{};

	int i_internal = current_i;
	char c_internal = initial_char;

	while (is_number(c_internal)) {
		number_raw.push_back(c_internal);
		i_internal++;

		c_internal = target_string[i_internal];
	}

	int number{};

	try {
		number = std::stoi(number_raw);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Out of range: " << e.what() << std::endl;
	}

	return std::make_pair(number, i_internal);
}

typedef std::vector<int> keys;
typedef std::vector<std::vector<int>> values;

typedef std::pair<keys, values> parsed_KVs;

std::map<int, std::vector<int>> parse_input(std::string raw_input) {
	keys parsed_keys{};
	values parsed_values{};

	std::vector<char> stack{};

	bool is_key_handled{};

	for (int i{}; i < raw_input.size();i++) {
		char c = raw_input[i];

		if ((stack.size() == 2 || stack.size() == 1) && is_number(c)) { // key
			is_key_handled = true;

			std::pair<int, int> pair = collect_number_from_initial_char(c, i, raw_input);

			int key = pair.first;
			int continuation_of_iteration = pair.second;

			parsed_keys.push_back(key);

			i = continuation_of_iteration;

			continue;
		}

		if (stack.size() == 3 || (stack.size() == 2 && is_key_handled) && is_number(c)) {  // begining of value
			std::vector<int> values_internal;
			
			char c_internal = c;
			int i_internal = i;

			while (c_internal != '}') {
				if (is_number(c_internal)) {
					std::pair<int, int> pair = collect_number_from_initial_char(
						c_internal, i_internal, raw_input);

					int whole_number = pair.first;

					values_internal.push_back(whole_number);

					int continuation_of_iteration = pair.second;

					i_internal = continuation_of_iteration;
					
					c_internal = raw_input[i_internal];
					continue;
				}

				i_internal++;
				c_internal = raw_input[i_internal];
			}

			parsed_values.push_back(values_internal);

			is_key_handled = false;

			c = raw_input[i_internal];
			i = i_internal;
		}
		
		if (c == '{') { stack.push_back('{'); }

		if (c == '}') { stack.pop_back(); }
	}

	std::map<int, std::vector<int>> out;

	for (int i{};  i < parsed_keys.size();i++) {
		int key_to_add = parsed_keys[i];
		std::vector<int> values_to_add = parsed_values[i];

		out[key_to_add] = values_to_add;
	}

	return out;
}


int main() {
	std::string user_input;
	std::getline(std::cin, user_input);

	std::map<int, std::vector<int> > parsed_input = parse_input(user_input);

	int current_index{};

	for (auto pair : parsed_input) {
		int key = pair.first;

		std::vector<int> vals = pair.second;
		
		std::sort(vals.begin(), vals.end(), [](int a, int b) {
			return a < b;
		});

		std::string values_substring{};

		for (int i{}; i < vals.size(); i++) {
			int current_val = vals[i];

			std::string current_val_converted = std::to_string(current_val);

			values_substring += current_val_converted;

			if (i != vals.size() - 1) {
				values_substring += ' ';
			}
		}

		std::cout << key << ": " << values_substring << '\n';

		current_index++;
	}
}